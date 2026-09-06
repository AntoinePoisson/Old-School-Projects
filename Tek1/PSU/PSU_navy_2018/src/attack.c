/*
** EPITECH PROJECT, 2019
** navy
** File description:
** attack.c
*/

#include "navy.h"

static int check_attack(char *entry)
{
    if (!entry || mstrlen(entry) != 2 ||
        (entry[0] < 'A' || entry[0] > 'H') ||
        (entry[1] < '1' || entry[1] > '8')) {
        mputstr("wrong position\n");
        return (-1);
    }
    return (0);
}

static int send_signal(int a, battleship_t *navy)
{
    int cpy = a;

    for ( ; a > 0; a /= 10) {
        usleep(100);
        if ((a % 10) == 1)
            kill(navy->enemy_pid, SIGUSR2);
        else
            kill(navy->enemy_pid, SIGUSR1);
    }
    usleep(100);
    if (bintoi(cpy) < 64) {
        kill(navy->enemy_pid, SIGUSR1);
        usleep(10);
    }
    if (bintoi(cpy) < 128) {
        kill(navy->enemy_pid, SIGUSR1);
        usleep(10);
    }
    return (0);
}

static int send_case(battleship_t *navy)
{
    int a, b;

    usleep(100);
    do {
        mputstr("attack: ");
        if ((navy->entry = mgetline(0)) == NULL)
            return (-1);
    } while (check_attack(navy->entry) == -1);
    for (a = 0; navy->my_map[a][0] != navy->entry[1]; a++);
    a *= 18;
    for (b = 0; navy->my_map[0][b] != navy->entry[0]; b++);
    a += b;
    return (send_signal(itobin(a), navy));
}

static int get_case(void)
{
    mputstr("waiting for enemy's attack...\n");
    for (int a = 0; a != 8; a++)
        pause();
    return (mgetnbr(recover_signal('\0')));
}

int torpedo(char **av, battleship_t *navy, int round)
{
    recover_signal('\0');
    navy->entry = NULL;
    navy->attack = 0;
    return ((round % 2) == 0) ? (send_case(navy)) : get_case();
}
