/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** Day05 task05 my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int square = 0;
    int i = 0;

    if (nb <= 0) {
        return (0);
    }
    for (i; square != nb; i = i + 1) {
        square = i * i;
        if (i > 46340) {
            return (0);
        }
    }
    return (i-1);
    return (0);
}
