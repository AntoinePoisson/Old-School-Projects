/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function of cat
*/

int check_error (int ac, char *av[]);
int cat (int ac, char *av[], int a);

int main(int ac, char *av[])
{
    int i = 1;
    int a = 0;

    if (check_error(ac, av) != 1)
        return (84);
    while (i != ac) {
        if (cat(ac, av, i) == 84)
            a = 84;
        i++;
    }
    return (a);
}
