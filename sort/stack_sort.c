#include "push_swap.h"
#include "stdio.h"

void	fill_info(t_info *info, int max)
{
	info->max = max;
	info->mid = (info->max - info->next) / 2 + info->next;	
}

void	find_place(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	(*b)->flag = -1;
	pa(a, b);
	ft_lstadd_back(comms, ft_lstnew(PA));
	ra(a);
	ft_lstadd_back(comms, ft_lstnew(RA));
	info->next++;	
}

void	swap_if_next(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	while ((*a && (*a)->next && (*a)->next->order == info->next) || (*b && (*b)->next && (*b)->next->order == info->next))
	{
		if (*a && (*a)->next && (*a)->next->order == info->next)
		{
			sa(a);
			ft_lstadd_back(comms, ft_lstnew(SA));
		}
		else if ((*b)->order == info->next + 1)
		{
			pa(a, b);
			ft_lstadd_back(comms, ft_lstnew(PA));
		}
		else if ((*b)->order < info->mid)
		{
			sb(b);
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
		rrb(b);
		ft_lstadd_back(comms, ft_lstnew(RRB));
	}
}

void	check_top_value(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	swap_if_next(a, b, info, comms);
	check_bottom_value(b, info, comms);
	while ((*a && (*a)->order == info->next) || (*b && (*b)->order == info->next))
	{
		if (*b && (*b)->order == info->next)
			find_place(a, b, info, comms);
		else
		{
			(*a)->flag = -1;
			ra(a);
			ft_lstadd_back(comms, ft_lstnew(RA));
			info->next++;	
		}
		swap_if_next(a, b, info, comms);
		check_bottom_value(b, info, comms);
	}
}

void    move_to_b(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	int i;
	int size;

	i = 0;
	size = info->mid - info->next + 1;
	while (i < size)
	{
		if ((*a)->order <= info->mid)
		{
			pb(a, b);
			ft_lstadd_back(comms, ft_lstnew(PB));
			i++;
		}
		else
		{
			ra(a);
			ft_lstadd_back(comms, ft_lstnew(RA));
		}
	}
}

int check_values(t_stack *s, int mid)
{
	while (s)
	{
		if (s->order >= mid)
			return (1);
		s = s->next;
	}
	return (0);
}

void	move_to_a(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	while (*b && check_values(*b, info->mid))
	{
		check_top_value(a, b, info, comms);
		if (!*b)
			return ;
		if ((*b)->order < info->mid)
		{
			rb(b);
			ft_lstadd_back(comms, ft_lstnew(RB));
		}
		else
		{
			(*b)->flag = info->flag;
			pa(a, b);
			ft_lstadd_back(comms, ft_lstnew(PA));
		}
	}
	check_top_value(a, b, info, comms);
}

void    stack_sort(t_stack **a, int size)
{
	t_stack		*b;
	t_info		*info;
	t_stack		*comms;
	int			curr_flag;

	b = NULL;
	comms = NULL;
	info = ft_infonew(size);
	while (b || !is_sorted(*a))
	{
		move_to_b(a, &b, info, &comms);
		while (info->flag && ft_lstlast(*a)->flag != -1)
		{
			rra(a);
			ft_lstadd_back(&comms, ft_lstnew(RRA));
		}
		while (b != NULL)
		{
			fill_info(info, info->mid);
			info->flag++;
			move_to_a(a, &b, info, &comms);
		}
		curr_flag = (*a)->flag;
		while (curr_flag > 0)
		{
			while ((*a)->flag == curr_flag)
			{
				if ((*a)->order > info->max)
					info->max = (*a)->order;
				pb(a, &b);
				ft_lstadd_back(&comms,ft_lstnew(PB));
				check_top_value(a, &b, info, &comms);
			}
			fill_info(info, info->max);
			while (b != NULL)
			{
				info->flag++;
				move_to_a(a, &b, info, &comms);
				fill_info(info, info->mid);
			}
			curr_flag = (*a)->flag;
		}
		fill_info(info, size);
	}
	replace(&comms);
	output(comms);
	printf("\n|%d|\n", ft_lstsize(comms));
	free(info);
	ft_lstclear(a);
	ft_lstclear(&b);
	ft_lstclear(&comms);
}
