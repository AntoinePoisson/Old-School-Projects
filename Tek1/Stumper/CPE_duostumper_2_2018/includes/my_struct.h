/*
** EPITECH PROJECT, 2019
** my_struct.c
** File description:
** all headers of my struct
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif

#ifndef EXIT_ERROR
# define EXIT_ERROR 84
#endif

typedef struct node_s
{
    int x;
    int y;
    struct node_s *next;
} node_t;

typedef struct variable_s
{
    int flag_s;
    int flag_g;
    int flag_w;
    char **tab;
    char *arg_g;
    char *arg_w;
    node_t *list;
} variable_t;

#endif
