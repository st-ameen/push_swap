#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

int p_len(uintptr_t n);
void print_p(uintptr_t n);
int ft_print_p(unsigned long long p);
int ft_print_format(va_list ar, const char s);
int ft_printf(const char *str, ...);
int ft_print_nbr(int n, int base);
int ft_print_str(char *str);
int ft_print_u(unsigned int u);
int nbr_len(int n);
int ft_putchar(char c);

#endif
