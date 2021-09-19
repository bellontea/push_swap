#include "push_swap.h"
#include "stdio.h"

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

void	output(t_stack	*comms)
{
	const char	commands[12][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (comms)
	{
		printf("%s\n", commands[comms->content]);
		comms = comms->next;
	}
}

int main(int argc, char **argv)
{
	t_stack *a;
	int		num;
	int		size;

	a = NULL;
	argc--;
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
	sort(a, size);
	if (size <= 6)
		mini_stack_sort(&a, size);
	else
		stack_sort(&a, size);
	ft_lstclear(&a);
}