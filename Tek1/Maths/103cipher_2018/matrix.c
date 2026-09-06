/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** key management
*/

#include "include/my.h"

int create_key(struct math *math, char *key)
{
    int y = 0;
    int x = 0;
    int i = 0;

    while (y < math->size_key && key[i] != '\0') {
        while (x < math->size_key && key[i] != '\0') {
            math->key[y][x] = key[i];
            i += 1;
            x += 1;
        }
        x = 0;
        y += 1;
    }
    return (y);
}

void display_key(struct math *math)
{
    int x = 0;
    int y = 0;

    printf("Key matrix:\n");
    while (y < math->size_key) {
        while (x < math->size_key - 1) {
            printf("%-7.0f ", math->key[y][x]);
            x += 1;
        }
        printf("%.0f\n", math->key[y][x]);
        y += 1;
        x = 0;
    }
}
