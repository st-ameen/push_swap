#include "ft_printf.h"

int ft_print_u(unsigned int u)
{
    char buffer[12];
    char *n = buffer;
    
    if (u == 0)
    {
        *n++ = '0';
    }
    else
    {
        while (u != 0)
        {
            *n++ = '0' + (u % 10);
            u /= 10;
        }
    }
    int width = n - buffer;

    while (n > buffer)
    {
        ft_putchar(*--n);
    }

    return width;
}
