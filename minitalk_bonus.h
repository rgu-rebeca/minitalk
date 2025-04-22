/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:22:29 by rgu               #+#    #+#             */
/*   Updated: 2025/04/22 20:47:14 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define _POSIX_C_SOURCE 200809L
# define _GNU_SOURCE

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	sig_handler(int sig, siginfo_t *info, void *context);
void	send_signal(int pid, char c);
void	send_message(int pid, unsigned char *message);
#endif