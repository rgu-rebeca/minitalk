#include "ft_printf.h"

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}
