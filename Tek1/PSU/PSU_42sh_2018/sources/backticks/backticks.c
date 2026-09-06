/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** backticks.c
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "my_shell.h"

char *test(int *i, char **array)
{
    char *str = NULL;

    if (my_strcmp(str, "`") == 0 || my_strcmp(array[*i], "`") == 0) {
        str = my_strcat(str, array[*i]);
        *i += 1;
    }
    for (; array[*i] != NULL &&
        my_str_finish_with_backtick(array[*i]) == false; *i += 1) {
        if (my_strcmp(str, "`") == 0 || my_strcmp(array[*i], "`") == 0)
            str = my_strcat(str, array[*i]);
        else
            str = my_strcat_with_char(str, array[*i], ' ');
    }
    if (my_str_finish_with_backtick(array[*i]) == true) {
        if (my_strcmp(str, "`") == 0 || my_strcmp(array[*i], "`") == 0)
            str = my_strcat(str, array[*i]);
        else
            str = my_strcat_with_char(str, array[*i], ' ');
    }
    return (str);
}

char **new_array(char **array)
{
    char **new_array = NULL;

    if (array == NULL)
        return (NULL);
    for (int i = 0; array[i]; i++) {
        if (my_str_starts_with_backtick(array[i]) == true)
            new_array = my_realloc_array(new_array, test(&i, array));
        else
            new_array = my_realloc_array(new_array, array[i]);
    }
    free_array(array);
    return (new_array);
}

char *replace_backslash_n_with_spaces(char *str)
{
    char *new_str = my_strdup(str);

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        if (new_str[i] == '\n')
            new_str[i] = ' ';
    return (new_str);
}

char *get_str_file(variable_t *var, int fd, char *array_i)
{
    char *str_file = NULL;

    create_file("./.temp", &fd);
    if (exec_backticks(var,
        get_str_between_backticks(array_i), fd) == 1)
        return (NULL);
    str_file = replace_backslash_n_with_spaces(file_to_str("./.temp"));
    remove("./.temp");
    return (str_file);
}

char *backticks(char *str, variable_t *var)
{
    int fd = 0;
    char *new_str = NULL;
    char **array = NULL;

    if (nb_backticks_is_even(str) == false) {
        my_puterror("Unmatched '`'.\n");
        return (NULL);
    }
    array = my_str_to_word_array(str);
    if (array != NULL)
        for (int i = 0; array[i]; i++)
            array[i] = clean_str(array[i]);
    array = new_array(array);
    for (int i = 0; array[i]; i++)
        if (my_str_has_backtick(array[i]) == true)
            array[i] = get_str_file(var, fd, array[i]);
    for (int i = 0; array[i]; i++)
        new_str = my_strcat_with_char(new_str, array[i], ' ');
    return (new_str);
}
