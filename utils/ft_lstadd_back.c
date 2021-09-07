#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
