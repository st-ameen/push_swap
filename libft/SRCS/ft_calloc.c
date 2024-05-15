#include "libft.h"

void *ft_calloc(size_t c, size_t s)
{
	void	*res;

	res = malloc(s * c);
	if (!res)
		return (0);
	ft_bzero(res, s * c);
	return (res);
}