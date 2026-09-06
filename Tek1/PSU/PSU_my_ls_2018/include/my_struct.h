/*
** EPITECH PROJECT, 2018
** my_struct
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

typedef struct direction_s
{
    int index;
    char **direction;
    int nbr_direction;
    int nbr_element;
    char **result;
} direction_t;

typedef struct recursive_s
{
    char *data;
    struct recursive_s *next;
} recursive_t;

typedef struct flag_s
{
    int flag_l;
    int flag_big_r;
    int flag_d;
    int flag_r;
    int flag_t;
    int nbr_flag;
    int nbr_recursive;
    struct recursive_s *r;
    struct direction_s *arg;
} flag_t;

#endif
