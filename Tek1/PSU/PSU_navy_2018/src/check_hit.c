/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check_hit.c
*/

#include "navy.h"

static void find_case(battleship_t *navy, char place[][3])
{
    int a = 0;

    for (navy->x = 0; navy->my_map[navy->x] != NULL; navy->x++) {
        for (navy->y = 0; navy->my_map[navy->x][navy->y] != 0; navy->y++) {
            if (a == navy->attack)
                break;
            a++;
        }
        if (a == navy->attack)
            break;
        a++;
    }
    (*place)[0] = navy->my_map[0][navy->y];
    (*place)[1] = navy->my_map[navy->x][0];
}

static int check_ships(battleship_t *navy)
{
    if (navy->my_map[navy->x][navy->y] >= '2' &&
        navy->my_map[navy->x][navy->y] <= '5') {
        mputstr("hit\n\n");
        navy->my_map[navy->x][navy->y] = 'x';
        kill(navy->enemy_pid, SIGUSR2);
    } else {
        mputstr("missed\n\n");
        navy->my_map[navy->x][navy->y] = 'o';
        kill(navy->enemy_pid, SIGUSR1);
    }
    pause();
    return (0);
}

static int wait_answer(battleship_t *navy)
{
    int z;
    char *str = malloc(9);

    if (!str)
        return (-1);
    pause();
    str = recover_signal('\0');
    for (z = 0; navy->my_map[0][z] != navy->entry[0]; z++);
    if (str[0] == '0') {
        mputstr("missed\n\n");
        navy->enemy_map[navy->entry[1] - 47][z] = 'o';
    } else {
        mputstr("hit\n\n");
        navy->enemy_map[navy->entry[1] - 47][z] = 'x';
    }
    kill(navy->enemy_pid, SIGUSR1);
    return (0);
}

int check_hit(char **av, battleship_t *navy, int round)
{
    char place[3] = {'\0', '\0', '\0'};

    recover_signal('\0');
    if ((round % 2) != 0) {
        usleep(100);
        navy->attack = bintoi(navy->attack);
        find_case(navy, &place);
        mputstr(place);
        mputstr(": ");
        check_ships(navy);
    } else {
        mputstr(navy->entry);
        mputstr(": ");
        if (wait_answer(navy) == -1)
            return (-1);
    }
    return (0);
}
