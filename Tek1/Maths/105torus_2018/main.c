/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

int check_error(int ac, char *av[]);
void is_secant_method(char *av[]);
void is_newton_method(char *av[]);
void is_bisection_method(char *av[]);

int main(int ac, char *av[])
{
    if (check_error(ac, av) == 84)
        return (84);
    if (av[1][0] == '1')
        is_bisection_method(av);
    else if (av[1][0] == '2')
        is_newton_method(av);
    else
        is_secant_method(av);
    return (0);
}
