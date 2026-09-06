/*
** EPITECH PROJECT, 2018
** highscore
** File description:
** highscore
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include "defender.h"

int open_file_highscore(void)
{
    int fd = 0;

    fd = open("./sources/.Highscore.txt", O_RDONLY);
    if (fd == -1) {
        my_putstr("Create .Highscore.txt\n");
        return (-1);
    }
    return (fd);
}

int analyse_file(char *file, int nbr)
{
    int count_nbr = 0;
    int count_separator = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] < '0' && file[i] > '9' && file[i] != '|')
            return (84);
        if (nbr == 0 && file[i] >= '0' && file[i] <= '9') {
            nbr = 1;
            count_nbr += 1;
        }
        if (file[i] == '|' && is_ext_analy_file(&nbr, &count_separator) == 84)
            return (84);
    }
    if (count_separator != 3 && count_nbr != 3)
        return (84);
    return (0);
}

int compare_data(char *data, int score, int count, int final_result)
{
    int result = my_getnbr(data);

    if (count != 4) {
        if (result <= score)
            return (1);
        return (0);
    }
    if (count == 4) {
        if (result <= score)
            final_result++;
        if (final_result >= 2)
            return (1);
    }
    return (0);
}

char *is_extension_compare_score(char *data, char *file, int *i_two)
{
    for (int i = 0; file[*i_two] != '|'; i++, *i_two += 1) {
        data[i] = file[*i_two];
        data[i + 1] = '\0';
    }
    return (data);
}

int compare_score(int score, int level, int bird)
{
    int fd = open_file_highscore();
    int i_two = 0;
    int result = 0;
    int count = 1;
    char *fil = malloc(sizeof(char) * 99999);
    char *data = malloc(sizeof(char) * 99999);

    if (fd == -1 || read(fd, fil, 99999) < 1 || analyse_file(fil, i_two) != 0)
        return (84);
    for (; count <= 3; count++, i_two++) {
        is_extension_compare_score(data, fil, &i_two);
        if (count == 1)
            result += compare_data(data, score, count, result);
        if (count == 2)
            result += compare_data(data, level, count, result);
    }
    close(fd);
    return (compare_data(data, bird, count, result));
}
