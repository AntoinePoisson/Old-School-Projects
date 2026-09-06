/*
** EPITECH PROJECT, 2019
** usefull_function
** File description:
** str_to_wordarr.c
*/

#include "str_to_wordarr.h"

static int count_lines(char const *s)
{
    int nb = 0;

    for (int a = 0; s[a] != '\0'; a++)
        if (s[a] == '\n' && s[a + 1] != '\0')
            nb += 1;
    return (nb + 1);
}

static int count_cols(char const *s)
{
    static int a = 0;
    int nb = 0;

    for ( ; s[a] != 0; a++) {
        if (s[a] == '\n')
            break;
        nb += 1;
    }
    a += 1;
    return (nb);
}

static char **malloc_array(char const *s, char **tmp, nb_t *nb)
{
    nb->lines = count_lines(s);
    tmp = malloc(sizeof(char *) * nb->lines + 8);
    if (!tmp)
        return (NULL);
    tmp[nb->lines] = NULL;
    for (int a = 0; a != nb->lines; a++) {
        nb->cols = count_cols(s);
        tmp[a] = malloc(nb->cols + 1);
        if (!tmp[a])
            return (NULL);
    }
    return (tmp);
}

char **str_to_arr(char const *s)
{
    nb_t nb;
    char **tmp = NULL;

    nb.x = 0;
    tmp = malloc_array(s, tmp, &nb);
    if (!tmp)
        return (NULL);
    for (int a = 0; s[a] != '\0'; a++) {
        for (nb.y = 0; s[a] != '\n' && s[a] != '\0'; a++) {
            tmp[nb.x][nb.y] = s[a];
            nb.y += 1;
        }
        if (s[a] == '\0')
            a -= 1;
        tmp[nb.x][nb.y] = '\0';
        nb.x += 1;
    }
    return (tmp);
}
