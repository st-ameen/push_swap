#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void stack_init(t_stack_node **a, char **av, bool flag)
{
    long nbr;
    int i;
    
    i = 0;
    while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag);
		nbr = ft_atol(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_free(a, av, flag);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag)
		free_matrix(av);
}