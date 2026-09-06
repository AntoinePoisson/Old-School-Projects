/*
** EPITECH PROJECT, 2019
** is_my_ls
** File description:
** is_extension_is_my_ls
*/

#include "is_my_ls.h"

DIR *is_open_directory_two(flag_t *flag, int *nbr)
{
    DIR *result = opendir(flag->arg->direction[*nbr]);

    flag->arg->index = *nbr;
    return (result);
}

DIR *is_open_directory(flag_t *flag, int *i)
{
    DIR *result = opendir(flag->arg->direction[*i]);

    flag->arg->index = *i;
    return (result);
}

int close_directory(DIR *dirp)
{
    int value = 0;

    if ((value = closedir(dirp)) != 0)
        return (84);
    return (value);
}

void save_result(struct dirent *result, flag_t *flag, int count)
{
    int i_two = 0;

    flag->arg->result[count] = malloc(sizeof(char) *
        my_strlen(result->d_name) + 1);
    for (; result->d_name[i_two] != '\0'; i_two++)
        flag->arg->result[count][i_two] = result->d_name[i_two];
    flag->arg->result[count][i_two] = '\0';
}

int directory_and_file(flag_t *flag, int *i)
{
    struct dirent *result = malloc(sizeof(*result));
    DIR *dirp = NULL;

    if ((dirp = is_open_directory(flag, i)) == NULL &&
        my_stat(flag->arg->direction[*i], 1, flag) != 'f' &&
        my_stat(flag->arg->direction[*i], 1, flag) != 'l')
        return (display_error_message(flag));
    else if (my_stat(flag->arg->direction[*i], 1, flag) == 'f' ||
        my_stat(flag->arg->direction[*i], 1, flag) == 'l') {
        return (display_file(flag, i));
    }
    for (int count = 0; (result = readdir(dirp)) != NULL; count++)
        save_result(result, flag, count);
    if (close_directory(dirp) != 0)
        return (display_error_message(flag));
    return (0);
}
