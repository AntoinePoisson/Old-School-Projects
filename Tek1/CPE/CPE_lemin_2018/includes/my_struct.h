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

typedef struct anthill_s
{
    int ant;
    int index;
} anthill_t;

typedef struct path_s
{
    int index;
    struct path_s *next;
} path_t;

typedef struct list_s
{
    char *data;
    struct list_s *next;
} list_t;

typedef struct node_s
{
    char *name;
    int posi_x;
    int posi_y;
    int ants;
    struct node_s **next;
} node_t;

typedef struct variable_s
{
    char **data_arg;
    int **tab_path;
    int **bad_path;
    struct node_s *start;
    struct node_s *end;
    struct path_s *path;
    int limit_path;
    int start_index;
    int end_index;
    int nbr_ants;
    int nbr_room;
    struct node_s **room;
} variable_t;

#endif
