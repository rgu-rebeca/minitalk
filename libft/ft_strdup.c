#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ptr;
	size_t		len;
	size_t		i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr [i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
