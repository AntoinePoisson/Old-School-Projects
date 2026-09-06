/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** rush 2 etape 4
*/

int count_l_step_by_step(int ac, char ** av, char c)
{
    int i = 0;
    int i2 = 0;
    char q = 0;

    if (c >= 65 && c <= 90)
        q = c + 32;
    else if (c >= 90 && c <= 122)
        q = c - 32;
    while (av[1][i] != '\0') {
        if (av[1][i] == c || av[1][i] == q)
            i2++;
        i++;
    }
    return (i2);
}
