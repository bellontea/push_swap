#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack *));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
