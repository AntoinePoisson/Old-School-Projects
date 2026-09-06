/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Day03
*/

#include <unistd.h>

int divisor(int nb)
{
    int i = 1;
    int r = 10;

    if (nb < 0) {
        nb = nb * (-1);
    }
    while(!(r >= 0 && r <= 9)) {
        r = nb / i;
        i = i * 10;
    }
    i = i / 10;
    return (i);
}

void decomposer(int nb)
{
    int i = divisor(nb);
    int r = 1;
    char c;
    
    if (nb < 0){
        write(1, "-",1);
        nb = nb * (-1);
    }
    for (i ; i >= 1 ; i = i/10) {
        r = nb/i;
        c = r + '0';
        write(1, &c, 1);
        nb = nb - (r*i);
    }
}

int my_put_nbr(int nb)
{
    decomposer(nb);
    return (0);
}


