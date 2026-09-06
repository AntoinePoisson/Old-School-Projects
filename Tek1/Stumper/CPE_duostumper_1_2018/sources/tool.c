/*
** EPITECH PROJECT, 2019
** tool.c
** File description:
** tool
*/

#include "my_lib.h"

int check_if_point_in_line(char *str);
int find_point_origin(int*, int*, char **);
char **fill_point(char **, int, int, int);

char **find_str(char **str, int size, char **ori)
{
    int x = 0;
    int y = 0;

    find_point_origin(&y, &x, ori);
    fill_point(str, x, y, size);
    return (str);
}
