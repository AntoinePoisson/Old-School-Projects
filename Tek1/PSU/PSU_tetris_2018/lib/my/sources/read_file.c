/*
** EPITECH PROJECT, 2019
** lib
** File description:
** read_file.c
*/

#include <stdio.h>
#include <stdlib.h>

static char *str_cat(char *s1, char *s2)
{
    int a = 0;
    int b = 0;
    char *tmp = NULL;

    for (; s1 && s1[a]; a++);
    for (; s2 && s2[b]; b++);
    tmp = malloc(a + b + 1);
    if (!tmp)
        return (NULL);
    tmp[a + b] = '\0';
    for (int c = 0; s1 && c ^ a; c++)
        tmp[c] = s1[c];
    for (int c = 0; s2 && c ^ b; c++)
        tmp[a + c] = s2[c];
    return (tmp);
}

char *read_file(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    char *file = NULL;
    char *buf = NULL;
    int res = 0;

    if (!fd)
        return (NULL);
    do {
        file = str_cat(file, buf);
        if (!file && buf)
            return (NULL);
        res = getline(&buf, &size, fd);
    } while (res != EOF);
    fclose(fd);
    return (file);
}
