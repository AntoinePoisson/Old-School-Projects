/*
** EPITECH PROJECT, 2018
** infin div
** File description:
** performs infinite divisions
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void check_div_zero(char *divisor, char* divided)
{
    if (divisor[0] == '0' && my_strlen(divisor) == 1) {
        my_putstr(DIV_BY_O_MSG);
        exit(DIV_OR_MOD_O);
    }
    if (my_strlen(divided) > 7) {
        my_putstr(TIME_OUT_MSG);
        exit(TIME_OUT);
    }
}

char *is_delet_zero_begin(char *str)
{
    int i = 0;

    my_revstr(str);
    for (i = my_strlen(str); str[i - 1] == '0'; i--);
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

char *is_extension_div(int case_neg, char *result)
{
    char one[] = "1";
    char one_neg[] = "-1";

    if (case_neg == 1) {
        result = infin_mul(result, one_neg);
        return (infin_add(result, one));
    }
    return (infin_sub(result, one));
}

char *is_div_neg(char *str, int *case_neg)
{
    if (str[0] == '-') {
        str[0] = '0';
        *case_neg += 1;
    }
    return (str);
}

char *infin_div(char *divided, char* divisor)
{
    char *divided_copy = malloc(sizeof(char) * my_strlen(divided));
    char *result = malloc(sizeof(char) * (my_strlen(divided)));
    int case_neg = 0;
    char one[] = "1";

    result[0] = '0';
    check_div_zero(divisor, divided);
    is_div_neg(divided, &case_neg);
    is_div_neg(divisor, &case_neg);
    is_delet_zero_begin(divided);
    is_delet_zero_begin(divisor);
    my_strcpy(divided_copy, divided);
    for (result; divided_copy[0] != '-'; result = infin_add(result, one)) {
        divided_copy = infin_sub(divided_copy, divisor);
        my_revstr(divisor);
    }
    return (is_extension_div(case_neg, result));
}
