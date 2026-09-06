/*
** EPITECH PROJECT, 2020
** funct_ptr.c
** File description:
** daytwo
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "func_ptr_enum.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; str && i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str && str[i]; i++)
        printf("%c", toupper(str[i]));
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*tab[4])(const char *) = {print_normal, print_reverse,
        print_upper, print_42};
    tab[action](str);
}
