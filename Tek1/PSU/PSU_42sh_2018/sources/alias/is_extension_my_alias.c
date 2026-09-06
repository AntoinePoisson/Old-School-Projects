/*
** EPITECH PROJECT, 2019
** is_extension_my_alias.c
** File description:
** is_extension_my_alias
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_shell.h"

void is_extension_rework_line_(char *line, int *i, int *size)
{
    for (; line[*i] != '\0' && line[*i] == ' ' && line[*i] == '\t'; *i += 1);
    for (; line[*i] != '\0' && line[*i] != ' ' && line[*i] != '\t';
        *i += 1, *size += 1);
    for (; line[*i] != '\0' && line[*i] == ' ' && line[*i] == '\t'; *i += 1);
    for (; line[*i] != '\0'; *i += 1, *size += 1);
}

char *is_extension_rework_line(char *line)
{
    char *result = NULL;
    int size = 0;
    int i = 0;

    is_extension_rework_line_(line, &i, &size);
    if ((result = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    for (i = 0, size = 0; (line[i] != '\0' && line[i] == ' ') ||
        (line[i] != '\0' && line[i] == '\t'); i++);
    for (; (line[i] != '\0' && line[i] != ' ' &&
        line[i] != '\t') || (line[i - 1] != ' ' && line[i - 1] != '\t' &&
        line[i] != '\0'); size++, i++)
        result[size] = line[i];
    for (; (line[i] != '\0' && line[i] == ' ') || (line[i] != '\0' &&
        line[i] == '\t'); i++);
    for (; line[i] != '\0'; i++, size++)
        result[size] = line[i];
    result[size] = '\0';
    return (result);
}

char *rework_line(char *line)
{
    int i = 0;

    for (; line[i] != '\0' && line[i] != ' ' && line[i] != '\t'; i++)
        line[i] = ' ';
    for (; line[i] != '\0' && line[i] != '='; i++);
    if (line[i] == '=')
        line[i] = ' ';
    if ((line[i] != '\0' && line[i + 1] == '"') || (line[i] != '\0'
        && line[i + 1] == 39)) {
        line[i + 1] = ' ';
        for (; line[i] != '\0'; i++);
        for (; i >= 0; i--)
            if (line[i] == '"' || line[i] == 39) {
                line[i] = '\0';
                break;
            }
    }
    return (is_extension_rework_line(line));
}

char *cpy_alias(char *alias, char *arg)
{
    char *result = NULL;
    int i = 0;
    int i_two = 0;
    int i_three = 0;

    for (; alias[i] != '\0' && alias[i] != ' '; i++);
    i_three = i;
    result = malloc(sizeof(char) * ((my_strlen(alias) - i) +
        (my_strlen(arg) - i)));
    if (alias == NULL || result == NULL)
        return (NULL);
    for (i += 1; alias[i] != '\0'; i++, i_two++)
        result[i_two] = alias[i];
    for (; arg[i_three] != '\0'; i_three++, i_two++)
        result[i_two] = arg[i_three];
    result[i_two] = '\0';
    return (result);
}

int check_alias(char *alias, char *arg)
{
    int i = 0;

    for (; alias[i] != '\0'; i++) {
        if ((alias[i] == ' ' && arg[i] == ' ') || (arg[i] == '\0' &&
            alias[i] == ' ')) {
            return (0);
        }
        if (arg[i] == '\0' || alias[i] == '\0' || alias[i] != arg[i]) {
            break;
        }
    }
    return (1);
}
