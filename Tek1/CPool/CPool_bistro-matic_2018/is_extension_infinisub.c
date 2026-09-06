/*
** EPITECH PROJECT, 2018
** is_extension_infinsous.c
** File description:
** extension of infinite soustraction
*/

#include "./include/my.h"

int is_extension_retenue_sub(int *r, int *retenue)
{
    *retenue = 0;
    if (*r > 9) {
        *r = *r - 10;
        *retenue = 1;
    }
    if (*r < 0) {
        *r += 10;
        *retenue = 1;
    }
    if (*r < 0)
        *r *= -1;
    return (*r);
}

char *is_infin_next(int i, int r, char string_three[], int negative_case)
{
    if (negative_case == 0) {
        string_three[i] = '-';
        i++;
    }
    return (selection_sub(string_three, r, i, negative_case));
}

void is_reverser_str(char *first, char *second)
{
    my_revstr(first);
    my_revstr(second);
}

void is_case_end_ft(char *first, int i, int *end_ft)
{
    if (first[i] == '\0')
        *end_ft = 0;
}

void is_case_end_sd(char *second, int i, int *end_sd)
{
    if (second[i] == '\0')
        *end_sd = 0;
}
