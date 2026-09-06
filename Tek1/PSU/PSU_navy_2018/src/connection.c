/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connection.c
*/

#include "navy.h"

static int stack_pid(int pid)
{
    static int stack = 1;

    stack *= pid;
    return (stack);
}

static void detect_enemy(int sig, siginfo_t *info, void *ctxt)
{
    (void)sig;
    (void)ctxt;
    stack_pid(info->si_pid);
    mputstr("enemy connected\n\n");
}

static int send_connection(int enemy_pid, int my_pid)
{
    if (enemy_pid == my_pid)
        return (-1);
    if (kill(enemy_pid, SIGUSR2) == -1)
        return (-1);
    mputstr("my_pid:  ");
    mput_nbr(my_pid);
    mputstr("\nsuccessfully connected\n\nmy positions:\n");
    return (0);
}

static int wait_connection(int *enemy_pid, int *my_pid)
{
    struct sigaction sig;

    sig.sa_sigaction = detect_enemy;
    sig.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR2, &sig, NULL) == -1)
        return (-1);
    mputstr("my_pid:  ");
    mput_nbr(*my_pid);
    mputstr("\nwaiting for enemy connection...\n\n");
    pause();
    *enemy_pid = stack_pid(1);
    mputstr("my positions:\n");
    return (0);
}

int connection(char **av, battleship_t *navy)
{
    navy->my_pid = getpid();
    if (av[2] == NULL) {
        if (wait_connection(&navy->enemy_pid, &navy->my_pid) == -1)
            return (-1);
    } else {
        navy->enemy_pid = mgetnbr(av[1]);
        if (send_connection(navy->enemy_pid, navy->my_pid) == -1)
            return (-1);
    }
    return (0);
}
