#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}

/*int	main(void)
{
	int	c = 'A';
	int	new = tolower(c);
	printf ("%c", new);
}*/