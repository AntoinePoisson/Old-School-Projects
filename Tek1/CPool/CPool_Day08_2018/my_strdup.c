/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** Write a function that allocates memory and copies the string given as argument
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *memoireAlloue = NULL;
    int size_str = my_strlen(src);

    memoireAlloue = malloc(sizeof(char) * (size_str + 1));
    for (i = 0; i != size_str; i++)
        memoireAlloue[i] = src[i];
    memoireAlloue[i] = '\0';
    return (memoireAlloue);
}
