#include "ft_printf.h"

int ft_print_format(va_list ar, const char s)
{
	int  l = 0;
	if (s == 'c')
		l += ft_putchar(va_arg(ar, int));
	else if (s == 's')
		l += ft_print_str(va_arg(ar, char *));
	else if (s == 'd' || s == 'i')
		l += ft_print_nbr(va_arg(ar, int), 10);
	else if (s == 'u')
		l += ft_print_u(va_arg(ar, unsigned int));
	else if (s == 'x' || s == 'X')
		l += ft_print_nbr(va_arg(ar, int), 16);
	else if (s == '%')
		l += ft_putchar('%');
	else if (s == 'p')
		l += ft_print_p(va_arg(ar, unsigned long long));
	return l;
}

int ft_printf(const char *str, ...)
{
	int i = 0;
	int l = 0;
	va_list ar;
	va_start(ar, str);
	while (str[i])
	{
		if (str[i] == '%')
			l += ft_print_format(ar, str[++i]);
		else
			l += ft_putchar(str[i]);
		i++;
	}
	va_end(ar);
	return l;
}
