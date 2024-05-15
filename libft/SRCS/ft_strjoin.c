#include "libft.h"
char *ft_strjoin(char const *s1, char const *s2)
{
    char *str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
    if (!str)
        return (NULL);
    int i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        str[i + ft_strlen(s1)] = s2[i];
        i++;
    }
    str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return (str);
}