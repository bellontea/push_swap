#include "push_swap.h"

void	find_place(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	(*b)->flag = -1;
	pa(a, b);
	ft_lstadd_back(comms, ft_lstnew(PA));
	ra(a, b);
	ft_lstadd_back(comms, ft_lstnew(RA));
	info->next++;
}

void	swap_if_next(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	while ((*a && (*a)->next && (*a)->next->order == info->next)
		|| (*b && (*b)->next && (*b)->next->order == info->next))
	{
		if (*a && (*a)->next && (*a)->next->order == info->next)
		{
			sa(a, b);
			ft_lstadd_back(comms, ft_lstnew(SA));
		}
		else if ((*b)->order == info->next + 1)
		{
			pa(a, b);
			ft_lstadd_back(comms, ft_lstnew(PA));
		}
		else if ((*b)->order < info->mid)
		{
			sb(a, b);
			ft_lstadd_back(comms, ft_lstnew(SB));
		}
		else if ((*b)->order >= info->mid)
			break ;
	}
}

void	check_bottom_value(t_stack **b, t_info *info, t_stack **comms)
{
	t_stack	*last;

	last = ft_lstlast(*b);
	if (last && last->order == info->next)
	{
		rrb(NULL, b);
		ft_lstadd_back(comms, ft_lstnew(RRB));
	}
}

void	check_top_value(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	swap_if_next(a, b, info, comms);
	check_bottom_value(b, info, comms);
	while ((*a && (*a)->order == info->next)
		|| (*b && (*b)->order == info->next))
	{
		if (*b && (*b)->order == info->next)
			find_place(a, b, info, comms);
		else
		{
			(*a)->flag = -1;
			ra(a, b);
			ft_lstadd_back(comms, ft_lstnew(RA));
			info->next++;
		}
		swap_if_next(a, b, info, comms);
		check_bottom_value(b, info, comms);
	}
}
