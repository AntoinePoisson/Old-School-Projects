/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** file_to_str.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int size_file(char const *filepath)
{
    struct stat st;

    stat(filepath, &st);
    return (st.st_size);
}

char *file_to_str(char const *filepath)
{
    char *str;
    int fd;
    int size = size_file(filepath);

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    if (size <= 0)
        return (NULL);
    if (!(str = malloc(sizeof(char) * (size + 1))))
        return (NULL);
    read(fd, str, size);
    str[size] = '\0';
    close(fd);
    return (str);
}
