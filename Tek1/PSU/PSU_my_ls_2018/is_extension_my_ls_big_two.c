/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

DIR *is_open_directory_big_two(flag_t *flag, int *nbr)
{
    DIR *result = opendir(flag->r->data);

    flag->arg->index = *nbr;
    return (result);
}

DIR *is_open_directory_big(flag_t *flag, int *i)
{
    DIR *result = opendir(flag->r->data);

    flag->arg->index = *i;
    return (result);
}

int close_directory_big_r(DIR *dirp)
{
    int value = 0;

    if ((value = closedir(dirp)) != 0)
        return (84);
    return (value);
}

void save_result_big_r(struct dirent *result, flag_t *flag, int count)
{
    int i_two = 0;

    flag->arg->result[count] = malloc(sizeof(char) *
        my_strlen(result->d_name) + 1);
    for (; result->d_name[i_two] != '\0'; i_two++)
        flag->arg->result[count][i_two] = result->d_name[i_two];
    flag->arg->result[count][i_two] = '\0';
}

int directory_and_file_big_r(flag_t *flag, int *i)
{
    struct dirent *result = malloc(sizeof(*result));
    DIR *dirp = NULL;

    if ((dirp = is_open_directory_big(flag, i)) == NULL &&
        my_stat(flag->r->data, 1, flag) != 'f' &&
        my_stat(flag->r->data, 1, flag) != 'l')
        return (display_error_message_big_r(flag));
    else if (my_stat(flag->r->data, 1, flag) == 'f' ||
        my_stat(flag->r->data, 1, flag) == 'l')
        return (display_file_big_r(flag));
    for (int count = 0; (result = readdir(dirp)) != NULL; count++)
        save_result_big_r(result, flag, count);
    if (close_directory_big_r(dirp) != 0)
        return (display_error_message_big_r(flag));
    return (0);
}
