/*
** EPITECH PROJECT, 2019
** is_create_tree.c
** File description:
** is_create_tree
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static int wrong_operator(char const *str, int cas)
{
    for (int i = 0; str[i] && str[i] == ' '; str = &str[i + 1]);
    if (cas != -1)
        if ((str[0] == '<' && str[1] == '<' && wrong_operator(&str[2], -1)) ||
            (str[0] == '>' && str[1] == '>' && wrong_operator(&str[2], -1)) ||
            (str[0] == '&' && str[1] == '&' && wrong_operator(&str[2], -1)) ||
            (str[0] == '|' && str[1] == '|' && wrong_operator(&str[2], -1)) ||
            (str[0] == '>' && wrong_operator(&str[1], -1)) ||
            (str[0] == '|' && wrong_operator(&str[1], -1)) ||
            (str[0] == ';' && wrong_operator(&str[1], -1)) ||
            (str[0] == '(' && wrong_operator(&str[1], -1)) ||
            (str[0] == '<' && wrong_operator(&str[1], -1)))
            return (1);
    if (cas == -1 && str[0] != '<' && str[0] != '>' &&
        str[0] != '|' && str[0] != ';' && str[0] != '&')
        return (1);
    return (0);
}

static int *arg_two_d_to_tab_two_d_int(char **arg)
{
    int count = 0;
    int *result = NULL;
    int i_two = 0;

    if (arg == NULL)
        return (NULL);
    for (int i = 0; arg[i]; i++)
        if (check_operator(arg[i]) != -1)
            count++;
    if ((result = malloc(sizeof(int) * (count + 1))) == NULL)
        return (NULL);
    for (int i = 0; arg[i]; i++, count = -1)
        if ((count = check_operator(arg[i])) != -1) {
            result[i_two] = count;
            i_two++;
        }
    result[i_two] = -1;
    return (result);
}

static int check_linking_operator(char **arg)
{
    int *tab = arg_two_d_to_tab_two_d_int(arg);

    if (tab == NULL)
        return (84);
    for (int i = 0; tab[i] != -1; i++)
        if ((tab[i] == 2 && tab[i + 1] == 3) ||
            (tab[i] == 2 && tab[i + 1] == 4) ||
            (tab[i] == 3 && tab[i + 1] == 3) ||
            (tab[i] == 3 && tab[i + 1] == 4) ||
            (tab[i] == 4 && tab[i + 1] == 3) ||
            (tab[i] == 4 && tab[i + 1] == 4) ||
            (tab[i] == 5 && tab[i + 1] == 5) ||
            (tab[i] == 5 && tab[i + 1] == 6) ||
            (tab[i] == 5 && tab[i + 1] == 2) ||
            (tab[i] == 6 && tab[i + 1] == 5) ||
            (tab[i] == 6 && tab[i + 1] == 6) ||
            (tab[i] == 6 && tab[i + 1] == 2))
            return (my_puterror("Ambiguous input redirect.\n"));
    free(tab);
    return (0);
}

int check_right_operator(char **arg)
{
    int nbr_operator = -1;
    int i = 0;

    for (i = 0; arg[i]; i++, nbr_operator = -1) {
        if (check_operator(arg[i]) != -1 && wrong_operator(arg[i], 1) == 0)
            return (display_adapt_message_of_wrong_operator(nbr_operator));
        if (((nbr_operator = check_operator(arg[i])) != -1) &&
            check_around_operator(arg, i, nbr_operator) == 84)
            return (84);
    }
    if (i > 0 && arg[i] == NULL) {
        nbr_operator = i - 1;
        for (i = 0; arg[nbr_operator] && arg[nbr_operator][i] == ' '; i++);
        if (arg[nbr_operator] != NULL && arg[nbr_operator][i] == '\0')
            arg[nbr_operator] = NULL;
    }
    return (check_linking_operator(arg));
}