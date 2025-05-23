/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:37 by rgu               #+#    #+#             */
/*   Updated: 2025/04/07 16:43:37 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

/*int	main(void)
{
	int	c = 'a';
	int	new = toupper(c);
	printf ("%c", new);
}*/