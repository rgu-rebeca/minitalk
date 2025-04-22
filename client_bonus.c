/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:22:10 by rgu               #+#    #+#             */
/*   Updated: 2025/04/22 20:22:13 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft/libft.h"

volatile sig_atomic_t	g_confirm = 0;

void	signal_confirm(int sig)
{
	(void)sig;
	g_confirm = 1;
}

void	send_signal(int pid, char c)
{
	int	bit;
	int	result;

	bit = 7;
	while (bit >= 0)
	{
		g_confirm = 0;
		if ((c >> bit) & 1)
			result = kill(pid, SIGUSR2);
		else
			result = kill(pid, SIGUSR1);
		if (result == -1)
		{
			ft_putstr_fd("error of kill() of client or invalid pid", 2);
			exit (1);
		}
		while (g_confirm != 1)
			pause();
		bit--;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
	}
	send_signal(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	signal(SIGUSR1, signal_confirm);
	send_message(pid, argv[2]);
	while (g_confirm != 1)
		pause();
	return (0);
}
