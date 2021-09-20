#include "push_swap.h"

int	read_commands(t_stack *comms)
{
	const char	commands[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	char	buf[4];
	int		res;

	ft_memset(buf, 0, 4);
	res = read(0, buf, 3);
	while (res > 0)
	{

		if (buf[2] == "\n")
			buf[2] = 0;
		else
			res = read(0, &res, 1);
		ft_memset(buf, 0, 4);
	}
}

int main(int argc, char **argv)
{
	t_stack *a;

	a = NULL;
	argc--;
	if (argc < 2)
		return (-1);
	if (!fill_stack(argc, argv, &a))
		return (-1);
	return (0);
}
