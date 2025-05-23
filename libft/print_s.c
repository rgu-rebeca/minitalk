/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:22:08 by rgu               #+#    #+#             */
/*   Updated: 2025/04/09 15:22:08 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_s(char *str)
{
	if (!str)
		str = "(null)";
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}
