/*
** EPITECH PROJECT, 2018
** Day 08
** File description:
** Task 04
*/

#include <stdlib.h>
#include <stddef.h>

int check_char(char const *str, int i)
{
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
        return (0);
    return (1);
}

int nb_word(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (check_char(str, i) == 1 && check_char(str, i + 1) == 0)
            nb = nb + 1;
        i = i + 1;
    }
    return (nb);
}

void malloc_string(char const *str, char **tab)
{
    int j = 0;
    int m = 0;
    int k = 0;

    while (j < nb_word(str) && str[m] != '\0') {
        while (check_char(str, m) == 0) {
            m = m + 1;
        }
        while (check_char(str, m) == 1) {
            m = m + 1;
            k = k + 1;
        }
        tab[j] = malloc(sizeof(char) * k + 1);
        j = j + 1;
        k = 0;
    }
}

void put_char_in_string(char const *str, char **tab)
{
    int j = 0;
    int m = 0;
    int k = 0;

    while (j < nb_word(str) && str[m] != '\0') {
        while (check_char(str, m) == 0) {
            m = m + 1;
        }
        while (check_char(str, m) == 1) {
            tab[j][k] = str[m];
            m = m + 1;
            k = k + 1;
        }
        tab[j][k] = '\0';
        k = 0;
        j = j + 1;
    }
    tab[j] = NULL;
}

char **my_str_to_word_array(char const *str)
{
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (nb_word(str) + 1));
    malloc_string(str, tab);
    put_char_in_string(str, tab);
    return (tab);
}
