#include "push_swap.h"

int	find_command(char *str)
{
	const char	commands[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
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

int	read_commands(t_stack **comms)
{
	char	buf[4];
	int		res;
	int		command;

	ft_memset(buf, 0, 4);
	res = read(0, buf, 3);
	while (res > 0)
	{
		if (buf[2] == '\n')
			buf[2] = 0;
		else
			res = read(0, &res, 1);
		command = find_command((char *)buf);
		if (command == -1)
			return (0);
		else
			ft_lstadd_back(comms, ft_lstnew(command));
		ft_memset(buf, 0, 4);
		res = read(0, buf, 3);
	}
//	if (res == -1)
//		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *a;
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
}
