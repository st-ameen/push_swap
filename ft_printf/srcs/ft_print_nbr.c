#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int l = 0;
	l = nbr_len(n);
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_print_nbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_print_nbr(n);
	}
	else if (n > 9)
	{
		ft_print_nbr(n / 10);
		ft_print_nbr(n % 10);
	}
	else
		 ft_putchar(n + 48);
	return l;
}