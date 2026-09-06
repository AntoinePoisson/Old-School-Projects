/*
** EPITECH PROJECT, 2019
** is_extension_ai_two.c
** File description:
** is_extension_ai_two.c
*/

#include <my_struct.h>
#include "my_lib.h"

void is_init_pow(var_t *var);

int calcul_limit_pow(var_t *var)
{
    int limit = 0;

    for (int i = 0; 1; i++) {
        if (var->nbr_remove >= my_compute_power_rec(2, i))
            limit = i;
        else
            break;
    }
    return (limit);
}

void add_pow(var_t *var, int nbr)
{
    if (nbr == 0)
        var->pow.zero += 1;
    if (nbr == 1)
        var->pow.one += 1;
    if (nbr == 2)
        var->pow.two += 1;
    if (nbr == 3)
        var->pow.three += 1;
    if (nbr == 4)
        var->pow.four += 1;
    if (nbr == 5)
        var->pow.five += 1;
    if (nbr == 6)
        var->pow.six += 1;
    if (nbr == 7)
        var->pow.seven += 1;
}

void find_pow(var_t *var, int nbr_stick)
{
    static int limit = -1;

    if (limit == -1)
        limit = calcul_limit_pow(var);
    while (nbr_stick > 0) {
        for (int i = limit; i > -1; i--)
            if (nbr_stick >= my_compute_power_rec(2, i)) {
                nbr_stick -= my_compute_power_rec(2, i);
                add_pow(var, i);
                i++;
            }
    }
}

void calcul_pow_two(var_t *var)
{
    int nbr_stick = 0;

    is_init_pow(var);
    for (int i = 1; i <= var->nbr_line; i++, nbr_stick = 0) {
        for (int i_two = 0; i_two <= var->size + 1; i_two++)
            if (var->game_board[i][i_two] == '|')
                nbr_stick++;
        find_pow(var, nbr_stick);
    }
}

int pow_select(var_t *var, int i)
{
    if (i == 0)
        return (var->pow.zero);
    if (i == 1)
        return (var->pow.one);
    if (i == 2)
        return (var->pow.two);
    if (i == 3)
        return (var->pow.three);
    if (i == 4)
        return (var->pow.four);
    if (i == 5)
        return (var->pow.five);
    if (i == 6)
        return (var->pow.six);
    if (i == 7)
        return (var->pow.seven);
    return (-1);
}