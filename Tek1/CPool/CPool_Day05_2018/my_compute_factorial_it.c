/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** Write an iterative function that returns the factorial.
*/

int my_compute_factorial_it(int nb)
{
    int i = 1;
    int a = nb;

    for (a = nb; a > 1; a = a - 1)
        i = i * a;
    if (nb == 1)
        return (1);
    if (nb < 0 || nb > 12)
        return (0);
    return(i);
}
