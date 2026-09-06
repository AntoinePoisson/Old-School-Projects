/*
** EPITECH PROJECT, 2018
** count_operator
** File description:
** count_operator
*/

int count_operator(int ac, char **tab)
{
    int nbr = 0;

    for (int i = 0; i <= (ac - 1); i++) {
        for (int i_two = 0; tab[i][i_two] != '\0'; i_two++) {
            if ((tab[i][i_two] == '-' && tab[i][i_two + 1] == 't') ||
                (tab[i][i_two] == '-' && tab[i][i_two + 1] == 'z') ||
                (tab[i][i_two] == '-' && tab[i][i_two + 1] == 's') ||
                (tab[i][i_two] == '-' && tab[i][i_two + 1] == 'r'))
                nbr++;
        }
    }
    return (nbr);
}
