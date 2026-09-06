/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** rush2 etape 4
*/

int count_l_step_by_step(int ac, char ** av, char c);
int count_percent (int j, int nb_c);
int strlen_alph(char **av);

int tabeng[27] = {0, 817, 149, 278, 425, 1270, 223, 202, 609, 697, 15, 77, 403, 241, 675, 751, 193, 10, 599, 633, 906, 276, 98, 236, 15, 197, 7};

int got_diff_eng(int ac, char **av)
{
    int n;
    int nb_of_letter;
    int nb_of_letter_of_str;
    int sum1 = 0;
    int r = 0;

    for (int i = 2; i < ac; i++) {
        n = av[i][0] - 0;
        if (av[i][0] >= 65 && av[i][0] <= 90)
            n = n - 64;
        if (av[i][0] >= 97 && av[i][0] <= 122)
            n = n - 96;
        nb_of_letter = count_l_step_by_step(ac, av, av[i][0]);
        nb_of_letter_of_str = strlen_alph(av);
        r = tabeng[n] - count_percent(nb_of_letter, nb_of_letter_of_str);
        if (r < 0)
            r = r * (-1);
        sum1 = sum1 + r;
    }
    return (sum1);
}
