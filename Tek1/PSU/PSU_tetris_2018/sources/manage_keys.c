/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** manage_keys.c
*/

#include "my_tetris.h"

static int is_wrong_key(char const *key, int a, int b)
{
    if (key[a] ^ '\\' && key[a] ^ 27)
        return (key[b] && key[b] != '}') ? (EXIT_SUCCESS) : (EXIT_FAILURE);
    if (key[a] == '\\') {
        if ((key[b] ^ 'n' && key[b] ^ 't') || (key[b + 1] && key[b + 1] != '}'))
            return (EXIT_SUCCESS);
        return (EXIT_FAILURE);
    }
    if (str_comp(tigetstr("kcub1"), key) < 0 &&
        str_comp(tigetstr("kcuu1"), key) < 0 &&
        str_comp(tigetstr("kcuf1"), key) < 0 &&
        str_comp(tigetstr("kcud1"), key) < 0)
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

static int key_opt(char **key, char *op1, char *op2, char const **av)
{
    int is_hook = 0;

    if (str_comp(av[0], op1) < 0 && my_strncmp(av[0], op2, my_strlen(op2)) < 0)
        return (-1);
    if (my_strncmp(av[0], op2, my_strlen(op2)) == 0) {
        is_hook =
        (av[0][my_strlen(op2)] ^ '{') ? my_strlen(op2) : my_strlen(op2) + 1;
        if (is_wrong_key(av[0], is_hook, 1 + is_hook) == 0)
            return (write(2, "Wrong key letter.\n", 18));
        *key = (char *)&av[0][is_hook];
        (*key)[1] = '\0';
    } else {
        is_hook = (av[1] && av[1][0] == '{') ? 1 : 0;
        if (!av[1] || is_wrong_key(&av[1][is_hook], 0, 1) == 0)
            return (write(2, "Wrong key letter.\n", 18));
        *key = (char *)&av[1][is_hook];
        (*key)[1] = '\0';
        return (1);
    }
    return (EXIT_SUCCESS);
}

int is_key_opt(char const **av, options_t *opt, int *a)
{
    int c = -1;

    c = (c < 0) ? key_opt(&opt->keys.pause, "-p", "--key-pause=", &av[*a]) : c;
    c = (c < 0) ? key_opt(&opt->keys.right, "-r", "--key-right=", &av[*a]) : c;
    c = (c < 0) ? key_opt(&opt->keys.left, "-l", "--key-left=", &av[*a]) : c;
    c = (c < 0) ? key_opt(&opt->keys.quit, "-q", "--key-quit=", &av[*a]) : c;
    c = (c < 0) ? key_opt(&opt->keys.drop, "-d", "--key-drop=", &av[*a]) : c;
    c = (c < 0) ? key_opt(&opt->keys.turn, "-t", "--key-turn=", &av[*a]) : c;
    *a += (c == 1) ? 1 : 0;
    if (c > 0 && c != 1)
        return (EXIT_FAILURE);
    return (c < 0) ? (-1) : (EXIT_SUCCESS);
}
