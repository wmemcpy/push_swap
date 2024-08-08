#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// read, write
# include <unistd.h>
// malloc, free, exit
# include <stdlib.h>
// bool, true, false
# include <stdbool.h>
// INT_MAX, INT_MIN
# include <limits.h>

# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct t_stack
{
	t_node	*list;
	int		size;
}	t_stack;

/*operations*/
void	sa(t_stack *a, bool log);
void	sb(t_stack *b, bool log);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b, bool log);
void	pb(t_stack *a, t_stack *b, bool log);
void	ra(t_stack *a, bool log);
void	rb(t_stack *b, bool log);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, bool log);
void	rrb(t_stack *b, bool log);
void	rrr(t_stack *a, t_stack *b);

/*utils*/
int		ft_min(t_stack *x);
int		ft_max(t_stack *x);
int		ft_mid(t_stack *x);

/*sort*/
void	little_sort_3(t_stack *a, bool log);
void	little_sort_4(t_stack *a, t_stack *b, bool log);
void	little_sort_5(t_stack *a, t_stack *b, bool log);
void	big_sort(t_stack *a, t_stack *b, bool log);

/*stack*/
bool	ft_check_args(int argc, char **argv);
int		*ft_init_tab(int argc, char **argv);

/*utils*/
bool	ft_is_sorted(t_stack *a, t_stack *b);
int		ft_error(void);

/*main*/
t_stack	*ft_tab_to_stack(int *tab, int size);
void	ft_stack_free(t_stack *stack);

/*bonus*/
char	*get_next_line(int fd);

#endif