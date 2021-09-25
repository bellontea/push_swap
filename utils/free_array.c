#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array + i && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
