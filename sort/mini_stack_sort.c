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
		ft_lstadd_back(comms, ft_lstnew(sa(a, NULL)));
	else if ((*a)->order == next)
	{
		ft_lstadd_back(comms, ft_lstnew(rra(a, NULL)));
		ft_lstadd_back(comms, ft_lstnew(rra(a, NULL)));
	}
	else if ((*a)->order != next && is_sorted((*a)->next))
		ft_lstadd_back(comms, ft_lstnew(ra(a, NULL)));
	else if ((*a)->order != next)
	{
		ft_lstadd_back(comms, ft_lstnew(ra(a, NULL)));
		ft_lstadd_back(comms, ft_lstnew(ra(a, NULL)));
	}
}

void	sort_three_elem_b(t_stack **b, t_stack **comms)
{
	int	next;

	next = find_next(*b);
	if (is_sorted(*b))
		return ;
	if ((*b)->order != next && is_sorted((*b)->next))
		ft_lstadd_back(comms, ft_lstnew(rb(NULL, b)));
	else if ((*b)->next->order == next && is_sorted((*b)->next))
		ft_lstadd_back(comms, ft_lstnew(sb(NULL, b)));
	else if ((*b)->order == next)
	{
		ft_lstadd_back(comms, ft_lstnew(rrb(NULL, b)));
		ft_lstadd_back(comms, ft_lstnew(rrb(NULL, b)));
	}
	else if ((*b)->order != next)
	{
		ft_lstadd_back(comms, ft_lstnew(rb(NULL, b)));
		ft_lstadd_back(comms, ft_lstnew(rb(NULL, b)));
	}
}

void	stack_merge(t_stack **a, t_stack **b, t_stack **comms)
{
	int	next;

	next = 1;
	while (*b)
	{
		if ((*a)->order == next)
			ft_lstadd_back(comms, ft_lstnew(ra(a, b)));
		else if ((*b)->order == next)
		{
			ft_lstadd_back(comms, ft_lstnew(pa(a, b)));
			ft_lstadd_back(comms, ft_lstnew(ra(a, b)));
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
		ft_lstadd_back(&comms, ft_lstnew(sa(a, &b)));
	if (size > 2)
	{
		while (ft_lstsize(*a) != 3)
			ft_lstadd_back(&comms, ft_lstnew(pb(a, &b)));
		sort_three_elem_a(a, &comms);
		if (ft_lstsize(b) > 1)
			sort_three_elem_b(&b, &comms);
		stack_merge(a, &b, &comms);
	}
	replace(&comms);
	output(comms);
	clear_all(a, &b, &comms);
}
