/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** task 02 day10
*/

int my_strlen(char const *str);

int nbrimpair(char const *chaine)
{
    int i = 0;
    int nbrimpair = 0;

    for (i = 0; chaine[i] != '\0'; i = i + 1) {
        if (chaine[i] == '-' || chaine[i] == '−')
            nbrimpair = nbrimpair + 1;
    }
    if (nbrimpair % 2 == 0)
        return (1);
    else
        return (0);
}

int chartoint(char str)
{
    int nbr = str;
    return(nbr - 48);
}

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


int my_getnbr(char const *str)
{
    int i = 0;
    int int_return = 0;
    int nbr_chiffre = 0;
    int a = 0;
    int nb = 10;
    int p = 0;
    int b = 0;
    int first_chiffre = 0;
    char stokage[my_strlen(str)];

    for (i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            while(str[i] >= '0' && str[i] <= '9' && first_chiffre == 0) {
                stokage[a] = str[i];
                nbr_chiffre++;
                a++;
                i++;
            }
            stokage[a] = '\0';
            p = nbr_chiffre - 1;
            while (b < nbr_chiffre) {
                int_return = chartoint(stokage[b]) * my_compute_power_it(nb,p) + int_return;
                p--;
                b++;
                if (int_return > 276447232)
                    return (0);
            }
            first_chiffre++;
        }
    }
    if (first_chiffre == 0)
        return (0);
    if (nbrimpair(str) == 0)
        int_return = int_return * -1;
    return(int_return);
}
