#include "push_swap.h"

int	find_command(char *str)
{
	const char	commands[11][4] = {"sa", "sb", "ss", "pa",
	"pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(str, commands[i], 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	read_extra(void)
{
	int	ch;

	while (read(0, &ch, 1))
		;
}

int	read_commands(t_stack **comms)
{
	char	buf[4];
	int		res;
	int		command;
	int		i;

	res = 1;
	while (res > 0)
	{
		ft_memset(buf, 0, 4);
		i = 0;
		res = read(0, &(buf[i]), 1);
		while (res && buf[i] != '\n' && i < 4)
			res = read(0, &(buf[++i]), 1);
		if (!res && !buf[0])
			break ;
		if (i >= 4)
			read_extra();
		buf[i] = 0;
		command = find_command((char *)buf);
		if (command == -1)
			return (0);
		else
			ft_lstadd_back(comms, ft_lstnew(command));
	}
	return (1);
}

int	checker(t_stack **a, t_stack **comms)
{
	int		(*comm_funcs[11])(t_stack **, t_stack **);
	t_stack	*b;

	create_array(comm_funcs);
	b = NULL;
	while (*comms)
	{
		comm_funcs[(*comms)->content](a, &b);
		*comms = (*comms)->next;
	}
	if (!b && is_sorted(*a))
		return (1);
	else
	{
		ft_lstclear(&b);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*comms;
	int		ret;
	char	**array;

	a = NULL;
	comms = NULL;
	if (argc < 2)
		return (0);
	if (!fill_stack(argc - 1, argv + 1, &a))
	{
		array = ft_split(argv[1], ' ');
		argc = array_size(array);
		ret = fill_stack(argc, array, &a);
		free_array(array);
		if (!ret)
			return (ft_error(&a, &comms));
	}
	if (!read_commands(&comms))
		return (ft_error(&a, &comms));
	if (checker(&a, &comms))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_all(&a, NULL, &comms);
}
