#include "libft.h"
char *ft_strdup(const char *s)
{
    char *d = malloc(ft_strlen(s) + 1);
    if (d == NULL)
        return NULL;       
    ft_strlcpy(d,s, ft_strlen(s) + 1);
    return d;
}