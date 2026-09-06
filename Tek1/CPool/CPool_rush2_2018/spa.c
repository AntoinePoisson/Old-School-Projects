/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** rush2 etape 4
*/

int count_l_step_by_step(int ac, char ** av, char c);
int count_percent (int j, int nb_c);
int strlen_alph(char **av);

int tabspa[26] = {0, 1153, 222, 402, 501, 1218, 69, 177, 70, 625, 49, 1, 497, 316, 671, 868, 251, 88, 463, 293, 114, 2, 22, 101, 47};

int got_diff_spa(int ac, char **av)
{
    int nb_of_letter;
    int nb_of_letter_of_str;
    int n;
    int sum4 = 0;
    int r = 0;

    for (int i = 2; i < ac; i++) {
        n = av[i][0] - 0;
        if (av[i][0] >= 65 && av[i][0] <= 90)
            n = n - 64;
        if (av[i][0] >= 97 && av[i][0] <= 122)
            n = n - 96;
        nb_of_letter = count_l_step_by_step(ac, av, av[i][0]);
        nb_of_letter_of_str = strlen_alph(av);
        r = tabspa[n] - count_percent(nb_of_letter, nb_of_letter_of_str);
        if (r < 0)
            r = r * (-1);
        sum4 = sum4 + r;
    }
    return (sum4);
}
