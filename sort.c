#include "push_swap.h"

int	*sort(t_stack *stack, int size)
{
	int	*array;
	int i;

	array = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (array);
}