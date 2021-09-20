#include "push_swap.h"

void	ft_error(t_stack **a)
{
	ft_lstclear(a);
	write(1, "ERROR\n", 7);
}
