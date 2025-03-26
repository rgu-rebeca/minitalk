#include "minitalk.h"
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

	bit = 7;
	while (bit >= 0)
	{
		g_confirm = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
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
	g_confirm = 0;
}
