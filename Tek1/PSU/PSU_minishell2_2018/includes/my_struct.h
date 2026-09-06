/*
** EPITECH PROJECT, 2019
** my_struct.h
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

typedef struct tree_s
{
    int operator;
    char *data;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct variable_s
{
    struct tree_s *tree;
    char **alias;
    char **path;
    char **env;
    char **arg_two_d;
    char *arg;
    char *pwd;
    char *prev_pwd;
    int quit;
    int value_return;
} variable_t;

#endif
