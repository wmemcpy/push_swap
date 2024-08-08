#include "../push_swap.h"

int	ft_min(t_stack *x)
{
	t_node	*iter;
	int		min;

	min = x->list->data;
	iter = x->list->prev;
	while (iter != NULL)
	{
		if (iter->data < min)
			min = iter->data;
		iter = iter->prev;
	}
	return (min);
}

int	ft_max(t_stack *x)
{
	t_node	*iter;
	int		max;

	max = x->list->data;
	iter = x->list->prev;
	while (iter != NULL)
	{
		if (iter->data > max)
			max = iter->data;
		iter = iter->prev;
	}
	return (max);
}

int	ft_mid(t_stack *x)
{
	t_node	*iter;
	int		min;
	int		max;
	int		mid;

	min = x->list->data;
	max = x->list->data;
	iter = x->list->prev;
	while (iter != NULL)
	{
		if (iter->data < min)
			min = iter->data;
		if (iter->data > max)
			max = iter->data;
		iter = iter->prev;
	}
	mid = (min + max) / 2;
	return (mid);
}

bool	ft_is_sorted(t_stack *a, t_stack *b)
{
	t_node	*iter;

	iter = a->list;
	if (b->size != 0)
		return (false);
	while (iter->prev != NULL)
	{
		if (iter->data > iter->prev->data)
			return (false);
		iter = iter->prev;
	}
	return (true);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (EXIT_FAILURE);
}
