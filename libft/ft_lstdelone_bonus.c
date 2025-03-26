#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst -> content);
	free (lst);
}

/*void	del(void*	content)
{
	free(content);
}
int	main(void)
{
	int	*content = (int*)malloc(sizeof(int));

	*content = 42;
	t_list	*node = ft_lstnew(content);
	printf("the node before deletion is:%d", *(int*)node ->content);
	ft_lstdelone(node, del);
	printf("deletion done");
	return 0;
}*/