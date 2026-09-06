/*
** EPITECH PROJECT, 2019
** usefull
** File description:
** mgetline.c
*/

#include "mgetline.h"

static int str_size(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for ( ; str[i] != '\0'; i++);
    return (i);
}

static char *cat_str(char *line, char *buff)
{
    int a = 0;
    char *tmp = malloc(str_size(line) + str_size(buff) + 1);

    if (!tmp)
        return (NULL);
    if (line != NULL)
        for ( ; line[a] != 0; a++)
            tmp[a] = line[a];
    for (int b = 0; buff[b] != 0; b++, a++)
        tmp[a] = buff[b];
    tmp[a] = 0;
    return (tmp);
}

char *mgetline(int fd)
{
    char *buff = malloc(READ_SIZE + 1);
    char *line = NULL;
    int nb_read = 0;

    if (READ_SIZE < 1 || fd < 0 || !buff)
        return (NULL);
    while ((nb_read = read(fd, buff, READ_SIZE)) > 0) {
        if (nb_read == -1)
            return (NULL);
        buff[nb_read] = '\0';
        line = cat_str(line, buff);
        if (line[str_size(line) - 1] == 10 || line[str_size(line) - 1] == 0) {
            line[str_size(line) - 1] = 0;
            break;
        }
    }
    free(buff);
    return (line);
}
