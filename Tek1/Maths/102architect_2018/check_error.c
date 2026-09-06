/*
** EPITECH PROJECT, 2018
** check_error
** File description:
** check_error
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
int is_operator(char *tab[], int i);

void option_h(void)
{
    printf("USAGE\n"
        "\t./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] "
        "...\n\n"
        "DESCRIPTION\n"
        "    x      abscissa of the original point\n"
        "    y      ordinate of the original point\n"
        "    transfo arg1 [arg2]\n"
        "    -t i j      translation along vector (i, j)\n"
        "    -z m n      scaling by factors m (x-axis) and n (y-axis)\n"
        "    -r d        rotation centered in O by a d degree angle\n"
        "    -s d        reflection over the axis passing through O with an"
        " inclination\n"
        "                angle of d degrees\n");
}

int is_flag(char *av[], int i)
{
    if (av[i][0] == '-' && av[i][1] == 't' && av[i][2] == '\0')
        return (1);
    if (av[i][0] == '-' && av[i][1] == 'z' && av[i][2] == '\0')
        return (1);
    if (av[i][0] == '-' && av[i][1] == 'r' && av[i][2] == '\0')
        return (1);
    if (av[i][0] == '-' && av[i][1] == 's' && av[i][2] == '\0')
        return (1);
    return (0);
}

void check_invalid_argument(int ac, char *av[])
{
    for (int i = 1; i < ac; i++)
        for (int i_two = 0; av[i][i_two] != '\0'; i_two++) {
            if (i_two == 0 && is_flag(av, i) == 1)
                break;
            if (!(av[i][i_two] >= '0' && av[i][i_two] <= '9') && av[i][i_two] !=
                '.' && av[i][i_two] != '-') {
                printf("Invalid Input\n");
                exit(84);
            }
        }
}

void is_extension_check_error(int ac, char *av[])
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        option_h();
        exit(0);
    }
    if (ac == 1) {
        printf("Invalid Input\n");
        exit(84);
    }
    check_invalid_argument(ac, av);
}

int check_error(int ac, char *av[])
{
    int nbr_operator = 0;
    int save_ac = ac;

    is_extension_check_error(ac, av);
    for (int i = 0; ac > 0; i++, ac--) {
        if (av[i][0] == '-' && av[i][1] == 't')
            nbr_operator += 5;
        if (av[i][0] == '-' && av[i][1] == 'z')
            nbr_operator += 5;
        if (av[i][0] == '-' && av[i][1] == 'r')
            nbr_operator += 4;
        if (av[i][0] == '-' && av[i][1] == 's')
            nbr_operator += 4;
    }
    save_ac--;
    if (nbr_operator != save_ac || nbr_operator == 0) {
        printf("Invalid Input\n");
        exit(84);
    }
    return (nbr_operator);
}
