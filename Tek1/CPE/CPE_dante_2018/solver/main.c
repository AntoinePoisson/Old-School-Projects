/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my_lib.h"
#include "get_next_line.h"
#include "my_struct.h"
#include "unistd.h"
#include "my_lib.h"

int check_error(int ac, char *av[], variable_t *var);
int backtracker(variable_t *var, int x, int y);
int find_way(variable_t *var, int x, int y);

static int check_error_map(variable_t *var)
{
    int size_x = strlen(var->map[0]);
    int size_y = 0;

    for (int i = 0; var->map[i] != NULL; i++, size_y++) {
        if (my_strlen(var->map[i]) != size_x)
            return (84);
    }
    var->size_x = size_x - 1;
    var->size_y = size_y - 1;
    return (0);
}

int add_tab(variable_t *var, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer = my_malloc(var->size_file + 3);

    if (fd == -1 || buffer == NULL)
        return (my_puterror("Cannot Open File.\n"));
    if (read(fd, buffer, var->size_file + 1) == -1 || my_strlen(buffer) == 0)
        return (my_puterror("Error Read File.\n"));
    if ((var->map = my_str_to_word_array(buffer)) == NULL)
        return (84);
    return (0);
}

static void is_extenson_main(variable_t *var, int i)
{
    for (int i2 = 0; var->map[i][i2]; i2++)
        if (var->map[i][i2] == '0')
            var->map[i][i2] = '*';
}

int main(int ac, char *av[])
{
    variable_t *var = malloc(sizeof(variable_t));

    if (check_error(ac, av, var) != 0)
        return (84);
    if (add_tab(var, av) == 84 || check_error_map(var) == 84)
        return (84);
    var->list = NULL;
    if (var->map[0][0] == 'X' || backtracker(var, 0, 0) == 84) {
        my_putstr("no solution found");
        return (0);
    }
    for (int i = 0; var->map[i]; i++) {
        is_extenson_main(var, i);
        write(1, var->map[i], strlen(var->map[i]));
        if (var->map[i + 1] != NULL)
            write(1, "\n", 1);
    }
    return (0);
}
