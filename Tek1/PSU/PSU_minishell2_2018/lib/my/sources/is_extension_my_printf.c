/*
** EPITECH PROJECT, 2018
** is_extension_my_printf
** File description:
** extension my printf file
*/

#include "my_extension.h"

int is_flag_h_tag(char *str, int i, va_list ap)
{
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'o') {
        my_putchar('0');
        my_put_nbr_base(va_arg(ap, int), "01234567");
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x') {
        my_putstr("0x");
        my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X') {
        my_putstr("0x");
        my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
        i += 3;
    }
    return (i);
}

int is_flag_espace(char *str, int i)
{
    if (str[i] == '%' && str[i + 1] == ' ') {
        my_putchar('%');
        for (; str[i + 1] == ' ' || str[i + 1] == '+'; i++);
    }
    return (i);
}

int is_flag_posi(char *str, int i)
{
    if ((str[i] == '%' && str[i + 1] == '+' && str[i + 2] == ' ' && str[i + 3]
        >= '0' && str[i + 3] <= '9') || (str[i] == '%' && str[i + 1] == '+' &&
        str[i + 2] == ' ' && str[i + 3] == '-')) {
        my_putstr("%+");
        i += 3;
    }
    if (str[i] == '%' && str[i + 1] == '+' && str[i + 2] == '+') {
        my_putchar('%');
        for (; (str[i + 1] == '+' || str[i + 1] == ' '
            || str[i + 1] == '-'); i++);
        if (str[i] == ' ' || str[i] == '+') {
            my_putchar('+');
            i++;
        }
    }
    return (i);
}

int is_extension_flag_neg(char *str, int i)
{
    int nb_espace = 0;
    int nb_posi = 0;

    for (; !(str[i] >= '0' && str[i] <= '9'); i++) {
        if (str[i] == '+')
            nb_posi++;
        if (str[i] == ' ')
            nb_espace++;
    }
    if (nb_espace > 0 && nb_posi > 0)
        my_putstr("%+-");
    if (nb_espace == 0 && nb_posi > 0)
        my_putstr("%+-");
    if (nb_espace > 0 && nb_posi == 0)
        my_putstr("% -");
    if (nb_espace == 0 && nb_posi == 0)
        my_putstr("%-");
    return (i);
}

int is_flag_neg(char *str, int i)
{
    if ((str[i] == '%' && str[i + 1] == '-' && str[i + 2] == '-') ||
        (str[i] == '%' && str[i + 1] == '-' && str[i + 2] == '+') ||
        (str[i] == '%' && str[i + 1] == '-' && str[i + 2] == ' ') ||
        (str[i] == '%' && str[i + 1] == '-' && str[i + 2] >= '0' &&
        str[i] <= '9'))
        i = is_extension_flag_neg(str, i);
    i = is_flag_espace(str, i);
    i = is_flag_posi(str, i);
    return (i);
}
