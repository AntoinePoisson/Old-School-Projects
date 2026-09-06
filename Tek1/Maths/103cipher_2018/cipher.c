/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** Encrypt a message
*/

#include "include/my.h"

void my_mega_malloc(struct math *math, char *key)
{
    if ((math->key = malloc(sizeof(float *) + 1)) == NULL)
        exit(EXIT_ERROR);
    math->size_key = 1;
    for (; (math->size_key * math->size_key) < my_strlen(key);
    math->size_key++);
    for (int i = 0; i < math->size_key; i++)
        if ((math->key[i] = malloc(sizeof(float) *
            (math->size_key + 1))) == NULL)
            exit(EXIT_ERROR);
    for (int y = 0; y < math->size_key; y++)
        for (int x = 0; x < math->size_key; x++)
            math->key[y][x] = '\0';
}

int cipher(int ac, char **av)
{
    int size_key = check_error(ac, av);
    struct math *math;

    if ((math = malloc(sizeof(struct math) + 1)) == NULL)
        return (EXIT_ERROR);
    if (ac != 4)
        return (EXIT_ERROR);
    if (my_strlen(av[2]) >= 17)
        return (EXIT_ERROR);
    my_mega_malloc(math, av[2]);
    if (av[3][0] == '0') {
        size_key = create_key(math, av[2]);
        display_key(math);
        size_key = math->size_key;
        encrypted(av, math, size_key);
    }
    return (EXIT_SUCCESS);
}
