/*
** EPITECH PROJECT, 2019
** my_str_to_wordd_array
** File description:
** put a string in tab
*/

#include <stdlib.h>

int check_alpha(char c, char y)
{
    if (c != y)
        return (1);
    return (0);
}

int count_words(char *str, char y)
{
    int word = 0;
    int nb_words = 0;

    for (int i = 0; str[i]; i++) {
        if (word == 0 && check_alpha(str[i], y) == 1) {
            word = 1;
            nb_words = nb_words + 1;
        }
        if (word == 1 && check_alpha(str[i], y) == 0)
            word = 0;
    }
    return (nb_words);
}

void save_words(char **tab, char *str, int nb_words, char y)
{
    int i = 0;
    int begin = 0;
    int k = 0;

    for (int j = 0; j < nb_words; j++, i++) {
        for (; str[i] && check_alpha(str[i], y) == 0; i++);
        begin = i;
        for (; str[i] && check_alpha(str[i], y) == 1; i++);
        tab[j] = malloc(sizeof(char) * ((i - 1) - begin + 2));
        for (k = 0; begin <= i - 1; begin++, k++)
            tab[j][k] = str[begin];
        tab[j][k] = '\0';
    }
}

char **str_to_word_array(char *str, char y)
{
    int nb_words = count_words(str, y);
    char **tab = malloc(sizeof(char *) * (nb_words + 1));

    save_words(tab, str, nb_words, y);
    tab[nb_words] = NULL;
    return (tab);
}
