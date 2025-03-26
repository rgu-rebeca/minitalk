#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

/*int main(void)
{
	char    *s = "asd";
	int     fd = 1;
	ft_putstr_fd(s, fd);
	return 0;
}*/