#include "push_swap.h"
#include "stdio.h"

void	replace(t_stack	**comms)
{
	t_stack	*save;

	save = *comms;
	while (*comms && (*comms)->next)
	{
		if (((*comms)->content == SA && (*comms)->next->content == SB) || 
		((*comms)->content == SB && (*comms)->next->content == SA))
		{
			(*comms)->content = SS;
			ft_lstdel_next(comms);
		}
		if (((*comms)->content == RA && (*comms)->next->content == RB) || 
		((*comms)->content == RB && (*comms)->next->content == RA))
		{
			(*comms)->content = RR;
			ft_lstdel_next(comms);
		}
		if (((*comms)->content == RRA && (*comms)->next->content == RRB) || 
		((*comms)->content == RRB && (*comms)->next->content == RRA))
		{
			(*comms)->content = RRR;
			ft_lstdel_next(comms);
		}	
		if ((*comms)->next->next && (((*comms)->next->content == PA && 
		(*comms)->next->next->content == PB) || ((*comms)->next->content == PB && 
		(*comms)->next->next->content == PA)))
		{
			ft_lstdel_next(comms);
			ft_lstdel_next(comms);
			*comms = save;
			continue ;
		}	
		*comms = (*comms)->next;	
	}
	*comms = save;
}

void	fill_info(t_info *info, int max)
{
	info->max = max;
	info->mid = (info->max - info->next) / 2 + info->next;	
}

void	stack_output(t_stack *a, t_stack *b, t_stack *comms, t_info *info)
{
	const char	commands[12][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	printf("INFO:\nmax: %d\nmid: %d\nnext: %d\n", info->max, info->mid, info->next);
	printf("\n");
	printf("Stack a:\n");
	while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");
	printf("Stack b:\n");
	while (b)
	{
		printf("%d ", b->content);
		b = b->next;
	}
	printf("\n");
	printf("Commands:\n");
	while (comms)
	{
		printf("%s ", commands[comms->content]);
		comms = comms->next;
	}
		printf("\n\n");
}

int     is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
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
	while ((*a && (*a)->next && (*a)->next->order == info->next && (*a)->next->flag) || (*b && (*b)->next && (*b)->next->order == info->next))
	{
		if (*a && (*a)->next && (*a)->next->order == info->next && (*a)->next->flag != -1)
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
	info = malloc(sizeof(t_info));
	info->max = size;
	info->next = 1;
	info->mid = info->max / 2 + info->next;
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
//	printf("\n|%d|\n", ft_lstsize(comms));
	free(info);
	ft_lstclear(a);
	ft_lstclear(&b);
	ft_lstclear(&comms);
}
