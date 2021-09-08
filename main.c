#include "push_swap.h"

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
	int		num;

	stack_a = NULL;
	argc--;
	if (argc < 2)
	{
		ft_error(&stack_a);
		return (-1);
	}
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
}