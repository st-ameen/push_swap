#include "libft.h"
int is_safe(char **ss, char s, int w_c)
{
    while (w_c >= 0)
    {
        ss[w_c] = malloc(sizeof(char) * (ft_strlen(s) + 1));
        if (!ss[w_c])
        {
            while (w_c < (w_c + 1))
            {
                free(ss[w_c]);
                w_c++;
            }
            free(ss);
            return 0;
        }
        w_c--;
    }
    return 1;
}

int ft_word_count(const char *str, char c)
{
    int i = 0;
    int w_c = 0;
    while (str[i])
    {
        if (str[i]!= c && str[i + 1] == c)
        {
            w_c++;
            while (str[i] == c)
                i++;
        }
        i++;
    }
    return (w_c);
}

char **ft_split(char const *s, char c)
{
    int w_c = ft_word_count(s, c);
    int i = 0, j = 0, k = 0;
    if (w_c == 0)
        return NULL;
    char **ss = malloc(sizeof(char *) * (w_c + 1));
    if (!ss)
        return NULL;
    if (is_safe(ss, s, w_c) == 0)
    {
        free(ss);
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
        ss[j][k] = s[i];
        k++;
        i++;
    }
    ss[j + 1] = NULL;
    return (ss);
}
