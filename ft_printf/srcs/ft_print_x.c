#include "ft_printf.h"

int	ft_x_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_x(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_x(num / 16, format);
		ft_put_x(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_print_x(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_x(num, format);
	return (ft_x_len(num));
}