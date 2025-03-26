#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;

	a = (const unsigned char *)s;
	while (n > 0)
	{
		if ((unsigned char) c == *a)
			return ((void *)a);
		a++;
		n--;
	}
	return (NULL);
}

/*int main(void)
{
	const void *a = "wewqe";
	int c = 'w';
	size_t  n = 3;
	void    *result = ft_memchr(a, c, n);
	printf ("the first ocurrence of the letter %c is %s", c, (char*) result);
	return 0;
}*/