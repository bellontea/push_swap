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

void	ft_error(t_stack **stack_a)
{
	ft_lstclear(stack_a);
	write(1, "ERROR\n", 7);
}

int		ft_check_nums(char *argv, t_stack *stack_a, int *num)
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
	while (stack_a)
	{
		if (*num == stack_a->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int		num;
	int		*array;
	int		size;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	argc--;
	if (argc < 2)
	{
		ft_error(&stack_a);
		return (-1);
	}
	size = argc;
	while (argc)
	{
		num = 0;
		if (!ft_check_nums(argv[argc], stack_a, &num))
		{
			ft_error(&stack_a);
			return (0);
		}
		ft_lstadd_front(&stack_a, ft_lstnew(num));
		argc--;
	}
	array = sort(stack_a, size);
	output(stack_a, stack_b);
	i = 0;
	while (i < size)
	{
		printf("%d", array[i]);
		i++;
	}
//	check(&stack_a, &stack_b);
}