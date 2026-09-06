/*
** EPITECH PROJECT, 2019
** my_struct.h
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

# include <stdbool.h>

typedef struct globing_s
{
    bool status;
    unsigned pc;
    char *name;
    struct globing_s *next;
} glob_t;

typedef struct history_s
{
    size_t index;
    char *hour;
    char *cmd;
    struct history_s *next;
} history_t;

typedef struct tree_s
{
    int operator;
    char *data;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct variable_s
{
    bool reset;
    int quit;
    int value_return;
    char *arg;
    char *pwd;
    char *prev_pwd;
    char **alias;
    char **path;
    char **env;
    char **arg_two_d;
    struct tree_s *tree;
    struct history_s *history;
} variable_t;

#endif
