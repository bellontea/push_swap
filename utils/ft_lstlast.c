#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
