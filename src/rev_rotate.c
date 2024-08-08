#include "../push_swap.h"

/*rra (reverse rotate a) : Décale d’une position vers le bas tous les élements
de la pile a. Le dernier élément devient le premier.*/
void	rra(t_stack *a, bool log)
{
	t_node	*iter;
	t_node	*elem;

	if (a->size < 2)
		return ;
	iter = a->list;
	while (iter->prev->prev != NULL)
		iter = iter->prev;
	elem = iter->prev;
	iter->prev = NULL;
	elem->prev = a->list;
	a->list = elem;
	if (log)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

/*rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements
de la pile b. Le dernier élément devient le premier.*/
void	rrb(t_stack *b, bool log)
{
	t_node	*iter;
	t_node	*elem;

	if (b->size < 2)
		return ;
	iter = b->list;
	while (iter->prev->prev != NULL)
		iter = iter->prev;
	elem = iter->prev;
	iter->prev = NULL;
	elem->prev = b->list;
	b->list = elem;
	if (log)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

/*rrr : rra et rrb en même temps.*/
void	rrr(t_stack *a, t_stack *b)
{
	rra(a, false);
	rrb(b, false);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
