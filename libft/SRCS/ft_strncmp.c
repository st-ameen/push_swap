int ft_strncmp(const char *s1, const char *s2, int n)
{
    while (n-- && *s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}