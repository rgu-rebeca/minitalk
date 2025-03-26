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