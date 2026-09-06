/*
** EPITECH PROJECT, 2019
** my_struct.c
** File description:
** all headers of my struct
*/

#ifndef MY_PUT_H
#define MY_PUT_H

typedef struct list_s
{
    int x;
    int y;
    struct list_s *next;
} list_t;

typedef struct variable_s
{
    char **map;
    list_t *list;
    int size_x;
    int size_y;
    int split_x;
    int split_y;
    int nbr_split_x;
    int nbr_split_y;
} variable_t;

#endif
