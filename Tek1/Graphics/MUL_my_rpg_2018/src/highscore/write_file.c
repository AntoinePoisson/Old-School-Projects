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
#include "my_rpg.h"

int is_ext_analy_file(int *nbr, int *count_separator)
{
    if (*nbr == 0)
        return (84);
    *count_separator += 1;
    *nbr = 0;
    return (0);
}

int create_file_of_highsocre(game_t *game)
{
    int fd = 0;

    fd = open("./src/highscore/.Highscore.txt", O_RDWR);
    if (fd == -1) {
        fd = open("./src/highscore/.Highscore.txt", O_CREAT, S_IRUSR | S_IWUSR
            | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        close(fd);
        fd = open("./src/highscore/.Highscore.txt", O_RDWR);
        write(fd, "48|48|48|", 9);
        close(fd);
        if (fd == -1) {
            my_putstr("Cannot Write on highscore file.\n");
            return (-1);
        }
        management_highscore(game, 1);
    } else
        close(fd);
    return (0);
}

int open_file_w(void)
{
    int fd = 0;

    fd = open("./src/highscore/.Highscore.txt", O_CREAT, S_IRUSR | S_IWUSR
        | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    close(fd);
    fd = open("./src/highscore/.Highscore.txt", O_RDWR | O_TRUNC);
    if (fd == -1) {
        my_putstr("Cannot Write on highscore file.\n");
        return (-1);
    }
    return (fd);
}

int write_file(char *score, char *time, char *kill)
{
    int fd = open_file_w();

    if (fd == -1) {
        my_putstr("Cannot Open\n");
        return (84);
    }
    write(fd, score, my_strlen(score));
    write(fd, "|", 1);
    write(fd, time, my_strlen(time));
    write(fd, "|", 1);
    write(fd, kill, my_strlen(kill));
    write(fd, "|", 1);
    close(fd);
    free(score);
    free(time);
    free(kill);
    return (1);
}

int management_highscore(game_t *game, int cas)
{
    int score = game->var.score;
    int time = game->var.time;
    int kill = game->var.kill;

    if (check_file_highscore() == 84)
        return (84);
    if (cas == 1) {
        if (compare_score(score, time, kill) == 1)
            write_file(dec_to_char(my_itoa(score, 0)),
            dec_to_char(my_itoa(time, 0)),
            dec_to_char(my_itoa(kill, 0)));
        return (0);
    }
    game->var.score_of_file = my_atoi(char_to_dec(data_highscore_file(0)));
    game->var.kill_of_file = my_atoi(char_to_dec(data_highscore_file(1)));
    game->var.time_of_file = my_atoi(char_to_dec(data_highscore_file(2)));
    return (0);
}
