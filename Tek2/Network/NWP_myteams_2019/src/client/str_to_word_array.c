/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int cp_word(char *str, char c)
{
    int n = 1;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (i == 0 & (str[0] == c || str[0] == '\t')) {
            while (str[i] == c || str[i] == '\t')
                i++;
        }
        if ((str[i] == c || str[i] == '\t') && str[i + 1] != '\0') {
            n++;
            while (str[i] == c || str[i] == '\t')
                i++;
        }
    }
    return (n);
}

int cp_char(char *str, char c)
{
    int i = 0;

    while (str[i] != c && str[i] != '\0' && str[i] != '\n' && str[i] != '\t')
        i++;
    i++;
    return (i);
}

char **my_str_loop(char *str, char c, char **tab, int d)
{
    int k = 0;
    int a = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; k++) {
        if (str[i] == c || str[i] == '\t') {
            while (str[i] == c || str[i] == '\t')
                i++;
            if ((str[0] != c && str[0] != '\t') || k != 0)
                a++;
            d = 0;
        }
        tab[a] = malloc(sizeof(char) * (cp_char(str + i, c) + 1));
        while (str[i] != c && str[i] != '\n' && str[i] != '\0'
                && str[i] != '\t')
            tab[a][d++] = str[i++];
        tab[a][d++] = '\0';
    }
    tab[a + 1] = NULL;
    return (tab);
}

char **my_str_to_word_tab(char *str, char c)
{
    char **tab = NULL;
    int d = 0;

    if (str == NULL)
        return (NULL);
    tab = malloc(sizeof(char *) * (cp_word(str, c) + 1));
    if (tab == NULL)
        return (NULL);
    return (my_str_loop(str, c, tab, d));
}