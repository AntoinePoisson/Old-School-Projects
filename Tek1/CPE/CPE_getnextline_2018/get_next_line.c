/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line.c
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *my_strcat(char *dest, char const *src)
{
    char *result;
    int i = 0;
    int a = 0;

    if (dest != NULL)
        for (a = 0; dest[a] != '\0'; a++);
    a += READ_SIZE + 1;
    if ((result = malloc(sizeof(char) * a + 1)) == NULL)
        return (NULL);
    if (dest != NULL)
        for (; dest[i] != '\0'; i++)
            result[i] = dest[i];
    if (src != NULL)
        for (a = 0; src[a] != '\0'; a++, i++)
            result[i] = src[a];
    result[i] = '\0';
    return (result);
}

int check_end_line(char *buffer, int return_read)
{
    int solv = -1;
    int i = 0;
    static char *prev_buffer = NULL;

    if (buffer != NULL) {
        for (; buffer[i] != '\0'; i++)
            if (buffer[i] == '\n') {
                solv = 1;
                break;
            }
        if (solv != -1)
            solv = i;
        else if (return_read == 0 && prev_buffer != buffer && i != 0) {
            solv = i;
            prev_buffer = buffer;
        }
    }
    else
        return (-1);
    return (solv);
}

char *rework_buffer(char *buffer, int *read_y, int *nbr_charac)
{
    int i = 0;
    int i_two = 0;
    int size = 0;

    for (i = 0; buffer != NULL && buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            break;
    if ((*nbr_charac = check_end_line(buffer, -1)) != -1)
        i++;
    for (size = 0; buffer != NULL && buffer[size] != '\0'; size++);
    if (size > 1 || (buffer != NULL && size == 1 && buffer[0] == '\n'))
        for (; buffer != NULL && buffer[i] != '\0'; i++, i_two++)
            buffer[i_two] = buffer[i];
    if (buffer != NULL)
        buffer[i_two] = '\0';
    if (*nbr_charac < 0 && check_end_line(buffer, -1) != -1) {
        *read_y = 0;
        *nbr_charac = check_end_line(buffer, -1);
    }
    return (buffer);
}

char *is_algo(int fd, int *line, int read_y, int *nbr)
{
    static char *buffer = NULL;
    static int nbr_charac = 0;
    static int ret_read = 0;
    char *reader = malloc(sizeof(char) * READ_SIZE);

    if (*line != 0 && read_y != 0)
        buffer = rework_buffer(buffer, &read_y, &nbr_charac);
    *line += 1;
    for (int i = 0; reader != NULL && i < READ_SIZE; i++)
        reader[i] = '\0';
    while ((read_y == 1) && (ret_read = read(fd, reader, READ_SIZE) > 0)) {
        if (ret_read == -1 || reader == NULL)
            return (NULL);
        buffer = my_strcat(buffer, reader);
        for (int i = 0; reader != NULL && i < READ_SIZE; i++)
            reader[i] = '\0';
        nbr_charac = check_end_line(buffer, ret_read);
        if (nbr_charac != -1 || ret_read  <= 0 || buffer == NULL)
            break;
    }
    if ((buffer == NULL) || (ret_read == 0 && buffer == NULL && read_y == 1) ||
        (ret_read == 0 && buffer[0] == '\0' && read_y == 1))
        return (NULL);
    if (ret_read == 0 && (nbr_charac = check_end_line(buffer, ret_read)) == -1
        || ret_read == 0 && reader[0] == '\0' && read_y == 1 && !buffer[0])
        return (NULL);
    free(reader);
    *nbr = nbr_charac;
    return (buffer);
}

char *get_next_line(int fd)
{
    static int line = 0;
    static int fd_save = -1;
    int nbr_charac = 0;
    char *result;
    char *buffer;
    int i = 0;

    if (fd < 0 || READ_SIZE <= 0 || READ_SIZE > 2147483647)
        return (NULL);
    if (fd_save != fd) {
        fd_save = fd;
        line = 0;
    }
    if ((buffer = is_algo(fd, &line, 1, &nbr_charac)) == NULL ||
        (result = malloc(sizeof(char) * nbr_charac + 1)) == NULL)
        return (NULL);
    for (i = 0; i < nbr_charac; i++)
        result[i] = buffer[i];
    result[i] = '\0';
    return (result);
}
