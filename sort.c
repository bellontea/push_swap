#include "push_swap.h"

void	sw(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int	*sort(t_stack *stack, int size)
{
	int	*array;
	int i;
	int	j;
	int	min;

	array = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	array_output(array, size);
	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		sw(&array[i], &array[min]);
		i++;
	}
	return (array);
}