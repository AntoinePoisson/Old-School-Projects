/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of push swap
*/

#include "main.h"

int main(int ac, char *av[])
{
    control_list_t *l_a = NULL;
    control_list_t *l_b = NULL;
    char *size_max;

    if (check_error_two(ac) == 84)
        return (84);
    if (check_error_three(ac) == 1)
        return (0);
    l_a = create_list_control_l_a(l_a, ac, av);
    l_b = create_list_control_l_b(l_b);
    size_max = is_init(&l_a, av);
    if (size_max[0] == '-' && size_max[1] == '1' && size_max[2] == '\0')
        return (0);
    is_pushswap(&l_a, &l_b, size_max, (ac - 1));
    write(1, "sb\n", 3);
    return (0);
}
