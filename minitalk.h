#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# define _DEFAULT_SOURCE

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	sig_handler(int sig, siginfo_t *info, void *context);
void	send_signal(int pid, char c);
void	send_message(int pid, char *message);
#endif