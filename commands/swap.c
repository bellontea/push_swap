#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *next_elem;

    if (!*stack || !(*stack)->next)
        return ;
    next_elem = (*stack)->next;
    (*stack)->next = next_elem->next;
    next_elem->next = *stack;
    (*stack) = next_elem;
}

void    sa(t_stack **stack_a)
{
    swap(stack_a);
}

void    sb(t_stack **stack_b)
{
    swap(stack_b);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}