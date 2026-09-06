/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** duplicate string
*/

#include <stddef.h>
#include <unistd.h>

void *my_malloc(size_t size, int fill);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *resul = NULL;
    int a = 0;

    if (src == NULL)
        return (NULL);
    resul = my_malloc(sizeof(char) * (my_strlen(src) + 1), 1);
    while (src[a] != 0) {
        resul[a] = src[a];
        a += 1;
    }
    return (resul);
}
