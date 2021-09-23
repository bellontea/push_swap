#include "push_swap.h"

int	check_values(t_stack *s, int value)
{
	while (s)
	{
		if (s->order >= value)
			return (1);
		s = s->next;
	}
	return (0);
}
