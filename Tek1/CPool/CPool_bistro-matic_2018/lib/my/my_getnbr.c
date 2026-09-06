/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** task05
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int minus = 0;

    while (str[i] == '-') {
        i += 1;
        minus += 1;
    }
    minus = minus % 2;
    for (int a = 0; str[i] >= '0' && str[i] <= '9'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        nbr = (nbr * 10) + (str[i] - '0');
        a += 1;
        if (a > 10)
            return (0);
    }
    if (minus != 0)
        nbr = nbr * (-1);
    return (nbr);
}
