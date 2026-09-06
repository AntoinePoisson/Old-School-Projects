/*
** EPITECH PROJECT, 2018
** step1 rush2
** File description:
** step1: nb of occurence
*/

int sum_and_compare(int ac, char **av);
void my_putchar (char c);
int my_putstr (char const *str);
void display_100();
int display_nb(int nb);
void print(int j, char *str, int total);

int count_percent(int j, int nb_c)
{
    int nb;
    int p = 100;

    for (int i = 0; !(p > 10000); i++) {
        nb = ((j * p) / nb_c);
        j = j * 10;
        p = p * 10;
        nb_c = nb_c * 10;
    }
    return (nb);
}

char determination_type_alph(char *str)
{
    char c = '0';

    if (str[0] >= 65 && str[0] <= 90)
        c = str[0] + 32;
    else if (str[0] >= 97 && str[0] <= 122)
        c = str[0] - 32;
    return (c);
}

int strlen_alph(char **av)
{
    int i = 0;
    int i3 = 0;

    while (av[1][i] != '\0') {
        if ((av[1][i] >= 65 && av[1][i] <= 90)
             || (av[1][i] >= 97 && av[1][i] <= 122))
            i3++;
        i++;
    }
    return (i3);
}

void count_nb_occurences(int ac, char **av)
{
    int i = 0;
    int i2 = 2;
    int j = 0;
    int total_alph = strlen_alph(av);

    while (i2 < ac) {
        j = 0;
        i = 0;
        while (av[1][i] != '\0') {
            if (av[1][i] == av[i2][0]
                || av[1][i] == determination_type_alph(av[i2]))
                j++;
            i++;
        }
        print(j, av[i2], total_alph);
        i2++;
    }
    sum_and_compare(ac,av);
}

int check_error(int ac, char **av)
{
    int i = 2;
    int i2;

    if (ac < 2)
        return (0);
    while ( i < ac ) {
        for (i2 = 0; av[i][i2] != '\0'; i2++);
        if ( i2 != 1)
            return (0);
        i++;
    }
    return (1);
}

int main (int ac, char **av)
{
    if (check_error(ac, av) !=1)
        return (0);
    count_nb_occurences(ac, av);
    return (0);
}
