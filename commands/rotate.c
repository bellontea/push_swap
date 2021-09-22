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

void	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
}

void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
