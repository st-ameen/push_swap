#include "libft.h"

int is_safe(char **str, char s, int w)
{
    while (w >= 0)
    {
        str[w] = malloc(sizeof(char) * (ft_strlen(s) + 1));
        if (!str[w])
        {
            while (w < (w + 1))
            {
                free(str[w]);
                w++;
            }
            free(str);
            return 0;
        }
        w--;
    }
    return 1;
}

int ft_word_count(const char *str, char c)
{
    int i = 0;
    int w = 0;
    while (str[i])
    {
        if (str[i] != c && str[i + 1] == c)
        {
            w++;
            while (str[i] == c)
                i++;
        }
        i++;
    }
    return w;
}

char **ft_split(char const *s, char c)
{
    int w = ft_word_count(s, c);
    int i = 0, j = 0, k = 0;
    if (w == 0)
        return NULL;
    char **str = malloc(sizeof(char *) * (w + 1));
    if (!str)
        return NULL;
    if (is_safe(str, s, w) == 0)
    {
        free(str);
        return NULL;
    }
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            while (s[i] == c)
                i++;
            j++;
            k = 0;
        }
        str[j][k] = s[i];
        k++;
        i++;
    }
    str[j + 1] = NULL;
    return (str);
}
