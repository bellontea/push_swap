#include "push_swap.h"

void	replace(t_stack	**comms)
{
	t_stack	*save;

	save = *comms;
	while (*comms && (*comms)->next)
	{
		if (((*comms)->content == SA && (*comms)->next->content == SB)
			|| ((*comms)->content == SB && (*comms)->next->content == SA))
		{
			(*comms)->content = SS;
			ft_lstdel_next(comms);
		}
		if (((*comms)->content == RA && (*comms)->next->content == RB)
			|| ((*comms)->content == RB && (*comms)->next->content == RA))
		{
			(*comms)->content = RR;
			ft_lstdel_next(comms);
		}
		if (((*comms)->content == RRA && (*comms)->next->content == RRB)
			|| ((*comms)->content == RRB && (*comms)->next->content == RRA))
		{
			(*comms)->content = RRR;
			ft_lstdel_next(comms);
		}	
		if ((*comms)->next->next && (((*comms)->next->content == PA
					&& (*comms)->next->next->content == PB)
				|| ((*comms)->next->content == PB
					&& (*comms)->next->next->content == PA)))
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
