#include <stdio.h>
#include <unistd.h>

typedef unsigned char byte_t;

void print_address(void *s);
void print_hex(byte_t byte);
void print_c_h(void *s, unsigned int size);
void print_s(void *s, unsigned int size);
void ft_putchar(char c);
void *ft_print_memory(void *addr, unsigned int size);

int main()
{
    char empty[] = "";
    char big[] = "this string is too long for this";
    char str[] = "bonjour les amin";
    char str1[] = "ches\t\nc et fo";
    char str2[] = "u\ttout\tce qu on ";
    char str3[] = "peut faire avec\t";
    char str4[] = "\n\tprint memory\n\n";
    char str5[] = "\n\tlol.lol\n \0";

    ft_print_memory((void *)empty, sizeof(empty));
    ft_print_memory((void *)big, sizeof(big));
    ft_print_memory((void *)str, sizeof(str));
    ft_print_memory((void *)str1, sizeof(str1));
    ft_print_memory((void *)str2, sizeof(str2));
    ft_print_memory((void *)str3, sizeof(str3));
    ft_print_memory((void *)str4, sizeof(str4));
    ft_print_memory((void *)str5, sizeof(str5));

}

void *ft_print_memory(void *addr, unsigned int size)
{
    if (size <= 1)
        return addr;
    print_address(addr);
    print_c_h(addr, size);
    print_s(addr, size);
    return addr;
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_address(void *s)
{
    byte_t *ptr;
    int i = 7;
    ptr = (byte_t *)&s;
    while (i >= 0)
    {
        print_hex(*(ptr + i));
        i--;
    }
    ft_putchar(':');
}

void   print_hex(byte_t byte)
{
    if (byte / 16 < 10)
        ft_putchar(48 + byte / 16);
    else
        ft_putchar(87 + byte / 16);
    if (byte % 16 < 10)
        ft_putchar(48 + byte % 16);
    else
        ft_putchar(87 + byte % 16);
}

void print_c_h(void *s, unsigned int size)
{
    int i = 0;
    int limit = 16;
    while (--size && limit--)
    {
        if (!(i % 2))
            write(1, " ", 1);
        print_hex(*(byte_t *)s);
        s++;
        i++;
    }
    if (i % 2)
        write(1, "  ", 2);
    else
        write(1, " ", 1);
}

void print_s(void *s, unsigned int size)
{
    int limit = 16;
    while (--size && limit--)
    {
        if (*(char *)s >= 32 && *(char *)s < 127)
            write(1, s, 1);
        else
            write(1, ".", 1);
        s++;
    }
    ft_putchar('\n');
}