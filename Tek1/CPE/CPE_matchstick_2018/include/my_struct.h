/*
** EPITECH PROJECT, 2019
** my_struct.h
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

typedef struct pow_two_s
{
    int zero;
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
} pow_two_t;

typedef struct var_s
{
    int nbr_line;
    int nbr_remove;
    int turn;
    int size;
    char **game_board;
    int display;
    struct pow_two_s pow;
} var_t;

#endif
