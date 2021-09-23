#include "push_swap.h"

void	push(t_stack **out, t_stack **in)
{
	t_stack	*elem;

	if (!*out)
		return ;
	elem = *out;
	*out = (*out)->next;
	ft_lstadd_front(in, elem);
}

int	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	return (PA);
}

int	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	return (PB);
}
