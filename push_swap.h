#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				order;
	int				flag;
}					t_stack;

typedef struct s_info
{
	int			max;
	int			mid;
	int			next;
	int			flag;
}				t_info;

enum e_content
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

t_stack		*ft_lstnew(int content);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack *lst);
void		ft_lstdel_next(t_stack **lst);
void		ft_lstclear(t_stack **lst);
void		ft_lstiter(t_stack *lst, void (*f)(int));
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		sa(t_stack **a, t_stack **b);
void		sb(t_stack **a, t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a, t_stack **b);
void		rb(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a, t_stack **b);
void		rrb(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		sort(t_stack *stack, int size);
void		array_output(t_stack *stack, int size);
void		stack_sort(t_stack **a, int size);
void		output(t_stack	*comms);
t_info		*ft_infonew(int size);
int			is_sorted(t_stack *a);
void		mini_stack_sort(t_stack **a, int size);
void		replace(t_stack	**comms);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
void		ft_error(t_stack **a, t_stack **comms);
int			ft_check_nums(char *argv, t_stack *a, int *num);
int			fill_stack(int size, char **nums, t_stack **a);
void		*ft_memset(void *b, int c, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		clear_all(t_stack **a, t_stack **b, t_stack **comms);
void		check_top_value(t_stack **a, t_stack **b, t_info *info,
				t_stack **comms);

#endif
