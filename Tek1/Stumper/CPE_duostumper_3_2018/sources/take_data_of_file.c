/*
** EPITECH PROJECT, 2019
** take_data_of_file.c
** File description:
** take_data_of_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my_lib.h"

int file_management(char const *file, int cas)
{
    int fd = -1;

    if (cas == -1) {
        fd = open(file, O_RDONLY);
        return (fd);
    }
    if (close(cas) == -1)
        return (-1);
    return (0);
}

int size_file(char const *file)
{
    struct stat sb;

    if (stat(file, &sb) == -1)
        return (-1);
    return (sb.st_size);
}

char *take_data_of_file(char const *file)
{
    int fd = file_management(file, -1);
    int size = -1;
    char *result = NULL;

    if (fd == -1 || (size = size_file(file)) == -1)
        return (NULL);
    result = my_malloc(size + 1);
    if (!result ||read(fd, result, size) == -1)
        return (NULL);
    return (result);
}
