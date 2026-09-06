/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

void sort_alphabetically_rev_big_r(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 1; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp(flag->arg->result[i_two - 1],
                flag->arg->result[i]) < 0) {
                save = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = flag->arg->result[i];
                flag->arg->result[i] = save;
            }
}

char *is_extension_link_directory(char *directory, char *result)
{
    int i_two = 0;
    int i_three = 0;

    result = malloc(sizeof(char) * my_strlen(directory) + 4);
    if (directory[0] != '/' &&
            directory[0] != '.' &&
            directory[1] != '\0') {
            result[0] = '.';
            result[1] = '/';
            i_three = 2;
        }
        for (; directory[i_two] != '\0'; i_two++, i_three++) {
            result[i_three] = directory[i_two];
            result[i_three + 1] = '\0';
        }
    return (result);
}

char *is_extension_link_directory_two(char *directory, flag_t *flag,
    char *result)
{
    int i_two = 0;

        result = malloc(sizeof(char) * (my_strlen(directory) +
            my_strlen(flag->r->data) + 3));
        for (int i = 0; flag->r->data[i] != '\0'; i++, i_two++)
            result[i_two] = flag->r->data[i];
        if (result[i_two - 1] != '/') {
            result[i_two] = '/';
            i_two++;
        }
        for (int i = 0; directory[i] != '\0'; i++, i_two++)
            result[i_two] = directory[i];
        result[i_two] = '\0';
    return (result);
}

char *is_extension_link_directory_three(char *directory, flag_t *flag,
    char *result, int i_two)
{
        result = malloc(sizeof(char) * (my_strlen(directory) +
            my_strlen(flag->arg->direction[flag->arg->index]) + 3));
        if (flag->arg->direction[flag->arg->index][0] != '/' &&
            flag->arg->direction[flag->arg->index][0] != '.' &&
            flag->arg->direction[flag->arg->index][1] != '\0') {
            result[0] = '.';
            result[1] = '/';
            i_two = 2;
        }
        for (int i = 0; flag->arg->direction[flag->arg->index][i]
            != '\0'; i++, i_two++)
            result[i_two] = flag->arg->direction[flag->arg->index][i];
        if (result[i_two - 1] != '/') {
            result[i_two] = '/';
            i_two++;
        }
        for (int i = 0; directory[i] != '\0'; i_two++, i++)
            result[i_two] = directory[i];
        result[i_two] = '\0';
    return (result);
}

char *is_extension_link_directory_four(char *directory, flag_t *flag,
    char *result, int i_two)
{
        result = malloc(sizeof(char) * (my_strlen(directory) +
            my_strlen(flag->arg->direction[flag->arg->index]) + 3));
        if (flag->arg->direction[flag->arg->index][0] != '/' &&
            flag->arg->direction[flag->arg->index][0] != '.' &&
            flag->arg->direction[flag->arg->index][1] != '\0') {
            result[0] = '.';
            result[1] = '/';
            i_two = 2;
        }
        for (int i = 0; flag->arg->direction[flag->arg->index][i]
            != '\0'; i++, i_two++)
            result[i_two] = flag->arg->direction[flag->arg->index][i];
        if (result[i_two - 1] != '/') {
            result[i_two] = '/';
            i_two++;
        }
        for (int i = 0; directory[i] != '\0'; i_two++, i++)
            result[i_two] = directory[i];
        result[i_two] = '\0';
    return (result);
}