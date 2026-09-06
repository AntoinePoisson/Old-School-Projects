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
    int cas;
    struct list_s *next;
} list_t;

typedef struct variable_s
{
    char **map;
    list_t *list;
    int size_x;
    int size_y;
    long unsigned size_file;
} variable_t;

#endif
