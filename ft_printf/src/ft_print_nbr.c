#include "ft_printf.h"

int ft_print_nbr(int n, int base)
{
	int l = 0;
	char *s = "0123456789abcdef";

	if (n < 0)
	{
		ft_putchar('-');
		return ft_print_nbr(-n, base);
	}
	else if (n < base)
		return ft_putchar(s[n]);
	else
	{
		l = ft_print_nbr(n / base, base);
		return l + ft_print_nbr(n % base, base);
	}
	return l;
}
