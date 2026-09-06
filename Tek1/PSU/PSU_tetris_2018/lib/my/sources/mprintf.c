/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mprintf.c
*/

#include "mprintf.h"

static void init_array(int (*array_ptr[NB_FUNCT])())
{
    array_ptr[0] = mp_disp_rev;
    array_ptr[1] = mp_mputstr;
    array_ptr[2] = mp_mputhexa;
    array_ptr[3] = mp_double_array;
    array_ptr[4] = mp_mput_nbr;
    array_ptr[5] = mp_mput_nbr;
    array_ptr[6] = mp_mput_un;
    array_ptr[7] = mp_convert_nb;
    array_ptr[8] = mp_convert_nb;
    array_ptr[9] = mp_convert_nb;
    array_ptr[10] = mp_convert_nb;
    array_ptr[11] = mp_mput_double;
    array_ptr[12] = mp_disp_adress;
    array_ptr[13] = mp_mput_long;
}

static int check_flag(char const *str, int i)
{
    for (int a = 0; a != 17; a++)
        if (mp_mstrcmp(&str[i], flags[a]) == 0)
            return (0);
    return (-1);
}

static int pass_format(int i, char const *s)
{
    for (i += 1; s[i] == 43 || s[i] == 32 || s[i] == 48 || s[i] == 35; i++);
    i += (s[i] == 'h') ? 1 : 0;
    return (i);
}

int mprintf(char const *str, ...)
{
    va_list list;
    int (*array_ptr[NB_FUNCT])();

    init_array(array_ptr);
    va_start(list, str);
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '%' && check_flag(str, i) == 0) {
            i = pass_format(i, str);
            mp_check_funct(str[i], &list, array_ptr);
            i += (str[i] == 'l') ? 1 : 0;
        } else
            mp_mput(str[i]);
    }
    va_end(list);
    return (0);
}
