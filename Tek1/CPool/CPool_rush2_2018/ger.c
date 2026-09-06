/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** rush2 etape 4
*/

int count_l_step_by_step(int ac, char ** av, char c);
int count_percent (int j, int nb_c);
int strlen_alph(char **av);

int tabger[27] = {0, 652, 189, 273, 508, 1640, 166, 301, 458, 655, 27, 1417, 344, 254, 978, 260, 67, 2, 700, 727, 615, 417, 85, 192, 3, 4, 113};

int got_diff_ger(int ac, char **av)
{
    int nb_of_letter;
    int nb_of_letter_of_str;
    int n;
    int sum5 = 0;
    int r = 0;

    for (int i = 2; i < ac; i++) {
        n = av[i][0] - 0;
        if (av[i][0] >= 65 && av[i][0] <= 90)
            n = n - 64;
        if (av[i][0] >= 97 && av[i][0] <= 122)
            n = n - 96;
        nb_of_letter = count_l_step_by_step(ac, av, av[i][0]);
        nb_of_letter_of_str = strlen_alph(av);
        r = tabger[n] - count_percent(nb_of_letter, nb_of_letter_of_str);
        if (r < 0)
            r = r * (-1);
        sum5 = sum5 + r;
    }
    return (sum5);
}
