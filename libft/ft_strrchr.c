#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_ocurrence;

	last_ocurrence = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_ocurrence = (char *) str;
		str++;
	}
	if ((char) c == '\0')
		last_ocurrence = (char *) str;
	return (last_ocurrence);
}

/*int main(void)
{
	const char  *test = "hello, world.";
	int c = 'o';
	char    *last_occur= ft_strrchr(test, c);
	if (last_occur)
		printf("The last occurence of the letter: %c is %s \n",c, last_occur);
	else
		printf("not found");
}*/