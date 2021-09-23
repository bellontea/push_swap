#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	ft_lstadd_front(stack, temp->next);
	temp->next = NULL;
}

int	rra(t_stack **a, t_stack **b)
{
	(void)b;
	reverse_rotate(a);
	return (RRA);
}

int	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	reverse_rotate(b);
	return (RRB);
}

int	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (RRR);
}
