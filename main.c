#include "push_swap.h"
#include "stdio.h"

void	output(t_stack *a, t_stack *b)
{
	printf("\nStack a:\n");
	if (!a)
		return ;
	while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\nStack b:\n");
	if (!b)
		return ;
	while (b)
	{
		printf("%d ", b->content);
		b = b->next;
	}
	printf("\n");
}

void	array_output(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d(%d) ", stack->content, stack->order);
		stack = stack->next;
		i++;
	}
	printf("\n");
}

void	check(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	pb(a, b);
	output(*a, *b);

	sa(a);
	output(*a, *b);
	sb(b);
	output(*a, *b);
	ss(a, b);
	output(*a, *b);

	ra(a);
	output(*a, *b);
	rb(b);
	output(*a, *b);
	rr(a, b);
	output(*a, *b);

	rra(a);
	output(*a, *b);
	rrb(b);
	output(*a, *b);
	rrr(a, b);
	output(*a, *b);
}

void	ft_error(t_stack **a)
{
	ft_lstclear(a);
	write(1, "ERROR\n", 7);
}

int		ft_check_nums(char *argv, t_stack *a, int *num)
{
	while (argv[*num])
	{
		if (!ft_isdigit(argv[*num]))
			return (0);
		(*num)++;
	}
	*num = ft_atoi(argv);
	if ((*num == 0 && argv[1] != '\0') || (*num == -1 && argv[2] != '\0'))
		return (0);
	while (a)
	{
		if (*num == a->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *a;
	int		num;
	int		*array;
	int		size;

	a = NULL;
	argc--;
	(void)array;
	if (argc < 2)
	{
		ft_error(&a);
		return (-1);
	}
	size = argc;
	while (argc)
	{
		num = 0;
		if (!ft_check_nums(argv[argc], a, &num))
		{
			ft_error(&a);
			return (0);
		}
		ft_lstadd_front(&a, ft_lstnew(num));
		argc--;
	}
	array = sort(a, size);
	array_output(a, size);
	stack_sort(&a, size);
	ft_lstclear(&a);
//	check(&a, &stack_b);
}