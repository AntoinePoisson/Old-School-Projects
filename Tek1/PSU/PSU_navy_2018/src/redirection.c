/*
** EPITECH PROJECT, 2019
** navy
** File description:
** redirection.c
*/

#include "navy.h"

char *recover_signal(char add)
{
    static char nb[9] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    static int index = 0;

    if (add == '\0') {
        index = 0;
        return (mstrlen(nb) == 1) ? (nb) : (mrevstr(nb));
    }
    if (index == 0)
        for (int a = 0; a != 9; a++)
            nb[a] = '\0';
    nb[index] = add;
    index += 1;
    return (NULL);
}

void receive_signal(int signal, siginfo_t *info, void *context)
{
    (void)context;
    (void)info;
    if (signal == SIGUSR1)
        recover_signal('0');
    else
        recover_signal('1');
    return ;
}

int redirect_signal(void)
{
    struct sigaction sig;

    sig.sa_sigaction = receive_signal;
    sig.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sig, NULL) == -1)
        return (-1);
    if (sigaction(SIGUSR2, &sig, NULL) == -1)
        return (-1);
    return (0);
}
