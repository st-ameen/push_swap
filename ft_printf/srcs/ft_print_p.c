#include "ft_printf.h"

int p_len(uintptr_t n)
{
	int l = 0;
	while (n != 0)
	{
		l++;
		n = n / 16;
	}
	return l;
}

void print_p(uintptr_t n)
{
	if (n >= 16)
	{
		print_p(n / 16);
		print_p(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_print_p(unsigned long long p)
{
	int	l = 0;

	l += write(1, "0x", 2);
	if (p == 0)
		l += write(1, "0", 1);
	else
	{
		print_p(p);
		l += p_len(p);
	}
	return (l);
}
