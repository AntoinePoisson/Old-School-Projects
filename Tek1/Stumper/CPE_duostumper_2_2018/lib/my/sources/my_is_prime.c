/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** D5, give the prime of number
*/

int my_is_prime(int nb)
{
    int i = 1;
    int continuer = 0;

    if (nb < 2)
        return (0);
    for (i = 1; i <= nb; i++) {
        if ((nb % i) == 0)
            continuer++;
    }
    if (continuer == 2)
        return (1);
    return (0);
}
