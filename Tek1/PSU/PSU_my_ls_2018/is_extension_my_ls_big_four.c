/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

char *is_extension_sort_time_big_r(flag_t *flag, int i)
{
    struct stat sb;
    char *time;
    char *stockage;
    int i_two = 0;
    char *link = link_directory(flag->arg->result[i], 5, flag);

    if (stat(link, &sb) == -1) {
        perror("lstat");
        exit(84);
    }
    time = ctime(&sb.st_mtime);
    stockage = malloc(sizeof(char) * my_strlen(time));
    return (parce_time_big_r(&i_two, stockage, time));
}

int my_strcmp_time_big_r(flag_t *flag, int i_two, int i)
{
    char *nbr_one = is_extension_sort_time_big_r(flag, i_two - 1);
    char *nbr_two = is_extension_sort_time_big_r(flag, i);

    return (my_strcmp(nbr_one, nbr_two));
}

void sort_time_big_r(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 1; i < limit; i++)
        for (int i_two = 0; i_two < limit; i_two++)
            if (my_strcmp_time_big_r(flag, i, i_two) > 0) {
                save = flag->arg->result[i_two];
                flag->arg->result[i_two] = flag->arg->result[i - 1];
                flag->arg->result[i - 1] = save;
            }
    for (int i = 0; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp_time_big_r(flag, i_two, i) < 0) {
                save = flag->arg->result[i];
                flag->arg->result[i] = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = save;
            }
}

void sort_time_rev_big_r(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;


    for (int i = 1; i < limit; i++)
        for (int i_two = 0; i_two < limit; i_two++)
            if (my_strcmp_time_big_r(flag, i, i_two) < 0) {
                save = flag->arg->result[i_two];
                flag->arg->result[i_two] = flag->arg->result[i - 1];
                flag->arg->result[i - 1] = save;
            }
    for (int i = 0; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp_time_big_r(flag, i_two, i) > 0) {
                save = flag->arg->result[i];
                flag->arg->result[i] = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = save;
            }
}

void sort_alphabetically_big_r(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 1; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp(flag->arg->result[i_two - 1],
                flag->arg->result[i]) > 0) {
                save = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = flag->arg->result[i];
                flag->arg->result[i] = save;
            }
}