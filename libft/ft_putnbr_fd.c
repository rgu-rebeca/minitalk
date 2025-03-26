#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		num;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	num = n % 10;
	if (n / 10 > 0)
	{
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	c = num + '0';
	write (fd, &c, 1);
}

/*int main(void)
{
	int n = 0;
	int fd = 1;
	ft_putnbr_fd(n, fd);
	return 0;
}*/