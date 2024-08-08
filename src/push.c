#include "../push_swap.h"

/*pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.*/
void	pa(t_stack *a, t_stack *b, bool log)
{
	t_node	*elem;

	if (b->size == 0)
		return ;
	elem = b->list;
	b->list = b->list->prev;
	b->size--;
	elem->prev = a->list;
	a->list = elem;
	a->size++;
	if (log)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
}

/*pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.*/
void	pb(t_stack *a, t_stack *b, bool log)
{
	t_node	*elem;

	if (a->size == 0)
		return ;
	elem = a->list;
	a->list = a->list->prev;
	a->size--;
	elem->prev = b->list;
	b->list = elem;
	b->size++;
	if (log)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}
