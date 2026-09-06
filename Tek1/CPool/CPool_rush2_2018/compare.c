/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** rush 2 etape 4
*/

#include <unistd.h>

int got_diff_fr(int ac, char **av);
int got_diff_eng(int ac, char **av);
int got_diff_ger(int ac, char **av);
int got_diff_spa(int ac, char **av);
void my_putchar (char c);
int my_putstr (char const *str);
int count_percent (int j, int nb_c);
int strlen_alph(char **av);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int carac = 0;

    for (carac = 0; str[carac] != '\0'; carac = carac + 1)
        my_putchar(str[carac]);
    return (0);
}

int sum_and_compare(int ac, char **av)
{
    int i = 0;
    char english[] = "=> English";
    char french[] = "=> French";
    char german[] = "=> German";
    char spanish[] = "=> Spanish";
    int nfr = got_diff_fr(ac, av);
    int neng = got_diff_eng(ac, av);
    int nger = got_diff_ger(ac, av);
    int nspa = got_diff_spa(ac, av);

    for (i = 0; i != nfr || i != neng || i != nger|| i != nspa; i++) {
        if (i == nfr)
            my_putstr(french);
        if (i == neng)
            my_putstr(english);
        if (i == nger)
            my_putstr(german);
        if (i == nspa)
            my_putstr(spanish);
        if (i == nfr || i == neng || i == nger|| i == nspa)
            return (0);
    }
    return (0);
}
