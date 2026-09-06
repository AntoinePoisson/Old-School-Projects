/*
** EPITECH PROJECT, 2018
** is_extension_two_infinimul
** File description:
** extension of infinimul three
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *is_extension_three_multip(int total, char *chaine_three, int *a)
{
    chaine_three[*a] = total + 48;
    *a += 1;
    return (chaine_three);
}

char *infin_mul_second(char *first, char *second, int negative_case)
{
    char *chaine_three = NULL;

    chaine_three = malloc(sizeof(char) * (my_strlen(first) + 2));
    if (chaine_three == NULL) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (is_zero_zero(first, second) == 0)
        return ("0");
    return (multip(first, second, chaine_three, negative_case));
}

char *is_neg_mul_posi(char *first, char *second, int *negative_case)
{
    *negative_case = 0;
    my_revstr(first);
    first[my_strlen(first) - 1] = '\0';
    my_revstr(first);
}

char *is_posi_mul_neg(char *first, char *second, int *negative_case)
{
    *negative_case = 0;
    my_revstr(second);
    second[my_strlen(second) - 1] = '\0';
    my_revstr(second);
}
