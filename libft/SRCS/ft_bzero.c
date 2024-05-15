void ft_bzero(void *b, int len)
{
    while (len > 0)
    {
        len--;
        *((unsigned char *)(b + len)) = 0;
    }
}