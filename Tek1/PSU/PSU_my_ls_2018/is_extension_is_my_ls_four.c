/*
** EPITECH PROJECT, 2019
** is_my_ls
** File description:
** is_extension_is_my_ls
*/

#include "is_my_ls.h"

char *parce_time(int *i, char *stockage, char *time)
{
    int i_two = my_strlen(time) - 2;

    for (; time[i_two] != ' '; i_two--, *i += 1)
        stockage[*i] = time[i_two];
    stockage[*i] = '\0';
    my_revstr(stockage);
    for (i_two = 0; time[i_two - 1] != ' '; i_two++);
    stockage[*i] = ' ';
    if (my_strlen(month(time, i_two)) == 1) {
        *i += 1;
        stockage[*i] = ' ';
        *i += 1;
    }
    my_strcat(stockage, month(time, i_two));
    return (is_extension_parce_time(i, stockage, time, i_two));
}

char *is_extension_sort_time(flag_t *flag, int i)
{
    struct stat sb;
    char *time;
    char *stockage;
    int i_two = 0;
    char *link = link_directory(flag->arg->result[i], 4, flag);

    if (stat(link, &sb) == -1) {
        perror("lstat");
        exit(84);
    }
    time = ctime(&sb.st_mtime);
    stockage = malloc(sizeof(char) * my_strlen(time));
    return (parce_time(&i_two, stockage, time));
}

int my_strcmp_time(flag_t *flag, int i_two, int i)
{
    char *nbr_one = is_extension_sort_time(flag, i_two - 1);
    char *nbr_two = is_extension_sort_time(flag, i);

    if (my_strcmp(nbr_one, nbr_two) == 0)
        return (my_strcmp(flag->arg->result[i_two - 1], flag->arg->result[i]));
    return (my_strcmp(nbr_one, nbr_two));
}

void sort_time(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 1; i < limit; i++)
        for (int i_two = 0; i_two < limit; i_two++)
            if (my_strcmp_time(flag, i, i_two) > 0) {
                save = flag->arg->result[i_two];
                flag->arg->result[i_two] = flag->arg->result[i - 1];
                flag->arg->result[i - 1] = save;
            }
    for (int i = 0; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp_time(flag, i_two, i) < 0) {
                save = flag->arg->result[i];
                flag->arg->result[i] = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = save;
            }
}

void sort_time_rev(flag_t *flag)
{
    int limit = flag->arg->nbr_element;
    char *save = NULL;

    for (int i = 1; i < limit; i++)
        for (int i_two = 0; i_two < limit; i_two++)
            if (my_strcmp_time(flag, i, i_two) < 0) {
                save = flag->arg->result[i_two];
                flag->arg->result[i_two] = flag->arg->result[i - 1];
                flag->arg->result[i - 1] = save;
            }
    for (int i = 0; i < limit; i++)
        for (int i_two = 1; i_two < limit; i_two++)
            if (my_strcmp_time(flag, i_two, i) > 0) {
                save = flag->arg->result[i];
                flag->arg->result[i] = flag->arg->result[i_two - 1];
                flag->arg->result[i_two - 1] = save;
            }
}