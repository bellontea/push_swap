#include "push_swap.h"

void	push(t_stack **out, t_stack **in)
{
    t_stack *elem;

    if (!*out)
        return ;
    elem = *out;
    *out = (*out)->next;
    ft_lstadd_front(in, elem);
}

void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
}