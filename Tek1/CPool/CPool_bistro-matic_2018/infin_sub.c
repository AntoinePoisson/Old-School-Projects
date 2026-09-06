/*
** EPITECH PROJECT, 2018
** infin_sub
** File description:
** performs infinite soustractions
*/

#include <stddef.h>
#include <stdlib.h>
#include "./include/my.h"

char *selection_sub(char string_three[], int r, int i, int negative_case)
{
    if (r == 0)
        i = i - 1;
    if (negative_case == 0) {
        i = i - 1;
        string_three[i + 1] = '\0';
        for (i; string_three[i] == '0' && i > 0; i--);
        string_three[i + 1] = '-';
        string_three[i + 2] = '\0';
    } else {
        for ((i + 1); string_three[i] == '0' && i > 0; i--);
        string_three[i + 1] = '\0';
    }
    my_revstr(string_three);
    if (string_three[0] == '-' && string_three[1] ==
        '0' && string_three[2] == '\0')
        return ("0");
    return (string_three);
}

char *infin_sub_second(char *first, char *second, int negative_case)
{
    int i = 0;
    int r = 0;
    int carry = 0;
    char *string_three = NULL;
    int end_ft = 1;
    int end_sd = 1;

    is_reverser_str(first, second);
    string_three = malloc(sizeof(char) * (my_strlen(first) + 2));
    for (i = 0; !(end_sd == 0 && end_ft == 0); i++) {
        is_case_end_ft(first, i, &end_ft);
        is_case_end_sd(second, i, &end_sd);
        r = ((first[i] - 48) * end_ft) - ((second[i] - 48) * end_sd) - carry;
        is_extension_retenue_sub(&r, &carry);
        string_three[i] = (r + 48);
    }
    return (is_infin_next(i, r, string_three, negative_case));
}

char *is_zero_zero_sub(char *first, char *second)
{
    if (first[0] == '-' && first[1] == '0' &&
        first[2] == '\0' && second[0] == '0' && second [1] == '\0')
        return ("0");
    return ("1");
}

char *is_neg_sub_posi(char *first, char *second, char *second_second)
{
    my_strcpy(second_second, second);
    my_revstr(second_second);
    second_second[my_strlen(second_second)] = '-';
    second_second[my_strlen(second_second) + 1] = '\0';
    my_revstr(second_second);
    return (infin_add(first, second_second));
}

char *is_posi_sub_neg(char *first, char *second)
{
    my_revstr(second);
    second[my_strlen(second) - 1] = '\0';
    my_revstr(second);
    return (infin_add(first, second));
}

char *is_neg_sub_neg(char *first, char *second)
{
    my_revstr(second);
    second[my_strlen(second) - 1] = '\0';
    my_revstr(second);
    return (infin_add(first, second));
}

char *is_sub_size_eq(char *first, char *second, int negative_case)
{
    for (int i = 0; i >= 0; i++) {
        if (first[i] > second[i])
            return (infin_sub_second(first, second, negative_case));
        if (second[i] > first[i]) {
            negative_case = 0;
            return (infin_sub_second(second, first, negative_case));
        }
    }
    return ("84");
}

char *infin_sub(char *first, char *second)
{
    int negative_case = 1;
    char *second_second = malloc(sizeof(char) * (my_strlen(second) + 2));

    if (is_zero_zero_sub(first, second) != "1")
        return (is_zero_zero_sub(first, second));
    if (second[0] == '-' && first[0] != '-')
        return (is_posi_sub_neg(first, second));
    if (first[0] == '-' && second[0] != '-')
        return (is_neg_sub_posi(first, second, second_second));
    if (first[0] == '-' && second[0] == '-')
        return (is_neg_sub_neg(first, second));
    if (my_strlen(first) == my_strlen(second))
        return (is_sub_size_eq(first, second, negative_case));
    if (my_strlen(first) > my_strlen(second)) {
        return (infin_sub_second(first, second, negative_case));
    } else {
        negative_case = 0;
        return (infin_sub_second(second, first, negative_case));
    }
}
