#include "push_swap.h"

void	ft_lstdelone(t_stack *lst)
{
	free(lst);
	lst = NULL;
}
