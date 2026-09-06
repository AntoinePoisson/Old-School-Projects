/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** Write an iterative function that returns the first argument raised to the power p, where p is the second argument.
*/

int my_compute_power_it(int nb, int p)
{
    int i = 1;
    int a = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    for (i = 1; i != p; i = i + 1)
        nb = nb * a;
    return (nb);
}
