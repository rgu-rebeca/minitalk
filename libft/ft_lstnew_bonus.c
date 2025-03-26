#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

/*int	main(void)
{
	int	content = 42;
	t_list *result = ft_lstnew(&content);
	printf("%d", *(int*)result -> content);
}*/