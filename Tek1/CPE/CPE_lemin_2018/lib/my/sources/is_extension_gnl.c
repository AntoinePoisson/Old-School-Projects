/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** is_extension_get_next_line.c
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "get_next_line.h"

char *is_end_algo(int ret_read, char *buffer, int read_y)
{
    if ((ret_read == 0 && buffer == NULL && read_y == 1) ||
        (ret_read == 0 && buffer[0] == '\0' && read_y == 1))
        return (NULL);
    return (buffer);
}

char *clear_buffer(char *reader, int *line)
{
    *line += 1;
    for (int i = 0; reader != NULL && i < READ_SIZE; i++)
        reader[i] = '\0';
    return (reader);
}

char *is_end_algo_two(char *reader, int *nbr, int nbr_charac, char *buffer)
{
    free(reader);
    *nbr = nbr_charac;
    return (buffer);
}

char *clear_reader(char *reader)
{
    for (int i = 0; i < READ_SIZE; i++)
        reader[i] = '\0';
    return (reader);
}
