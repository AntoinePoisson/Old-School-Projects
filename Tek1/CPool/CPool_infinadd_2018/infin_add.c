/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** corp of infin_add
*/

#include "./include/my.h"
#include <stddef.h>
#include <stdlib.h>

int infin_add(char *av[], int a, int b)
{
    int i = 0;
    int r = 0;
    int retenue = 0;
    char *chaine_three = NULL;
    int end_a = 1;
    int end_b = 1;
    int exit_negative = is_extension_exit_negative(av, a, b);

    chaine_three = malloc(sizeof(char) * (my_strlen(av[a]) + 2));
    for (i = 0; !(end_b == 0 && end_a == 0); i++) {
        if (av[b][i + exit_negative] == '\0')
            end_b = 0;
        if (av[a][i + exit_negative] == '\0')
            end_a = 0;
        r = ((av[a][i] - 48) * end_a) + ((av[b][i] - 48) * end_b) + retenue;
        is_extension_retenue(&r, &retenue);
        chaine_three[i] = (r + 48);
    }
    selection_display(chaine_three, r, i, av);
    return (0);
}

int selection_display(char chaine_three[], int r, int i, char *av[])
{
    if (r == 0)
        i = i - 1;
    my_revstr(av[1]);
    if (av[1][0] == '-') {
        i = i - 1;
        chaine_three[i + 1] = '\0';
        for (i; chaine_three[i] == '0'; i--);
        chaine_three[i + 1] = '-';
        chaine_three[i + 2] = '\0';
    } else {
        for ((i + 1); chaine_three[i] == '0'; i--);
        chaine_three[i + 1] = '\0';
    }
    my_revstr(chaine_three);
    my_putstr(chaine_three);
    my_putchar('\n');
    return (0);
}
