#include "push_swap.h"

int	find_next(t_stack *stack)
{
	int	next;

	next = 6;
	while (stack)
	{
		if (stack->order < next)
			next = stack->order;
		stack = stack->next;
	}
	return (next);
}

void	sort_three_elem_a(t_stack **a, t_stack **comms)
{
	int	next;

	next = find_next(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)->next->order == next && is_sorted((*a)->next))
	{
		sa(a);
		ft_lstadd_back(comms, ft_lstnew(SA));
	}
	else if ((*a)->order == next)
	{
		rra(a);
		ft_lstadd_back(comms, ft_lstnew(RRA));
		rra(a);
		ft_lstadd_back(comms, ft_lstnew(RRA));
	}
	else if ((*a)->order != next && is_sorted((*a)->next))
	{
		ra(a);
		ft_lstadd_back(comms, ft_lstnew(RA));	
	}
	else if ((*a)->order != next)
	{
		ra(a);
		ft_lstadd_back(comms, ft_lstnew(RA));
		ra(a);
		ft_lstadd_back(comms, ft_lstnew(RA));
	}
}

void	sort_three_elem_b(t_stack **b, t_stack **comms)
{
	int	next;

	next = find_next(*b);
	if (is_sorted(*b))
		return ;
	if ((*b)->order != next && is_sorted((*b)->next))
	{
		rb(b);
		ft_lstadd_back(comms, ft_lstnew(RB));	
	}
	else if ((*b)->next->order == next && is_sorted((*b)->next))
	{
		sb(b);
		ft_lstadd_back(comms, ft_lstnew(SB));
	}
	else if ((*b)->order == next)
	{
		rrb(b);
		ft_lstadd_back(comms, ft_lstnew(RRB));
		rrb(b);
		ft_lstadd_back(comms, ft_lstnew(RRB));
	}
	else if ((*b)->order != next)
	{
		rb(b);
		ft_lstadd_back(comms, ft_lstnew(RB));
		rb(b);
		ft_lstadd_back(comms, ft_lstnew(RB));
	}
}

void	stack_merge(t_stack **a, t_stack **b, t_stack **comms)
{
	int	next;

	next = 1;
	while (*b)
	{
		if ((*a)->order == next)
		{
			ra(a);
			ft_lstadd_back(comms, ft_lstnew(RA));
		}
		else if ((*b)->order == next)
		{
			pa(a, b);
			ft_lstadd_back(comms, ft_lstnew(PA));
			ra(a);
			ft_lstadd_back(comms, ft_lstnew(RA));
		}
		next++;
	}
}

void	mini_stack_sort(t_stack **a, int size)
{
	t_stack		*comms;
	t_stack		*b;

	comms = NULL;
	b = NULL;
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		sa(a);
		ft_lstadd_back(&comms, ft_lstnew(SA));
	}
	if (size > 2)
	{
		while (ft_lstsize(*a) != 3)
		{
			pb(a, &b);
			ft_lstadd_back(&comms, ft_lstnew(PB));
		}
		sort_three_elem_a(a, &comms);
		if (ft_lstsize(b) > 1)
			sort_three_elem_b(&b, &comms);		
		stack_merge(a, &b, &comms);
	}
	replace(&comms);
	output(comms);
}