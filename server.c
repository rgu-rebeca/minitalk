#include "minitalk.h"
#include "libft/libft.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	character;

	(void)context;
	if (sig == SIGUSR1)
		character = character << 1;
	else if (sig == SIGUSR2)
		character = character << 1 | 1;
	bit++;
	if (bit == 8)
	{
		write (1, &character, 1);
		if (character == 0)
			write (1, "\n", 1);
		bit = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
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
