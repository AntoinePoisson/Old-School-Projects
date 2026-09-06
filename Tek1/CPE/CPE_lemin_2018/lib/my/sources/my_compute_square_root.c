/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** D5, a function that returns the square root.
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    int square = 0;

    if (nb > 46340 || nb < 0)
        return (84);
    if (nb == 0)
        return (0);
    for (i = 0; square < nb; i++)
        square = i * i;
    i--;
    if (nb == (i * i))
        return (i);
    else
        return (0);
}
