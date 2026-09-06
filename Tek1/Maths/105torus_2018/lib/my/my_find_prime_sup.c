/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** D5, find the first prime number sup
*/

int my_find_prime_sup(int nb)
{
    int i = 1;
    int continuer = 0;
    int prime = 0;
    int a = 0;

    while (prime == 0) {
        nb = nb + a;
        for (i = 1; i <= nb; i++) {
            if ((nb % i) == 0)
                continuer++;
        }
        if (continuer == 2)
            prime = nb;
        a++;
        continuer = 0;
    }
    return (nb);
}
