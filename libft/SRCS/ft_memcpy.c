void *ft_memcpy(void *dest, const void *src, int n)
{
    char *dest_ptr = (char *)dest;
    const char *src_ptr = (const char *)src;
    while (n--)
    {
        *dest_ptr = *src_ptr;
        dest++;
        src++;
    }
}
