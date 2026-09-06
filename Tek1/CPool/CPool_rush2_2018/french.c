/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** rush 2 etape 4
*/

int count_l_step_by_step(int ac, char ** av, char c);
int count_percent (int j, int nb_c);
int strlen_alph(char **av);

int tabfr[27] = {0, 764, 90, 326, 367, 1472, 107, 87, 74, 753, 61, 7, 546, 297, 710, 580, 252, 136, 669, 795, 724, 631, 184, 5, 43, 13, 33};

int got_diff_fr(int ac, char **av)
{
    int nb_of_letter;
    int nb_of_letter_of_str;
    int n;
    int sum2 = 0;
    int r = 0;

    for (int i = 2; i < ac; i++) {
        n = av[i][0] - 0;
        if (av[i][0] >= 65 && av[i][0] <= 90)
            n = n - 64;
        if (av[i][0] >= 97 && av[i][0] <= 122)
            n = n - 96;
        nb_of_letter = count_l_step_by_step(ac, av, av[i][0]);
        nb_of_letter_of_str = strlen_alph(av);
        r = tabfr[n] - count_percent(nb_of_letter, nb_of_letter_of_str);
        if (r < 0)
            r = r * (-1);
        sum2 = sum2 + r;
    }
    return (sum2);
}
