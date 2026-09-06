/*
** EPITECH PROJECT, 2018
** is_extension_two_my_printf
** File description:
** extension two of my printf
*/

#include "my_extension.h"

int is_extension_printf_four_0(char *str, int i, va_list ap)
{
    if (str[i] == '%' && str[i + 1] == '0' && str[i + 2] == 'o') {
        my_put_nbr_base(va_arg(ap, int), "01234567");
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == '0' && str[i + 2] == 'x') {
        my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == '0' && str[i + 2] == 'u') {
        my_unsigned_putnbr(va_arg(ap, int));
        i += 3;
    }
    i = is_flag_neg(str, i);
    i = is_flag_h_tag(str, i, ap);
    return (i);
}

void is_extension_of_extension_three(long lon)
{
    my_putstr("\\");
    if (lon < 8)
        my_putchar('0');
    if (lon < 64)
        my_putchar('0');
    my_put_nbr_base(lon, "01234567");
}

int is_extension_printf_three(char *str, int i, va_list ap)
{
    long lon = 0;

    if (str[i] == '%' && str[i + 1] == 'S') {
        lon = va_arg(ap, long);
        if (lon < 32 || lon > 127)
            is_extension_of_extension_three(lon);
        else
            my_put_nbr(lon);
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == 'p') {
        my_putstr("0x");
        lon = va_arg(ap, long);
        if (lon != 0)
            my_put_adress(lon);
        else
            my_putchar('0');
        i += 2;
    }
    return (i);
}

int is_extension_printf_two(char *str, int i, va_list ap)
{
    char *s = NULL;

    if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'u') {
        my_unsigned_putnbr(va_arg(ap, long));
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == 's') {
        s = va_arg(ap, char *);
        if (s != NULL)
            my_putstr(s);
        else
            my_putstr("(null)");
        i += 2;
    }
    if (str[i] == '%' && str[i + 1] == '%') {
        my_putchar('%');
        i += 2;
    }
    return (i);
}

int is_extension_printf_0(char *str, int i, va_list ap)
{
    if ((str[i] == '%' && str[i + 1] == '0' && str[i + 2] == 'd')
        || (str[i] == '%' && str[i + 1] == '0' && str[i + 2] == 'i')) {
        my_put_nbr(va_arg(ap, int));
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == '0' && str[i + 2] == 'X') {
        my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
        i += 3;
    }
    if ((str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'd') ||
        (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'i')) {
        my_put_long(va_arg(ap, long));
        i += 3;
    }
    return (i);
}
