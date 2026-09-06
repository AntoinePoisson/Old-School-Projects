/*
** EPITECH PROJECT, 2019
** analyze_chara
** File description:
** analyze_charac
*/

#include "my_lib.h"

int analyze_chara(int base, char chara)
{
    if (chara == '\t')
        return (0);
    if ((chara) == base)
        return (1);
    if ((chara + 32) == base || (chara - 32) == base)
        return (1);
    if ((chara ) == base + 32 || (chara) == base - 32)
        return (1);
    return (0);
}

char **destroy_ligne(char **tab, int posi)
{
    my_putstr(tab[posi]);
    tab[posi][0] = '\0';
    return (tab);
}
