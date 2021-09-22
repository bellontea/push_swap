#include "push_swap.h"

void	fill_info(t_info *info, int max)
{
	info->max = max;
	info->mid = (info->max - info->next) / 2 + info->next;
}

void	move_to_b(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	int	i;
	int	size;

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
			ra(a, b);
			ft_lstadd_back(comms, ft_lstnew(RA));
		}
	}
}

int	check_values(t_stack *s, int mid)
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
			rb(a, b);
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

void	stack_sort(t_stack **a, int size)
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
			rra(a, &b);
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
				ft_lstadd_back(&comms, ft_lstnew(PB));
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
	free(info);
	clear_all(a, &b, &comms);
}
