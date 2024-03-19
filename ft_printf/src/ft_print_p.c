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
			write(1, &n, 1);
		else
			write(1, (char[]){n - 10 + 'a'}, 1);

	}
}

int ft_print_p(unsigned long long p)
{
	int l = 0;
	l += ft_print_str("0x");
	if (p == 0)
		return l += ft_putchar('0');
	l += p_len(p);
	print_p(p);
	return l;
}
