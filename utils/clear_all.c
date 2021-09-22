#include "push_swap.h"

void	clear_all(t_stack **a, t_stack **b, t_stack **comms)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_lstclear(comms);
}
