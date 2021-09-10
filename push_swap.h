#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct 		s_stack
{
	int				content;
	struct s_stack	*next;
	int				order;
	int				flag;
}					t_stack;

t_stack		*ft_lstnew(int content);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack *lst);
void		ft_lstclear(t_stack **lst);
void		ft_lstiter(t_stack *lst, void (*f)(int));
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void    	sa(t_stack **stack_a);
void    	sb(t_stack **stack_b);
void    	ss(t_stack **stack_a, t_stack **stack_b);
void    	pa(t_stack **a, t_stack **b);
void    	pb(t_stack **a, t_stack **b);
void    	ra(t_stack **a);
void    	rb(t_stack **b);
void    	rr(t_stack **a, t_stack **b);
void    	rra(t_stack **a);
void    	rrb(t_stack **b);
void    	rrr(t_stack **a, t_stack **b);
int			*sort(t_stack *stack, int size);

#endif
