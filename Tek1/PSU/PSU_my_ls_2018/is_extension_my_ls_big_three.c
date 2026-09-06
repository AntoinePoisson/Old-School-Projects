/*
** EPITECH PROJECT, 2019
** is_ls_R
** File description:
** my_ls_R
*/

#include "is_ls_big_r.h"

int first_analyze_big_r(flag_t *flag, int *nbr, int *i)
{
    DIR *dirp = NULL;

    if ((dirp = is_open_directory_big_two(flag, i)) == NULL &&
        my_stat(flag->r->data, 1, flag) != 'f' &&
        my_stat(flag->r->data, 1, flag) != 'l') {
        return (display_error_message_big_r(flag));
    }
    else if (my_stat(flag->r->data, 1, flag) == 'f' ||
        my_stat(flag->r->data, 1, flag) == 'l') {
        *nbr += 1;
        return (1);
    }
    while ((readdir(dirp)) != NULL)
        *nbr += 1;
    if (close_directory_big_r(dirp) != 0)
        return (display_error_message_big_r(flag));
    return (0);
}

void display_result_big_r(flag_t *flag)
{
    int limit = flag->arg->nbr_element;

    if (flag->flag_d == 1)
        return (display_flag_d_big_r(flag));
    write(1, "\n", 1);
    my_putstr(flag->r->data);
    write(1, ":\n", 2);
    if (flag->flag_l == 1)
        return (display_flag_l_big_r(flag));
    for (int i_two = 0; i_two < limit; i_two++) {
        if (flag->arg->result[i_two][0] != '.') {
            my_putstr(flag->arg->result[i_two]);
            write(1, "\n", 1);
        }
    }
}

void display_flag_big_r(flag_t *flag, int *i)
{
    if (flag->flag_d == 1)
        return (display_flag_d(flag, i));
    if (flag->arg->nbr_direction == 1 && flag->arg->direction[0][0] == '.' &&
        flag->arg->direction[0][1] == '\0')
        my_putstr(".:\n");
    else {
        my_putstr(flag->arg->direction[flag->arg->index]);
        my_putstr(":\n");
    }
}

char *is_extension_parce_time_big_r(int *i, int i_two, char *time,
    char *stockage)
{
    int count = 0;

    *i += my_strlen(month(time, i_two)) + 1;
    stockage[*i] = ' ';
    if (my_strlen(month(time, i_two)) != 2)
        *i -= 1;
    i_two += 3;
    if (time[i_two + 1] < '0' && time[i_two + 1] > '9')
        i_two += 1;
    if (time[i_two + 1] < '0' && time[i_two + 1] > '9')
        i_two += 1;
    for (; count < 2 || time[i_two] != ' '; i_two++, *i += 1) {
        if (time[i_two] == ':') {
            stockage[*i] = ' ';
            count++;
        }
        else
            stockage[*i] = time[i_two];
    }
    return (stockage);
}

char *parce_time_big_r(int *i, char *stockage, char *time)
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
    return (is_extension_parce_time_big_r(i, i_two, time, stockage));
}
