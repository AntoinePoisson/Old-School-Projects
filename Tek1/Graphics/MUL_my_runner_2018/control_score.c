/*
** EPITECH PROJECT, 2018
** control_score
** File description:
** control_score
*/

#include "struct.h"

int compare_score(int score, int level, int bird);
int write_file(char *score, char *level, char *bird);
char *my_itoa(int, int);

void control_score(variable_t *sf)
{
    char *score = my_itoa(sf->var_norm.score, 0);
    char *level = my_itoa(sf->var_norm.level, 0);
    char *bird = my_itoa(sf->var_norm.bird_mode, 0);

    if (compare_score(sf->var_norm.score, sf->var_norm.level - 1,
        sf->var_norm.bird_mode) != 0)
        write_file(score, level, bird);
}
