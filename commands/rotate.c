#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

int	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	return (RA);
}

int	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	return (RB);
}

int	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	return (RR);
}
