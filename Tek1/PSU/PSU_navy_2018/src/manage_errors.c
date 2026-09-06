/*
** EPITECH PROJECT, 2019
** navy
** File description:
** manage_errors.c
*/

#include "navy.h"

char *create_buffer(char *buff, int fd)
{
    int end_buffer;

    if ((buff = malloc(100)) == NULL)
        return (NULL);
    if ((end_buffer = read(fd, buff, 100)) == -1)
        return (NULL);
    buff[end_buffer] = 0;
    return (buff);
}

static char **alloc_strings(char **arr, int fd)
{
    char *buff = NULL;

    if ((buff = create_buffer(buff, fd)) == NULL)
        return (NULL);
    if ((arr = str_to_arr(buff)) == NULL)
        return (NULL);
    free(buff);
    return (arr);
}

static int check_size(char c)
{
    static char d = '\0';

    if (c < '2' || c > '5')
        return (-1);
    if (d == c)
        return (-1);
    else
        d = c;
    return (0);
}

static int analyse_pos(int fd)
{
    char **arr = NULL;

    if ((arr = alloc_strings(arr, fd)) == NULL)
        return (-1);
    for (int a = 0; arr[a] != NULL; a++) {
        if ((check_size(arr[a][0]) == -1) ||
            (arr[a][1] != ':' || arr[a][4] != ':') ||
            (arr[a][2] < 'A' || arr[a][2] > 'H') ||
            (arr[a][3] < '1' || arr[a][3] > '8') ||
            (arr[a][5] < 'A' || arr[a][5] > 'H') ||
            (arr[a][6] < '1' || arr[a][6] > '8'))
            return (-1);
        if (((arr[a][5] - arr[a][2]) != (a + 1)) &&
            ((arr[a][6] - arr[a][3]) != (a + 1)))
            return (-1);
    }
    for (int a = 0; arr[a] != NULL; a++)
        free(arr[a]);
    free(arr);
    return (0);
}

int error_handling(int ac, char **av)
{
    int fd;

    if (ac < 2 || ac > 3) {
        write(2, "Wrong number of arguments.\n", 27);
        return (-1);
    }
    if (ac == 2) {
        if ((fd = open(av[1], O_RDONLY)) == -1 || analyse_pos(fd) == -1) {
            write(2, "Wrong argument sent.\n", 21);
            return (-1);
        }
    } else
        if ((fd = open(av[2], O_RDONLY)) == -1 || analyse_pos(fd) == -1
            || mgetnbr(av[1]) <= 0 || misnum(av[1]) == -1) {
            write(2, "Wrong argument sent.\n", 21);
            return (-1);
        }
    close(fd);
    return (0);
}
