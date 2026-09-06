/*
** EPITECH PROJECT, 2018
** infin mod
** File description:
** performs infinite modulos
*/

#include <stdlib.h>
#include "my.h"

void check_mod_zero(char *divisor, char *divided)
{
    if (divisor[0] == '0' && my_strlen(divisor) == 1) {
        my_putstr(MOD_BY_O_MSG);
        exit(DIV_OR_MOD_O);
    }
    if (my_strlen(divided) > 7) {
        my_putstr(TIME_OUT_MSG);
        exit(TIME_OUT);
    }
}

char *infin_mod_second(char *divided, char* divisor, int negative_case)
{
    char one[] = "-1";
    char *division = infin_div(divided, divisor);
    char *mult = infin_mul(division, divisor);
    char *sub = malloc(sizeof(char) * (my_strlen(mult) + 2));

    sub = infin_sub(divided, mult);
    if (negative_case == 0 && sub[0] != '0' && sub[1] != '\0')
        return (infin_mul(sub, one));
    return (sub);
}

void reverse_string(char *divided, char* divisor)
{
    my_revstr(divided);
    my_revstr(divisor);
}

int is_divisor_bigger(char *divided, char* divisor)
{
    int size_divided = my_strlen(divided);
    int size_divisor = my_strlen(divisor);

    if (divided[0] == '-')
        size_divided -= 1;
    if (divisor[0] == '-')
        size_divisor -= 1;
    if (size_divided < size_divisor)
        return (1);
    if (size_divided == size_divisor)
        return (size_equal(divided, divisor));
    return (0);
}

char *infin_mod(char *divided, char* divisor)
{
    int i = 0;
    int negative_case = 1;

    check_mod_zero(divisor, divided);
    if (is_divisor_bigger(divided, divisor) == 1)
        return (divided);
    if (divided[0] == '-') {
        divided[0] = '0';
        negative_case = 0;
    }
    if (divisor[0] == '-')
        divisor[0] = '0';
    reverse_string(divided, divisor);
    for (i = my_strlen(divisor); divisor[i - 1] == '0'; i--);
    divisor[i] = '\0';
    for (i = my_strlen(divided); divided[i - 1] == '0'; i--);
    divided[i] = '\0';
    reverse_string(divided, divisor);
    return (infin_mod_second(divided, divisor, negative_case));
}
