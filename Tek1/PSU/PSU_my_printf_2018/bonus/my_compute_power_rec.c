/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** D5, an recursive function, who can calcul power
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 1)
        return (nb * my_compute_power_rec(nb, p - 1));
    return (0);
}
