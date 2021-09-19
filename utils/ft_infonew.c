#include "push_swap.h"

t_info	*ft_infonew(int size)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->flag = 0;
	info->next = 1;
	info->max = size;
	info->mid = info->max / 2 + info->next;
	return (info);
}
