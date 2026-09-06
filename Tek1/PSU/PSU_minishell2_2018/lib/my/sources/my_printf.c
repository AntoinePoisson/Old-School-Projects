/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** it's my printf
*/

#include "my_printf.h"

int is_extension_printf_four(char *str, int i, va_list ap, int previous)
{
    if (str[i] == '%' && str[i + 1] == 'o') {
        my_put_nbr_base(va_arg(ap, int), "01234567");
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == 'x') {
        my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == 'u') {
        my_unsigned_putnbr(va_arg(ap, int));
        i += 2;
    }
    i = is_extension_printf_four_0(str, i, ap);
    if (previous == i)
        my_putchar(str[i]);
    return (i);
}

int is_extension_printf(char *str, int i, va_list ap)
{
    if ((str[i] == '%' && str[i + 1] == 'd') || (str[i] == '%'
        && str[i + 1] == 'i')) {
        my_put_nbr(va_arg(ap, int));
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == 'c') {
        my_putchar(va_arg(ap, int));
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == 'b') {
        my_put_nbr_base(va_arg(ap, int), "01");
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == 'X') {
        my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
        i += 2;
    }
    i = is_extension_printf_0(str, i, ap);
    return (i);
}

int is_extension_my_printf(char *str, int i)
{
    if (str[i] == '%' && str[i + 1] == 'n') {
        my_put_nbr(return_printf);
        i += 2;
    }
    return (i);
}

int my_printf(char *str, ...)
{
    va_list ap;
    int i = 0;
    int previous = 1;

    va_start(ap, str);
    while (str[i] != '\0') {
        if (previous == i)
            i++;
        if (str[i] == '\0')
            break;
        previous = i;
        i = is_extension_my_printf(str, i);
        i = is_extension_printf(str, i, ap);
        i = is_extension_printf_two(str, i, ap);
        i = is_extension_printf_three(str, i, ap);
        i = is_extension_printf_four(str, i, ap, previous);
    }
    va_end(ap);
    return (return_printf);
}
