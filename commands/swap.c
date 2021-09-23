#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*next_elem;

	if (!*stack || !(*stack)->next)
		return ;
	next_elem = (*stack)->next;
	(*stack)->next = next_elem->next;
	next_elem->next = *stack;
	(*stack) = next_elem;
}

int	sa(t_stack **a, t_stack **b)
{
	(void)b;
	swap(a);
	return (SA);
}

int	sb(t_stack **a, t_stack **b)
{
	(void)a;
	swap(b);
	return (SB);
}

int	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	return (SS);
}
