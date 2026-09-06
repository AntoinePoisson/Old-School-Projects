/*
** EPITECH PROJECT, 2018
** architect
** File description:
** architect
*/

#include <stdio.h>
#include <stdlib.h>

int check_error(int ac, char *av[]);
int is_operator(char **tab, int i);
int my_strlen(char const *str);
int count_operator(int ac, char **tab);
int trans(char *str_one, char *str_two, char *str_three, char *four);
int scal(char *str_one, char *str_two, char *str_four, char *five) ;
int reflect(char *str_one, char *str_two, char *str_four);
int rotation(char *str_one, char *str_two, char *str_four);

void is_extension_sinle_calcul(char *av[], int ac, int i)
{
    if (is_operator(av, i) == 3 && i <= ac - 1 && i >= 2)
        rotation(av[i - 2], av[i - 1], av[i + 1]);
    else if (i + 1 != ac && is_operator(av, i) == 3 && !(i <= ac - 1 &&
        i >= 2)) {
        printf("Invalid Input\n");
        exit(84);
    }
    if (is_operator(av, i) == 4 && i <= ac - 1 && i >= 2)
        reflect(av[i - 2], av[i - 1], av[i + 1]);
    else if (i + 1 != ac && is_operator(av, i) == 4 && !(i <= ac - 1 &&
        i >= 2)) {
        printf("Invalid Input\n");
        exit(84);
    }
}

void single_calcul(char *av[], int ac, int i)
{
    for (i = 1; i < ac; i++) {
        if (is_operator(av, i) == 1 && i <= ac - 2 && i >= 2)
            trans(av[i - 2], av[i - 1], av[i + 1], av[i + 2]);
        else if (i + 1 != ac && is_operator(av, i) == 1 && !(i <= ac - 2 &&
            i >= 2)) {
            printf("Invalid Input\n");
            exit(84);
        }
        if (is_operator(av, i) == 2 && i <= ac - 2 && i >= 2)
            scal(av[i - 2], av[i - 1], av[i + 1], av[i + 2]);
        else if (i + 1 != ac && is_operator(av, i) == 2 && !(i <= ac - 2 &&
            i >= 2)) {
            printf("Invalid Input\n");
            exit(84);
        }
        is_extension_sinle_calcul(av, ac, i);
    }
}

int main(int ac, char *av[])
{
    int i = check_error(ac, av);
    int nbr_operator = count_operator(ac, av);

    if (nbr_operator == 1)
        single_calcul(av, ac, i);
    return (0);
}
