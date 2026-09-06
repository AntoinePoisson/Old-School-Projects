/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

int check_error(int ac, char *av[]);

int main(int ac, char *av[])
{
    if (check_error(ac, av) != 0)
        return (84);
    return (0);
}
