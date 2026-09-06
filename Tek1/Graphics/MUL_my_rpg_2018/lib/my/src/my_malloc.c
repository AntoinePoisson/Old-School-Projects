/*
** EPITECH PROJECT, 2019
** my_malloc
** File description:
** my_malloc
*/

#include <stdlib.h>

char *my_memset(char *pointer, char c, int size)
{
    for (int i = 0; i < size; pointer[i] = c, i++);
    return (pointer);
}

char **my_memset_table(char **pointer, int size)
{
    for (int i = 0; i < size; pointer[i] = NULL, i++);
    return (pointer);
}

void *my_malloc(size_t size, int fill)
{
    char *pointer_one = NULL;
    char **pointer_two = NULL;

    if (fill == 1) {
        if ((pointer_one = malloc(size)) == NULL)
            return (NULL);
        pointer_one = my_memset((char *)pointer_one, '\0',
        (size / sizeof(char)));
        return (pointer_one);
    }
    if (fill == 2) {
        if ((pointer_two = malloc(size)) == NULL)
            return (NULL);
        pointer_two = my_memset_table((char **)pointer_two,
        (size / sizeof(char *)));
        return (pointer_two);
    }
    return (NULL);
}
