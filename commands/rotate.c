#include "push_swap.h"

void	rotate(t_stack **stack)
{
    t_stack *first;

    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;
    ft_lstadd_back(stack, first);
}

void	reverse_rotate(t_stack **stack)
{
    t_stack *temp;

    if (!*stack || !(*stack)->next)
        return ;
    temp = *stack;
    while (temp->next->next)
        temp = temp->next;
    ft_lstadd_front(stack, temp->next);
    temp->next = NULL;
}

void    ra(t_stack **a)
{
    rotate(a);
}

void    rb(t_stack **b)
{
    rotate(b);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);    
}

void    rra(t_stack **a)
{
    reverse_rotate(a);
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);    
}