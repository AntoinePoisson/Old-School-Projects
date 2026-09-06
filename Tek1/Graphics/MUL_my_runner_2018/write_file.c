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

    fd = fopen("Highscore.txt", "w+b");
    if (fd == NULL) {
        my_putstr("Cannot Write file.\n");
        return (NULL);
    }
    return (fd);
}

int write_file(char *score, char *level, char *bird)
{
    FILE *fd = open_file_w();
    char *separator = "|";

    if (fd == NULL) {
        fclose(fd);
        return (0);
    }
    fwrite(score, sizeof(char), my_strlen(score), fd);
    fwrite(separator, sizeof(char), 1, fd);
    fwrite(bird, sizeof(char), 1, fd);
    fwrite(separator, sizeof(char), 1, fd);
    fwrite(level, sizeof(char), my_strlen(level), fd);
    fwrite(separator, sizeof(char), 1, fd);
    return (1);
}
