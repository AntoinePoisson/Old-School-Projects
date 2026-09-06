/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** Write a recursive function that returns the factorial.
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return (1);
    if (nb < 0 || nb > 12)
        return (0);
    if (nb > 1)
        return (nb * my_compute_factorial_rec(nb - 1));
}
