#include "ft_printf.h"

int nbr_len(int i)
{
	int l = 0;
	if (i == 0)
		return 1;
	if (i < 0)
	{
		l++;
		i = -i;
	}
	
	while (i != 0)
	{
		l++;
		i = i / 10;
	}
	return l;
}
