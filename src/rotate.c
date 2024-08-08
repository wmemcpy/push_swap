#include "../push_swap.h"

/*ra (rotate a) : Décale d’une position vers le haut tous les élements de la
pile a. Le premier élément devient le dernier.*/
void	ra(t_stack *a, bool log)
{
	t_node	*elem;
	t_node	*iter;

	if (a->size < 2)
		return ;
	elem = a->list;
	a->list = a->list->prev;
	elem->prev = NULL;
	iter = a->list;
	while (iter->prev != NULL)
		iter = iter->prev;
	iter->prev = elem;
	if (log)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

/*rb (rotate b) : Décale d’une position vers le haut tous les élements de la
pile b. Le premier élément devient le dernier.*/
void	rb(t_stack *b, bool log)
{
	t_node	*elem;
	t_node	*iter;

	if (b->size < 2)
		return ;
	elem = b->list;
	b->list = b->list->prev;
	elem->prev = NULL;
	iter = b->list;
	while (iter->prev != NULL)
		iter = iter->prev;
	iter->prev = elem;
	if (log)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

/*rr : ra et rb en même temps.*/
void	rr(t_stack *a, t_stack *b)
{
	ra(a, false);
	rb(b, false);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
