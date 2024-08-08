#include "../push_swap.h"

static void	little_sort_5_1(t_stack *a, t_stack *b, bool log)
{
	if (a->list->data == 1)
		pb(a, b, log);
	else if (a->list->prev->data == 1)
	{
		sa(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->data == 1)
	{
		ra(a, log);
		ra(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->prev->data == 1)
	{
		rra(a, log);
		rra(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->prev->prev->data == 1)
	{
		rra(a, log);
		pb(a, b, log);
	}
}

static void	little_sort_5_2(t_stack *a, t_stack *b, bool log)
{
	if (a->list->data == 2)
		pb(a, b, log);
	else if (a->list->prev->data == 2)
	{
		sa(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->data == 2)
	{
		ra(a, log);
		ra(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->prev->data == 2)
	{
		rra(a, log);
		pb(a, b, log);
	}
}

void	little_sort_5(t_stack *a, t_stack *b, bool log)
{
	little_sort_5_1(a, b, log);
	little_sort_5_2(a, b, log);
	little_sort_3(a, log);
	pa(a, b, log);
	pa(a, b, log);
}

void	little_sort_3(t_stack *a, bool log)
{
	if (a->list->data == ft_mid(a) && a->list->prev->data == ft_min(a) \
		&& a->list->prev->prev->data == ft_max(a))
		sa(a, log);
	else if (a->list->data == ft_max(a) && a->list->prev->data == ft_mid(a) \
		&& a->list->prev->prev->data == ft_min(a))
	{
		sa(a, log);
		rra(a, log);
	}
	else if (a->list->data == ft_min(a) && a->list->prev->data == ft_max(a) \
		&& a->list->prev->prev->data == ft_mid(a))
	{
		sa(a, log);
		ra(a, log);
	}
	else if (a->list->data == ft_max(a) && a->list->prev->data == ft_min(a) \
		&& a->list->prev->prev->data == ft_mid(a))
		ra(a, log);
	else if (a->list->data == ft_mid(a) && a->list->prev->data == ft_max(a) \
		&& a->list->prev->prev->data == ft_min(a))
		rra(a, log);
}

void	little_sort_4(t_stack *a, t_stack *b, bool log)
{
	if (a->list->data == ft_min(a))
		pb(a, b, log);
	else if (a->list->prev->data == ft_min(a))
	{
		sa(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->data == ft_min(a))
	{
		ra(a, log);
		ra(a, log);
		pb(a, b, log);
	}
	else if (a->list->prev->prev->prev->data == ft_min(a))
	{
		rra(a, log);
		pb(a, b, log);
	}
	little_sort_3(a, log);
	pa(a, b, log);
}
