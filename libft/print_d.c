#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
	{
		ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	print_d(int num)
{
	int	count;
	int	aux;

	count = 1;
	aux = num;
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (aux < 0)
	{
		aux = -aux;
		count++;
	}
	while (aux / 10 > 0)
	{
		count++;
		aux = aux / 10;
	}
	ft_putnbr(num);
	return (count);
}
