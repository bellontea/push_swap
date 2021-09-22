#include "push_swap.h"

void	sw(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sort(t_stack *stack, int size)
{
	int	*array;
	int i;
	int	j;
	int	min;
	int	**links;

	array = malloc(sizeof(int) * size);
	links = malloc(sizeof(int*) * size);
	i = 0;
	while (stack)
	{
		array[i] = stack->content;
		links[i] = &(stack->order);
		stack = stack->next;
		i++;
	}
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
		sw((int *)&links[i], (int*)&links[min]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		*links[i] = i + 1;
		i++;
	}
	free(array);
	free(links);
}