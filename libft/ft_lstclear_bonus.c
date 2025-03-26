#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)-> next;
		(del)((*lst)-> content);
		free (*lst);
		*lst = aux;
	}
}

/*void	del(void*	content)
{
	free(content);
}

void print_list(t_list *head)
{
    while (head)
    {
        printf("%d -> ", *(int*)head-> content);
        head = head->next;
    }
    printf("NULL\n");
}

int	main(void)
{
	int	*content1 = (int*)malloc(sizeof(int));
	int	*content2 = (int*)malloc(sizeof(int));

	*content1 = 42;
	*content2 = 25;
	t_list	*node1 = ft_lstnew(content1);
	ft_lstadd_back(&node1, ft_lstnew(content2));
	print_list(node1);
	ft_lstclear(&node1, del);
	printf("deletion done");
	return 0;
}*/