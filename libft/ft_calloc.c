#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*ptr2;

	i = 0;
	if (size != 0 && num > SIZE_MAX / size)
		ptr = NULL;
	ptr = malloc(num * size);
	ptr2 = (unsigned char *) ptr;
	if (ptr == NULL)
		return (NULL);
	while (i < size * num)
	{
		ptr2[i] = 0;
		i++;
	}
	return (ptr);
}
