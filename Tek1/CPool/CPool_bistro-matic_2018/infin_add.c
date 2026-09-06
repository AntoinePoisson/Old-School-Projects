/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** corp of infin_add
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int is_zero_zero(char *first, char *second)
{
    int taille_1 = my_strlen(first);
    int taille_2 = my_strlen(second);

    if (taille_1 == 1 && taille_2 == 1)
        if (first[0] == '0' && second[0] == '0')
            return (0);
    if (first[0] == '-' && first[1] == '0' && first[2] == '\0' &&
        second[0] == '0' && second [1] == '\0' || first[0] == '-' &&
        first[1] == '0' && first[2] == '\0' && second[0] == '-' &&
        second [1] == '0' && second[2] == '\0')
        return (0);
    return (1);
}

char *infin_add(char *first, char *second)
{
    if (first[0] == '-' && second[0] != '-') {
        my_revstr(first);
        first[my_strlen(first) - 1] = '\0';
        my_revstr(first);
        return (infin_sub(second, first));
    }
    if (second[0] == '-' && first[0] != '-') {
        my_revstr(second);
        second[my_strlen(second) - 1] = '\0';
        my_revstr(second);
        return (infin_sub(first, second));
    }
    if (is_zero_zero(first, second) == 0)
        return ("0");
    if (my_strlen(first) >= my_strlen(second))
        return (infin_add_second(first, second));
    return (infin_add_second(second, first));
}

char *infin_add_second(char *first, char *second)
{
    int i = 0;
    int r = 0;
    int carry = 0;
    char *chaine_three = NULL;
    int end_a = 1;
    int end_b = 1;
    int exit_negative = is_extension_exit_negative(first, second);

    chaine_three = malloc(sizeof(char) * (my_strlen(first) + 2));
    for (i = 0; !(end_b == 0 && end_a == 0); i++) {
        if (second[i + exit_negative] == '\0')
            end_b = 0;
        if (first[i + exit_negative] == '\0')
            end_a = 0;
        r = ((first[i] - 48) * end_a) + ((second[i] - 48) * end_b) + carry;
        is_extension_retenue(&r, &carry);
        chaine_three[i] = (r + 48);
    }
    return (selection_add(chaine_three, r, i, first));
}

char *selection_add(char *chaine_three, int r, int i, char *first)
{
    if (r == 0)
        i = i - 1;
    my_revstr(first);
    if (first[0] == '-') {
        i = i - 1;
        chaine_three[i + 1] = '\0';
        for (i; chaine_three[i] == '0'; i--);
        chaine_three[i + 1] = '-';
        chaine_three[i + 2] = '\0';
    } else {
        for ((i + 1); chaine_three[i] == '0'; i--);
        chaine_three[i + 1] = '\0';
    }
    my_revstr(chaine_three);
    return (chaine_three);
}
