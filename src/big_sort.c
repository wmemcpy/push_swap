#include "../push_swap.h"

static void	push_last_bit_one(t_stack *a, t_stack *b, int bit_max, bool log)
{
	int	size;
	int	i;
	int	tmp;

	i = 0;
	size = a->size;
	while (i < size)
	{
		tmp = a->list->data;
		if (((tmp >> bit_max) & 1) == 0)
			pb(a, b, log);
		else
			ra(a, log);
		i++;
	}
}

void	big_sort(t_stack *a, t_stack *b, bool log)
{
	int	max_num;
	int	bit_max;

	max_num = ft_max(a);
	bit_max = 0;
	while (max_num >> bit_max)
	{
		push_last_bit_one(a, b, bit_max, log);
		while (b->size > 0)
			pa(a, b, log);
		bit_max++;
	}
}
