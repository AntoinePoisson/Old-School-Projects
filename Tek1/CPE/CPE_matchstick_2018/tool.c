/*
** EPITECH PROJECT, 2019
** tool.c
** File description:
** tool
*/

#include <stddef.h>
#include "get_next_line.h"
#include "my_lib.h"
#include "my_struct.h"

char *get_next_line(int fd);
int control_nbr_remove_stick(var_t *var, char *data, int cas);
int check_end(var_t *var);
int remove_stick(var_t *var, int line, int nbr);
int check_righ_chose_line(var_t *var, int line);

int is_extension_take_information(int *cas, int *nbr_line, char *data)
{
    *cas = 0;
    my_putstr("Player removed ");
    my_put_nbr(my_getnbr(data));
    my_putstr(" match(es) from line ");
    my_put_nbr(*nbr_line);
    my_putstr("\n");
    *nbr_line = 0;
    return (0);
}

void is_extension_take_information_two(int cas)
{
    if (cas == 0)
        my_putstr("Line: ");
    else
        my_putstr("Matches: ");
}

void is_ext_take_info(int *cas, int *nbr_line)
{
    *cas = 0;
    *nbr_line = 0;
}

int is_ext_take_info_two(int *cas, int *nbr_line, char *data)
{
    *cas = 1;
    *nbr_line = my_getnbr(data);
    return (1);
}

int take_information(var_t *var)
{
    static int cas = 0;
    static int nbr_line = 0;
    char *data = NULL;

    is_extension_take_information_two(cas);
    if ((data = get_next_line(0)) == NULL)
        return (1);
    if (my_strcmp(data, "a3EOF36qch7zk87nAZuaA4+") == 0)
        return (-1);
    if (cas == 0 && control_nbr_remove_stick(var, data, 0) == 0 &&
        check_righ_chose_line(var, my_getnbr(data)) == 1)
        return (is_ext_take_info_two(&cas, &nbr_line, data));
    if (cas == 1) {
        if (control_nbr_remove_stick(var, data, 1) == 0 &&
            remove_stick(var, nbr_line, my_getnbr(data)) != 1)
            return (is_extension_take_information(&cas, &nbr_line, data));
        else
            is_ext_take_info(&cas, &nbr_line);
    }
    return (1);
}
