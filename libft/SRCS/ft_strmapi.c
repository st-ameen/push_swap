#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    int i = 0;
    int len = ft_strlen(s);
	if (!s || !f)
		return NULL;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    while (s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return str;
}