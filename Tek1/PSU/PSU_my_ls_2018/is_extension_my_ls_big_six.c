/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

char *is_extension_link_directory_five(char *directory, flag_t *flag,
    char *result, int i_two)
{
        result = malloc(sizeof(char) * (my_strlen(directory) +
            my_strlen(flag->r->data) + 3));
        if (flag->r->data[0] != '/' && flag->r->data[0] != '.' &&
            flag->r->data[1] != '\0') {
            result[0] = '.';
            result[1] = '/';
            i_two = 2;
        }
        for (int i = 0; flag->r->data[i] != '\0'; i++, i_two++)
            result[i_two] = flag->r->data[i];
        if (result[i_two - 1] != '/') {
            result[i_two] = '/';
            i_two++;
        }
        for (int i = 0; directory[i] != '\0'; i_two++, i++)
            result[i_two] = directory[i];
        result[i_two] = '\0';
    return (result);
}

char *link_directory(char *directory, int nbr, flag_t *flag)
{
    char *result = NULL;
    int i_two = 0;

    if (directory[0] == '.' && directory[1] != '/' && directory[1] != '\0' &&
        directory[0] == '/')
        return (directory);
    if (nbr == 1)
        return (is_extension_link_directory(directory, result));
    if (nbr == 2)
        return (is_extension_link_directory_two(directory, flag, result));
    if (nbr == 3)
        return (is_extension_link_directory_three(directory, flag, result,
            i_two));
    if (nbr == 4)
        return (is_extension_link_directory_four(directory, flag, result,
            i_two));
    if (nbr == 5)
        return (is_extension_link_directory_five(directory, flag, result,
            i_two));
    return (result);
}

void check_big_r_element(flag_t *flag)
{
    char *directory = NULL;
    char *link = NULL;

    for (int i = flag->arg->nbr_element - 1; i > 1; i--) {
        directory = link_directory(flag->arg->result[i], 3, flag);
        if (my_stat(flag->arg->result[i], -42, flag) == 'd' ||
            my_stat(directory, -42, flag) == 'd') {
            link = find_name(directory);
            if (link[0] != '.')
            add_element(flag, directory);
        }
    }
}

void check_big_r_elemen_two(flag_t *flag)
{
    char *directory = NULL;
    char *link = NULL;

    for (int i = flag->arg->nbr_element - 1; i > 1; i--) {
        directory = link_directory(flag->arg->result[i], 5, flag);
        if (my_stat(directory, -42, flag) == 'd') {
            link = find_name(directory);
            if (link[0] != '.')
                push(flag, directory);
        }
    }
}

void is_extension_is_ls_big_big_r(flag_t *flag)
{
    if (flag->flag_t == 1 && flag->flag_r == 0)
        sort_time_big_r(flag);
    if (flag->flag_r == 1 && flag->flag_t == 1)
        sort_time_rev_big_r(flag);
    if (flag->flag_r == 1 && flag->flag_t == 0)
        sort_alphabetically_rev_big_r(flag);
    if (flag->flag_r == 0 && flag->flag_t == 0)
        sort_alphabetically_big_r(flag);
}