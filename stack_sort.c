#include "push_swap.h"
#include "stdio.h"

void	stack_output(t_stack *a, t_stack *b, t_stack *comms)
{
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
		printf("%d ", comms->content);
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
	(*b)->flag++;
	pa(a, b);
	ft_lstadd_back(comms, ft_lstnew(PA));
	ra(a);
	ft_lstadd_back(comms, ft_lstnew(RA));
	info->next++;	
}

void    move_to_b(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	int i;
	int size;

	i = 0;
	size = info->mid - info->next + 1;
	while (i < size)
	{
		if ((*a)->content <= info->mid)
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
	info->flag = 1;
}

void	move_to_a(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	int i;
	int size;

	i = 0;
	size = info->max - info->mid + 1;
	while (*b && i < size)
	{
		stack_output(*a, *b, *comms);
		if ((*b)->content <= info->mid)
		{
			if ((*b)->content == info->next)
			{
				find_place(a, b, info, comms);
				continue;
			}
			rb(b);
			ft_lstadd_back(comms, ft_lstnew(RA));
		}
		else
		{
			(*b)->flag++;
			pa(a, b);
			ft_lstadd_back(comms, ft_lstnew(PA));
			i++;
		}
	}
	info->flag = 1;
}

void    stack_sort(t_stack **a, int size)
{
	t_stack		*b;
	t_info		*info;
	t_stack		*comms;

	if (is_sorted(*a))
		return ;
	b = NULL;
	info = malloc(sizeof(t_info));
	comms = NULL;
	info->max = size;
	info->next = 1;
	info->mid = info->max / 2 + info->next;
	stack_output(*a, b, comms);
	move_to_b(a, &b, info, &comms);
	while (b != NULL)
	{
		info->max = info->mid;
		info->mid = (info->max - info->next) / 2 + info->next;
		move_to_a(a, &b, info, &comms);
	}
	// free(info);
	// stack_output(*a, b, comms);
	// ft_lstclear(&b);
	// ft_lstclear(&comms);
}
