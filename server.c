/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:22:45 by rgu               #+#    #+#             */
/*   Updated: 2025/04/22 20:22:46 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

char	*add_char(char *str, char c)
{
	int		len;
	char	*new_str;
	int		i;

	i = 0;
	len = 0;
	while (str && str[len])
		len++;
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

void	sig_handler_aux(int *bit, char *character)
{
	static char	*msg;

	if (*bit == 8)
	{
		if (*character == '\0')
		{
			write (1, msg, ft_strlen(msg));
			write (1, "\n", 1);
			free(msg);
			msg = NULL;
		}
		else
		{
			msg = add_char(msg, *character);
			if (!msg)
				exit(1);
		}
		*bit = 0;
		*character = 0;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	character;
	int			result;

	(void)context;
	if (sig == SIGUSR1)
		character = character << 1;
	else if (sig == SIGUSR2)
		character = character << 1 | 1;
	bit++;
	sig_handler_aux(&bit, &character);
	result = kill(info->si_pid, SIGUSR1);
	if (result == -1)
	{
		ft_putstr_fd("error of kill() of the server or invalid pid\n", 2);
		exit (1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("The server ID is: %d\n", pid);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
