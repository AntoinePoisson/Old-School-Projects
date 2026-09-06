/*
** EPITECH PROJECT, 2019
** my_struct.h
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

typedef struct var_s
{
    char **alias;
    char **path;
    char **env;
    char **arg_two_d;
    char *arg;
    char *pwd;
    char *prev_pwd;
    int quit;
} var_t;

#endif
