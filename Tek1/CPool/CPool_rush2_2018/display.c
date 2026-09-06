/*
** EPITECH PROJECT, 2018
** rush2
** File description:
** rush2 etape 4
*/
#include <unistd.h>

int my_put_nbr(int nb);
int count_percent(int j, int nb_c);

void display_100()
{
    int c = 1;
    char c2;

    for (int i = 0; i < 4; i++) {
        c2 = c + '0';
        write(1, &c2, 1);
        if (i == 2)
            write(1, ".", 1);
        if (c == 1)
            c = 0;
    }
}

int display_nb(int nb)
{
    int divisor = 1000;
    int c = 1;
    char c2;

    if (nb == 10000) {
        display_100();
        return (0);
    } else {
        while (divisor != 0) {
            c = (nb / divisor);
            c2 = c + '0';
            if (!(c == 0 && divisor == 1000))
		write(1, &c2, 1);
            if (divisor == 100)
                write(1, ".", 1);
	    nb = nb - (c * divisor);
	    divisor = divisor / 10;
        }
    }
    return (0);
}


void print(int j, char *str, int total)
{
    int pourcent = count_percent(j, total);

    write(1, str, 1);
    write(1, ":", 1);
    my_put_nbr(j);
    write(1, " ", 1);
    write(1, "(", 1);
    display_nb(pourcent);
    write(1, "%", 1);
    write(1, ")", 1);
    write(1, "\n", 1);
}
