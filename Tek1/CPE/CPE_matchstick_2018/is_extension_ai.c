/*
** EPITECH PROJECT, 2019
** is_extension_ai.c
** File description:
** is_extension_ai.c
*/

#include <my_struct.h>
#include "my_lib.h"

void calcul_pow_two(var_t *var);
int pow_select(var_t *var, int i);

int is_extension_balance_nbr(var_t *var, int value, int cas)
{
    int count = 0;
    int nbr_tot_stick = 0;

    calcul_pow_two(var);
    if (cas == 1) {
        for (int i = 7; i > 0; i--)
            if (pow_select(var, i) != 0)
                count++;
        if (pow_select(var, value) == 1)
            count--;
    } else {
        for (int i = 1; i <= var->nbr_line; i++)
            for (int i_two = 0; i_two <= var->size + 1; i_two++)
                if (var->game_board[i][i_two] == '|')
                    nbr_tot_stick++;
        if (nbr_tot_stick != 1)
            count = 5;
    }
    return (count);
}

void is_extension_balance_nbr_two(var_t *var, int *count)
{
    for (int i = 7; i > 0; i--)
        if (pow_select(var, i) != 0)
            *count += 1;
}

int balance_nbr(var_t *var, int nbr_remove, int value, int cas)
{
    int count = 0;

    for (int i = value - 1; i > -1; i--)
        if (pow_select(var, i) % 2 != 0)
            if ((nbr_remove - my_compute_power_rec(2, i)) > 0 &&
                is_extension_balance_nbr(var, value, 1) != 0)
                nbr_remove -= my_compute_power_rec(2, i);
    if (cas == -1) {
        calcul_pow_two(var);
        is_extension_balance_nbr_two(var, &count);
        if (pow_select(var, value) == 1)
            count--;
        if ((count == 0 && (pow_select(var, 0) % 2) != 0 && nbr_remove + 1 <=
            var->nbr_remove && pow_select(var, 0) != 1))
            return (-42);
        if ((is_extension_balance_nbr(var, value, 0) == 0))
            return (-43);
    }
    return (nbr_remove);
}

int spe_cas(var_t *var, int line, int *nbr_remove)
{
    int nbr_tot_stick = 0;
    int nbr_on_line = 0;

    for (int i = 1; i <= var->nbr_line; i++)
        for (int i_two = 0; i_two <= var->size + 1; i_two++)
            if (var->game_board[i][i_two] == '|')
                nbr_tot_stick++;
    for (int i = 0; i <= var->size + 1; i++)
        if (var->game_board[line][i] == '|')
            nbr_on_line++;
    if (nbr_on_line + 1 == nbr_tot_stick && nbr_on_line <= var->nbr_remove) {
        for (int i = 0; i <= var->size + 1; i++)
            if (var->game_board[line][i] == '|')
                var->game_board[line][i] = ' ';
        *nbr_remove = nbr_on_line;
        return (1);
    }
    return (0);
}

int ai_check_value(var_t *var, int nbr_remove, int line)
{
    int count = 0;

    for (int i = 0; var->game_board[line][i] != '\0'; i++)
        if (var->game_board[line][i] == '|')
            count++;
    if (nbr_remove > count)
        return (1);
    return (0);
}