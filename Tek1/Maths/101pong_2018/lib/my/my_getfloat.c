/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** D4, function that returns a number, sent to the function as a string.
*/

#include <math.h>

int my_strlen(char const *str);
int my_compute_power_rec(int nb, int p);
char *my_revstr(char *str);
int nbrimpair(char const *chaine);

float place_recovery_two_cus(int nbr_chiffre, char stokage[], float int_return,
                             int position_point)
{
    int p = 0;
    int b = 0;
    int nb = 10;

    while (b < nbr_chiffre) {
        if (b == position_point) {
            p *= -1;
            b++;
        }
        if (stokage[b] != '\0')
            int_return += (stokage[b] - 48) * powf(nb, p);
        else
            int_return += 0 * powf(nb, p);
        p++;
        b++;
    }
    return (int_return);
}

float place_recovery_one_cus(char const *str, int i, float int_return)
{
    int a = 0;
    float nbr_chiffre = 0;
    char stokage[my_strlen(str)];
    int point = -1;

    while (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
        if (str[i] == '.')
            point = a;
        stokage[a] = str[i];
        nbr_chiffre++;
        a++;
        i++;
    }
    stokage[a] = '\0';
    my_revstr(stokage);
    return (place_recovery_two_cus(nbr_chiffre, stokage, int_return, point));
}

float my_getfloat(char const *str)
{
    float int_return = 0;
    int first_chiffre = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= '0' && str[i] <= '9' && first_chiffre == 0) {
            int_return = place_recovery_one_cus(str, i, int_return);
            first_chiffre++;
        }
    }
    if (first_chiffre == 0)
        return (0);
    if (nbrimpair(str) == 0)
        int_return = int_return * -1;
    return (int_return);
}
