#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str = (char *)malloc(len + 1);
    int i = 0;
    if (str == NULL)
     return (NULL);
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}