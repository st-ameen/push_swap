int ft_isascii(const char c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0); 
}