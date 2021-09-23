#include "push_swap.h"

int	check_existence(t_stack *comms, int current, int next)
{
	return (comms->content == current && comms->next->content == next);
}

void	replacement(t_stack	**comms, t_stack *save, int comm)
{
	(*comms)->content = comm;
	ft_lstdel_next(comms);
	*comms = save;
}

void	replace(t_stack	**comms)
{
	t_stack	*save;

	save = *comms;
	while (*comms && (*comms)->next)
	{
		if (check_existence(*comms, SA, SB) || check_existence(*comms, SB, SA))
			replacement(comms, save, SS);
		if (check_existence(*comms, RA, RB) || check_existence(*comms, RB, RA))
			replacement(comms, save, RR);
		if (check_existence(*comms, RRA, RRB)
			|| check_existence(*comms, RRB, RRA))
			replacement(comms, save, RRR);
		if ((*comms)->next->next && (check_existence((*comms)->next, PA, PB)
				|| check_existence((*comms)->next, PB, PA)))
		{
			ft_lstdel_next(comms);
			ft_lstdel_next(comms);
			*comms = save;
			continue ;
		}	
		*comms = (*comms)->next;
	}
	*comms = save;
}
