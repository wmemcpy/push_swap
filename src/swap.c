#include "../push_swap.h"

/*sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.*/
void	sa(t_stack *a, bool log)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->list->prev->data;
	a->list->prev->data = a->list->data;
	a->list->data = temp;
	if (log)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

/*sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.*/
void	sb(t_stack *b, bool log)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->list->prev->data;
	b->list->prev->data = b->list->data;
	b->list->data = temp;
	if (log)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

/*ss : sa et sb en même temps.*/
void	ss(t_stack *a, t_stack *b)
{
	sa(a, false);
	sb(b, false);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
