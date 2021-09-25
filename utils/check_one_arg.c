#include "push_swap.h"

int	check_one_arg(int *argc, char *arg, t_stack **a)
{
	int		ret;
	char	**array;	

	ret = 0;
	if (*argc > 2)
		return (ret);
	array = ft_split(arg, ' ');
	*argc = array_size(array) + 1;
	ret = fill_stack(*argc - 1, array, a);
	free_array(array);
	return (ret);
}
