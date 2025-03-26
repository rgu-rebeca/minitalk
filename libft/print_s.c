#include "ft_printf.h"

int	print_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		write (1, str, 1);
		str++;
		count++;
	}
	return (count);
}
