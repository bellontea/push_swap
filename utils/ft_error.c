#include "push_swap.h"

int	ft_error(t_stack **a, t_stack **comms)
{
	ft_lstclear(a);
	ft_lstclear(comms);
	ft_putstr_fd("Error\n", 1);
	return (1);
}
