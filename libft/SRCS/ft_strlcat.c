#include "libft.h"
unsigned int ft_strlcat(char *dst, const char *src, int len)
{
    unsigned int dst_len = ft_strlen(dst);
    unsigned int src_len = ft_strlen(src);
    unsigned int res = 0;
    unsigned int i = 0;
    
    if (len > dst_len)
        res = dst_len + src_len;
    else
        res = src_len + len;
    if (len == 0)
        return res;
    while (src[i]!= '\0' && dst_len + i < len - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return res;
}