/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_realloc_array.c
*/

#include <stdlib.h>
#include <stddef.h>

int my_arrlen(char **array);
char *my_strdup(char const *src);

char **my_realloc_array(char **array, char *str)
{
    char **new_array = NULL;
    int i = 0;

    if (!(new_array = malloc(sizeof(char *) * (my_arrlen(array) + 2))))
        return (NULL);
    new_array[my_arrlen(array) + 1] = NULL;
    if (array != NULL) {
        for (; array[i]; i++) {
            new_array[i] = my_strdup(array[i]);
            free(array[i]);
        }
    }
    new_array[i] = my_strdup(str);
    free(array);
    return (new_array);
}
