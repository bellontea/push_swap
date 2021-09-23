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

void	create_array(void (**arr)(t_stack **, t_stack **))
{
	arr[SA] = sa;
	arr[SB] = sb;
	arr[SS] = ss;
	arr[PA] = pa;
	arr[PB] = pb;
	arr[RA] = ra;
	arr[RB] = rb;
	arr[RR] = rr;
	arr[RRA] = rra;
	arr[RRB] = rrb;
	arr[RRR] = rrr;
}

int	checker(t_stack **a, t_stack **comms)
{
	void	(*comm_funcs[11])(t_stack **, t_stack **);
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

	a = NULL;
	comms = NULL;
	argc--;
	if (!argc)
		return (0);
	if (argc < 2)
	{
		ft_error(&a, &comms);
		return (0);
	}
	if (!fill_stack(argc, argv, &a))
		return (0);
	if (!read_commands(&comms))
	{
		ft_error(&a, &comms);
		return (0);
	}
	if (checker(&a, &comms))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_all(&a, NULL, &comms);
}
