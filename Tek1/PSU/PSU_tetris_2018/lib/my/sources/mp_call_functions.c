/*
** EPITECH PROJECT, 2019
** mprintf
** File description:
** mp_call_functions.c
*/

#include "mprintf.h"

static void one_character(char flag, va_list *list)
{
    if (flag == '%')
        mp_mput('%');
    else if (flag == 'c')
        mp_mput((char)va_arg(*list, int));
}

static void call_convertion(int j, va_list *list, int (*array_ptr[NB_FUNCT])())
{
    if (j == 7)
        array_ptr[j]((struct arg_s){va_arg(*list, unsigned int), 8, 'o'});
    if (j == 8)
        array_ptr[j]((struct arg_s){va_arg(*list, unsigned int), 2, 'b'});
    if (j == 9)
        array_ptr[j]((struct arg_s){va_arg(*list, unsigned int), 16, 'x'});
    if (j == 10)
        array_ptr[j]((struct arg_s){va_arg(*list, unsigned int), 16, 'X'});
}

static void call_function(int j, va_list *list, int (*array_ptr[NB_FUNCT])())
{
    if (j <= 2)
        array_ptr[j](va_arg(*list, char *));
    if (j == 3)
        array_ptr[j](va_arg(*list, char const **));
    if (j >= 4 && j <= 6)
        array_ptr[j](va_arg(*list, int));
    if (j == 11)
        array_ptr[j](va_arg(*list, double));
    if (j == 12)
        array_ptr[j](va_arg(*list, void const *));
    if (j == 13)
        array_ptr[j](va_arg(*list, long long));
}

void mp_check_funct(char flag, va_list *list, int (*array_ptr[NB_FUNCT])())
{
    int j;

    if (flag == '%' || flag == 'c')
        one_character(flag, list);
    else {
        for (j = 0; flag != STRING_INDEX[j] && j != 14; j++);
        if (j < 7 || j > 10)
            call_function(j, list, array_ptr);
        else
            call_convertion(j, list, array_ptr);
    }
}
