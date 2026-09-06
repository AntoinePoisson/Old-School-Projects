/*
** EPITECH PROJECT, 2020
** funct_ptr.h
** File description:
** funct_ptr.h
*/

#ifndef PTR_H
# define PTR_H

typedef enum action_e
{
    PRINT_NORMAL,
    PRINT_REVERSE,
    PRINT_UPPER,
    PRINT_42
} action_t;

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

#endif