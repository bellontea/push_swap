#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_lstclear(&((*lst)->next));
	ft_lstdelone(*lst);
	*lst = NULL;
}
