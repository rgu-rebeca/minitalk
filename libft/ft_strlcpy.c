#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0 && src[i] != '\0')
	{
		while ((i < dstsize - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/*int	main(void)
{
	const char	src[20] = "lorem ipsum";
	char	dest[3] = "qwe";
	int	dstsize = 3;
	int	srcsize = ft_strlcpy(dest, src, dstsize);
	printf("the dest size is: %d", dstsize);
	printf("the src size is: %d", srcsize);
	printf("the new dest is: %s", dest);
}*/