#include "push_swap.h"

int	ft_check_nums(char *argv, t_stack *a, int *num)
{
	if (argv[0] == '-' || argv[0] == '+')
	{
		if (argv[1] != 0)
			(*num)++;
		else
			return (0);
	}
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
