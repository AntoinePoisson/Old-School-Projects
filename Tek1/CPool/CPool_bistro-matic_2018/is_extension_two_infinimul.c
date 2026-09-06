/*
** EPITECH PROJECT, 2018
** is_extension_two_infinimul
** File description:
** extension of infinimul
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *end(int carry, char *chaine_three, int a)
{
    if (carry != 0) {
        chaine_three[a] = carry + 48;
        a++;
    }
    chaine_three[a] = '\0';
    return (chaine_three);
}

char *is_extension_multip(int *a, int i, char *first, char *chaine_three)
{
    *a = 0;
    while (*a != i) {
        chaine_three[*a] = '0';
        *a += 1;
    }
    if (i != 0)
        chaine_three = malloc(sizeof(char) * (my_strlen(first) + 2 + i));
    return (chaine_three);
}

void *revstring(char *first, char *second)
{
    my_revstr(first);
    my_revstr(second);
}

void is_carry_mul(int *retenue, int *total)
{
    int save = 0;

    *retenue = 0;
    save = *total;
    if (*total > 9) {
        *total = *total % 10;
        for (*retenue = 0; save > 9; *retenue += 1)
            save -= 10;
    }
}

char *is_extension_two_multip(char *result, char *chaine_three, int i)
{
    if (i > 0)
        extend_infmul(result, chaine_three);
    else
        my_strcpy(result, chaine_three);
    free(chaine_three);
    return (result);
}
