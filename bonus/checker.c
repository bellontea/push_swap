#include "push_swap.h"

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
