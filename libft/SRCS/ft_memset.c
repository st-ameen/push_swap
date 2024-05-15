void *ft_memset(void *b, int c, int len)
{
    len--;
    while (len >= 0)
    {
        *((unsigned char *)(b + len)) = (unsigned char) c;
        len--;
    }
    return b;
}
