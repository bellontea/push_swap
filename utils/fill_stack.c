#include "push_swap.h"

int		fill_stack(int size, char **nums, t_stack **a)
{
	int	num;

	while (size)
	{
		num = 0;
		if (!ft_check_nums(nums[size], *a, &num))
		{
			ft_error(a, NULL);
			return (0);
		}
		ft_lstadd_front(a, ft_lstnew(num));
		size--;
	}
	return (1);
}
