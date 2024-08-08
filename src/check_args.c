#include "../push_swap.h"

static void	ft_fill_rank(int *tab, int *rank, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		rank[i]++;
		while (j < argc - 1)
		{
			if (tab[i] > tab[j])
				rank[i]++;
			j++;
		}
		i++;
	}
}

int	*ft_init_tab(int argc, char **argv)
{
	int	*tab;
	int	*rank;
	int	i;
	int	j;

	tab = ft_calloc(sizeof(int), (argc - 1));
	rank = ft_calloc(sizeof(int), (argc - 1));
	if (!tab || !rank)
		exit(EXIT_FAILURE);
	i = 1;
	j = argc - 2;
	while (i < argc)
	{
		tab[j] = ft_atoi(argv[i]);
		i++;
		j--;
	}
	ft_fill_rank(tab, rank, argc);
	free(tab);
	return (rank);
}

static bool	ft_isint(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Checks the command line arguments for validity.
 *
 * This function checks if the command line arguments are valid for the program.
 * It ensures that there are no duplicate arguments, and that each argument is a valid integer.
 * Additionally, it checks if the argument is within the range of INT_MIN and INT_MAX,
 * and if the length of the argument is within the limit of 11 characters.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings representing the command line arguments.
 * @return Returns true if the arguments are valid, false otherwise.
 */
bool	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (false);
			j++;
		}
		if (!ft_isint(argv[i]))
			return (false);
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN
			|| ft_strlen(argv[i]) > 11)
			return (false);
		i++;
	}
	return (true);
}
