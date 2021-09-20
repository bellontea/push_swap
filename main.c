#include "push_swap.h"

void	output(t_stack	*comms)
{
	const char	commands[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (comms)
	{
		ft_putstr_fd((char *)commands[comms->content], 1);
		ft_putstr_fd("\n", 1);
		comms = comms->next;
	}
}

int main(int argc, char **argv)
{
	t_stack *a;

	a = NULL;
	argc--;
	if (argc < 2)
	{
		ft_error(&a);
		return (-1);
	}
	if (!fill_stack(argc, argv, &a))
		return (-1);
	sort(a, argc);
	if (argc <= 6)
		mini_stack_sort(&a, argc);
	else
		stack_sort(&a, argc);
//	ft_lstclear(&a);
}