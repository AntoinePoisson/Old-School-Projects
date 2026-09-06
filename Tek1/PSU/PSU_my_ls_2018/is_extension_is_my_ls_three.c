/*
** EPITECH PROJECT, 2019
** is_my_ls
** File description:
** is_extension_is_my_ls
*/

#include "is_my_ls.h"

int first_analyze(flag_t *flag, int *nbr, int *i)
{
    DIR *dirp = NULL;

    if ((dirp = is_open_directory_two(flag, i)) == NULL &&
        my_stat(flag->arg->direction[*i], 1, flag) != 'f' &&
        my_stat(flag->arg->direction[*i], 1, flag) != 'l')
        return (display_error_message(flag));
    else if (my_stat(flag->arg->direction[*i], 1, flag) == 'f' ||
        my_stat(flag->arg->direction[*i], 1, flag) == 'l') {
        *nbr += 1;
        return (1);
    }
    while ((readdir(dirp)) != NULL)
        *nbr += 1;
    if (close_directory(dirp) != 0)
        return (display_error_message(flag));
    return (0);
}

void display_result(flag_t *flag, int first, int *i)
{
    int limit = flag->arg->nbr_element;

    if (flag->flag_d == 1)
        return (display_flag_d(flag, i));
    if (first != 1)
        write(1, "\n", 1);
    if (flag->arg->nbr_direction != 1 && flag->flag_big_r == 0) {
        my_putstr(flag->arg->direction[*i]);
        write(1, ":\n", 2);
    }
    if (flag->flag_big_r == 1 && flag->flag_d == 0)
        display_flag_big_r(flag, i);
    if (flag->flag_l == 1 && flag->flag_r == 0)
        return (display_flag_l(flag));
    for (int i_two = 0; i_two < limit; i_two++) {
        if (flag->arg->result[i_two][0] != '.') {
            my_putstr(flag->arg->result[i_two]);
            write(1, "\n", 1);
        }
    }
}

char *is_extension_month(char *time, int i_two)
{
    if (time[i_two] == 'J' && time[i_two + 1] == 'u' && time[i_two + 2] == 'l')
        return ("7");
    if (time[i_two] == 'A' && time[i_two + 1] == 'u' && time[i_two + 2] == 'g')
        return ("8");
    if (time[i_two] == 'S' && time[i_two + 1] == 'e' && time[i_two + 2] == 'p')
        return ("9");
    if (time[i_two] == 'O' && time[i_two + 1] == 'c' && time[i_two + 2] == 't')
        return ("10");
    if (time[i_two] == 'N' && time[i_two + 1] == 'o' && time[i_two + 2] == 'v')
        return ("11");
    if (time[i_two] == 'D' && time[i_two + 1] == 'e' && time[i_two + 2] == 'c')
        return ("12");
    return ("0");
}

char *month(char *time, int i_two)
{
    if (time[i_two] == 'J' && time[i_two + 1] == 'a' && time[i_two + 2] == 'n')
        return ("1");
    if (time[i_two] == 'F' && time[i_two + 1] == 'e' && time[i_two + 2] == 'b')
        return ("2");
    if (time[i_two] == 'M' && time[i_two + 1] == 'a' && time[i_two + 2] == 'r')
        return ("3");
    if (time[i_two] == 'A' && time[i_two + 1] == 'p' && time[i_two + 2] == 'r')
        return ("4");
    if (time[i_two] == 'M' && time[i_two + 1] == 'a' && time[i_two + 2] == 'y')
        return ("5");
    if (time[i_two] == 'J' && time[i_two + 1] == 'u' && time[i_two + 2] == 'n')
        return ("6");
    return (is_extension_month(time, i_two));
}

char *is_extension_parce_time(int *i, char *stockage, char *time, int i_two)
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
