#include "ft_printf.h"

int ft_print_u(unsigned int u)
{
	int l = nbr_len(u);
	char *n;

	if (u == 0)
		l += ft_putchar('0');
	else 
	{
		n = malloc(sizeof(char) * (l + 1));
		if (!n)
			return 0;
		n[l] = '\0';
		while (n != 0)
		{
			n[l - 1] = u % 10 + 48;
			u = u / 10;
			l--;
		}
		l = 0;
		l += ft_print_str(n);
		free(n);
	}
	return l;
}
