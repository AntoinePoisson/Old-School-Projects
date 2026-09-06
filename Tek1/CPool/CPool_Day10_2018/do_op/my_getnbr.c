/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** task 02 Day 10
*/

int chosee_divisor(int nbr)
{
    int a = 10;
    int i = 1;

    for (i = 1; !(a >= 0 && a <= 9); i = i * 10)
        a = nbr / i;
    i = i / 10;
    return (i);
}

int my_put_nbr(int nbr)
{
    int i = 1;
    int a = chosee_divisor(nbr);
    char c = 0;

    while (a >= 1) {
        if (nbr < 0){
            write(1, 45, 1);
            nbr = nbr * (-1);
        }
        i = nbr / a;
        c = i + 48;
        write(1, &c, 1);
        nbr = nbr - (i * a);
        a = a / 10;
    }
    return (0);
}
