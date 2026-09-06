/*
** EPITECH PROJECT, 2019
** my_alias.c
** File description:
** my_alias
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_shell.h"

static int open_and_close_alias_file(int cas)
{
    int value_return = 0;

    if (cas == -1) {
        if ((value_return = open("./.42shrc", O_RDONLY)) == -1) {
        }
    } else {
        if ((value_return = close(cas)) == -1) {
        }
    }
    return (value_return);
}

static int find_size_file(void)
{
    int fd = open_and_close_alias_file(-1);
    int size = 0;
    char *result = NULL;

    if (fd == -1)
        return (0);
    for (; (result = get_next_line(fd)) != NULL; size++)
        free(result);
    if (open_and_close_alias_file(fd) == -1)
        return (0);
    return (size);
}

static char **fill_alias(variable_t *var, char **alias, int size, int fd)
{
    char *result = NULL;
    int i = 0;

    for (; ((result = get_next_line(fd)) != NULL) && i <= size;) {
        if (my_strncmp(result, "alias ", 5) == 0) {
            if ((alias[i] = rework_line(result)) == NULL)
                return (NULL);
            i++;
        }
        free(result);
    }
    alias[i] = NULL;
    for (i = 0; alias[i] != NULL; i++);
    if ((var->alias = malloc(sizeof(char *) * (i + 1))) == NULL)
        return (NULL);
    return (alias);
}

char *control_alias(variable_t *var, char *arg)
{
    char *result = NULL;

    while ((arg && arg[0] && arg[0] == ' ') ||
        (arg && arg[0] && arg[0] == '\t'))
        arg = &arg[1];
    if (var->alias != NULL && var->alias[0] != NULL &&
        arg != NULL && arg[0] != '\0')
        for (int i = 0; var->alias[i] != NULL; i++) {
            if (check_alias(var->alias[i], arg) == 0) {
                result = cpy_alias(var->alias[i], arg);
                return (result);
            }
        }
    return (arg);
}

int is_initialization_alias(variable_t *var)
{
    int size = find_size_file();
    int fd = open_and_close_alias_file(-1);
    char **alias = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    if (fd == -1 || size == 0 || alias == NULL)
        return (84);
    if (fill_alias(var, alias, size, fd) == NULL)
        return (84);
    if (open_and_close_alias_file(fd) == -1)
        return (84);
    for (; alias != NULL && alias[i] != NULL; i++)
        var->alias[i] = alias[i];
    var->alias[i] = NULL;
    free(alias);
    return (0);
}
