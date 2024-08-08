#include "../push_swap.h"

t_stack	*ft_tab_to_stack(int *tab, int size)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->size = size;
	stack->list = NULL;
	while (i < size)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			exit(EXIT_FAILURE);
		node->data = tab[i];
		node->prev = stack->list;
		stack->list = node;
		i++;
	}
	free(tab);
	return (stack);
}

void	ft_stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->list;
	while (node)
	{
		tmp = node;
		node = node->prev;
		free(tmp);
	}
	free(stack);
}

static void	chose_sort(t_stack *a, t_stack *b, bool log)
{
	if (a->size == 2)
		sa(a, log);
	else if (a->size == 3)
		little_sort_3(a, log);
	else if (a->size == 4)
		little_sort_4(a, b, log);
	else if (a->size == 5)
		little_sort_5(a, b, log);
	else
		big_sort(a, b, log);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!ft_check_args(argc, argv))
		return (ft_error());
	if (argc == 2)
		return (EXIT_SUCCESS);
	a = ft_tab_to_stack(ft_init_tab(argc, argv), argc - 1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (EXIT_FAILURE);
	b->size = 0;
	b->list = NULL;
	if (!ft_is_sorted(a, b))
		chose_sort(a, b, true);
	ft_stack_free(a);
	ft_stack_free(b);
	return (EXIT_SUCCESS);
}
