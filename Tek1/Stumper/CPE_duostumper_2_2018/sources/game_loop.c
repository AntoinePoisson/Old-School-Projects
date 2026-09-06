/*
** EPITECH PROJECT, 2019
** Boggle
** File description:
** game loop if there is no -w
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_struct.h"
#include "my_lib.h"

int is_algo(variable_t *);
void display_tab(variable_t *);

int verify_input(char *line, variable_t *var)
{
    int size = my_strlen(line);

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] < 'a' && line[i] > 'z')
            return (my_puterror("Invalid input\n"));
    var->arg_w = malloc(sizeof(char) * size + 1);
    var->arg_w = my_strcpy(var->arg_w, line);
    return (0);
}

int game_with_w_flag(variable_t *var)
{
    if (is_algo(var) == 1)
        display_tab(var);
    else
        printf("The word \"%s\" is not in the grid.\n", var->arg_w);
    return (0);
}

int game_loop(variable_t *var)
{
    char *line = NULL;
    size_t len;
    ssize_t nread;

    if (var->flag_w == 1) {
        game_with_w_flag(var);
        return (0);
    }
    display_tab(var);
    while (1) {
        my_putstr("> ");
        if ((nread = getline(&line, &len, stdin)) == -1)
            return (0);
        if (verify_input(line, var) != 84) {
            if (is_algo(var) == 1) {
                break;
            } else
                printf("The word \"%s\" is not in the grid.\n", var->arg_w);
        }
    }
    return (0);
}
