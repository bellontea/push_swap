#include "push_swap.h"

void	output(t_stack	*comms)
{
	const char	commands[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra",
	"rb", "rr", "rra", "rrb", "rrr"};

	while (comms)
	{
		ft_putstr_fd((char *)commands[comms->content], 1);
		ft_putstr_fd("\n", 1);
		comms = comms->next;
	}
}

int	clear_if_sorted(t_stack **a)
{
	if (a && is_sorted(*a))
	{
		ft_lstclear(a);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_stack	*a;
	char	**array;

	a = NULL;
	array = NULL;
	if (argc < 2)
		return (0);
	if (!fill_stack(argc - 1, argv + 1, &a))
	{
		array = ft_split(argv[1], ' ');
		argc = array_size(array) + 1;
		ret = fill_stack(argc - 1, array, &a);
		free_array(array);
		if (!ret)
			return (ft_error(&a, NULL));
	}
	if (clear_if_sorted(&a))
		return (0);
	argc--;
	sort(a, argc);
	if (argc <= 6)
		mini_stack_sort(&a, argc);
	else
		stack_sort(&a, argc);
}
