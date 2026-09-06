/*
** EPITECH PROJECT, 2018
** infin_mul
** File description:
** Infin_mul
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *selection(char chaine_three[], int result, int i, char *para_useless)
{
    if (result == 0)
        i = i - 1;
    for ((i+1); chaine_three[i] == '0'; i--);
    chaine_three[i + 1] = '\0';
    return (chaine_three);
}

char *extend_infmul(char *result, char *chaine_three)
{
    int i = 0;
    int end_a = 1;
    int end_b = 1;
    int r = 0;
    int carry = 0;

    for (i = 0; !(end_b == 0 && end_a == 0); i++) {
        if (result[i] == '\0')
            end_a = 0;
        if (chaine_three[i] == '\0')
            end_b = 0;
        r = ((result[i] - 48) * end_a) +
            ((chaine_three[i] - 48) * end_b) + carry;
        is_extension_retenue(&r, &carry);
        result[i] = (r + 48);
    }
    return (selection(result, r, i, chaine_three));
}

char *selection_mul(char chaine_three[], int result, int i, int negative_case)
{
    int counter_zero = 0;

    if (chaine_three[0] == '0' && chaine_three[1] == '0') {
        for (counter_zero; chaine_three[counter_zero] == '0'; counter_zero++);
        if (counter_zero == i)
            return ("0");
    }
    if (negative_case == 0) {
        i = i - 1;
        chaine_three[i + 1] = '\0';
        for (i; chaine_three[i] == '0' && i > 0; i--);
        chaine_three[i + 1] = '-';
        chaine_three[i + 2] = '\0';
    } else {
        for (i; chaine_three[i] == '0' && i > 0; i--);
        chaine_three[i + 1] = '\0';
    }
    my_revstr(chaine_three);
    return (chaine_three);
}

char *multip(char *first, char *second, char *chaine_three, int negative_case)
{
    int i = 0;
    int a = 0;
    char *result = NULL;
    int total = 0;
    int retenue = 0;

    revstring(first, second);
    result = malloc(sizeof(char) * (my_strlen(first) * my_strlen(second)+ 2));
    for (i = 0; second[i] != '\0'; i++) {
        is_extension_multip(&a, i, first, chaine_three);
        for (int y = 0; first[y] != '\0'; y++) {
            total = (first[y] - 48) * (second[i] - 48) + retenue;
            is_carry_mul(&retenue, &total);
            is_extension_three_multip(total, chaine_three, &a);
        }
        end(retenue, chaine_three, a);
        is_extension_two_multip(result, chaine_three, i);
    }
    a = my_strlen(result);
    return (selection_mul(result, retenue, a, negative_case));
}

char *infin_mul(char *first, char *second)
{
    int negative_case = 1;
    int size_first = 0;
    int size_second = 0;

    if (first[0] == '-' && second[0] != '-')
        is_neg_mul_posi(first, second, &negative_case);
    if (first[0] != '-' && second[0] == '-')
        is_posi_mul_neg(first, second, &negative_case);
    if (first[0] == '-' && second[0] == '-') {
        is_neg_mul_posi(first, second, &negative_case);
        is_posi_mul_neg(first, second, &negative_case);
        negative_case = 1;
    }
    size_first = my_strlen(first);
    size_second = my_strlen(second);
    if (size_first >= size_second)
        return (infin_mul_second(first, second, negative_case));
    else
        return (infin_mul_second(second, first, negative_case));
}
