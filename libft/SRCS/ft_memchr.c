void *ft_memchr(const void *s, int c, int n)
{
    unsigned char *str = (unsigned char *)s;
    unsigned char byte = (unsigned char)c;

    while (n--)
    {
        if (*str == byte)
            return ((void *)str);
        str++;
    }
    return 0;
}