/*
** EPITECH PROJECT, 2019
** is_turn_ai.c
** File description:
** is_turn_ai
*/

#include <my_struct.h>
#include "my_lib.h"

void is_init_pow(var_t *var);
void is_basic_ai(var_t *var);
int balance_nbr(var_t *var, int nbr_remove, int value, int cas);
int spe_cas(var_t *var, int line, int *nbr_remove);
int ai_check_value(var_t *var, int nbr_remove, int line);
int calcul_limit_pow(var_t *var);
void calcul_pow_two(var_t *var);
int pow_select(var_t *var, int i);

void is_extension_delete_stick(var_t *var, int nbr_remove, int line)
{
    var->display = 0;
    my_putstr("AI removed ");
    my_put_nbr(nbr_remove);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putstr("\n");
}

void delete_stick(var_t *var, int line, int value)
{
    int nbr_remove = 0;
    int nbr = my_compute_power_rec(2, value);

    nbr = balance_nbr(var, nbr, value, 0);
    if (spe_cas(var, line, &nbr_remove) == 0) {
        if (ai_check_value(var, nbr, line) == 1)
            return;
        for (int i = var->size + 2; i > 0 && nbr_remove != nbr; i--) {
            if (((nbr_remove + 1 == nbr && balance_nbr(var, nbr, value, -1)
                == -42) && nbr_remove != 0) || ((nbr_remove + 1 == nbr &&
                balance_nbr(var, nbr, value, -1) == -43 && nbr_remove != 0)))
                break;
            if (var->game_board[line][i] == '|') {
                var->game_board[line][i] = ' ';
                nbr_remove++;
            }
        }
    }
    is_extension_delete_stick(var, nbr_remove, line);
    return;
}

int remove_ai(var_t *var, int nbr_remove, int nbr_stick)
{
    static int limit = -1;

    if (limit == -1)
        limit = calcul_limit_pow(var);
    for (int i = 1; i <= var->nbr_line; i++, nbr_stick = 0) {
        for (int i_two = 0; i_two <= var->size + 1; i_two++)
            if (var->game_board[i][i_two] == '|')
                nbr_stick++;
        while (nbr_stick > 0)
            for (int i_three = limit; i_three > -1; i_three--)
                if (nbr_stick >= my_compute_power_rec(2, i_three)) {
                    nbr_stick -= my_compute_power_rec(2, i_three);
                    if (i_three == nbr_remove) {
                        delete_stick(var, i, nbr_remove);
                        return (1);
                    }
                    i_three++;
                }
    }
    return (0);
}

void is_turn_ai(var_t *var)
{
    int nbr_stick = 0;

    var->display = 1;
    calcul_pow_two(var);
    for (int i = 7; i != -1; i--)
        if (pow_select(var, i) % 2 != 0)
            if (remove_ai(var, i, nbr_stick) == 1) {
                if (var->display == 0)
                    return;
                else
                    break;
            }
    is_basic_ai(var);
}
