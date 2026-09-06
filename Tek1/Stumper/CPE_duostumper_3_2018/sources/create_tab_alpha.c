/*
** EPITECH PROJECT, 2019
** create_tab_alpha.c
** File description:
** create_tab_alpha
*/

#include <stdlib.h>
#include "my_lib.h"

char **create_tab_alpha(void)
{
    int i_two = 1;
    char **str = malloc(sizeof(char *) * 3);

    if (str == NULL || (str[0] = my_malloc(30)) == NULL)
        return (NULL);
    str[0][0] = '0';
    for (int i = 'a'; i <= 'z'; i++, i_two++)
        str[0][i_two] = i;
    i_two = 1;
    if ((str[1] = my_malloc(30)) == NULL)
        return (NULL);
    str[1][0] = '0';
    for (int i = 'A'; i <= 'Z'; i++, i_two++)
        str[1][i_two] = i;
    return (str);
}
