#include "push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(int *))
{
	t_stack	*new_lst;
	t_stack	*new_elem;

	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
