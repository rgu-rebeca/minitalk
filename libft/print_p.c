#include "ft_printf.h"

static void	ft_put_hexa(unsigned long num)
{
	char	c;

	if (num / 16 > 0)
		ft_put_hexa(num / 16);
	if (num % 16 >= 10)
		c = 'a' + (num % 16) - 10;
	else
		c = num % 16 + '0';
	write (1, &c, 1);
}

int	print_p(void *ptr)
{
	size_t	aux;
	int		count;

	if (!ptr || (void *)ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	count = 3;
	aux = (size_t) ptr;
	while (aux / 16 > 0)
	{
		count++;
		aux = aux / 16;
	}
	ft_put_hexa((size_t)ptr);
	return (count);
}
