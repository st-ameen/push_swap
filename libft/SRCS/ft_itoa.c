#include "libft.h"

int num_len(int n)
{
    int l = 0;
    while (n!= 0)
    {
        n = n / 10;
        l++;
    }
    return (l);
}

char *ft_itoa(int n)
{
    char *str;
    int start = 0;
    int end = 0;
    int l = num_len(n);
    int i = 0;
    if (n < 0)
    {
        start = 1;
        n = -n;
        l++;
        i++;
    }
    str = (char *)malloc((l + 1) * sizeof(char));
    if (str == NULL)
        return NULL;
    while (i < l)
    {
        str[i] = n % 10 + '0';
        n = n / 10;
        i++;
    }
    str[i] = '\0';
    if (start > 0)
        str[0] = '-';
    end = i - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}