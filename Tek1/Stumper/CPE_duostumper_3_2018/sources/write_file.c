/*
** EPITECH PROJECT, 2018
** write_file
** File description:
** write_file, return 1 success else 0
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_lib.h"

int my_putstr(char const *str);

FILE *open_file_w(void)
{
    FILE *fd = NULL;

    fd = fopen("crypt", "w+b");
    return (fd);
}

int write_file(char *data)
{
    FILE *fd = open_file_w();

    if (fd == NULL) {
        fclose(fd);
        return (84);
    }
    fwrite(data, sizeof(char), my_strlen(data), fd);
    return (0);
}
