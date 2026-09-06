/*
** EPITECH PROJECT, 2018
** is_operator
** File description:
** is_operator
*/

int is_operator(char **av, int i)
{
    if (av[i][0] == '-' && av[i][1] == 't')
        return (1);
    if (av[i][0] == '-' && av[i][1] == 'z')
        return (2);
    if (av[i][0] == '-' && av[i][1] == 'r')
        return (3);
    if (av[i][0] == '-' && av[i][1] == 's')
        return (4);
    return (0);
}
