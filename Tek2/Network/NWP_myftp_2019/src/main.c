/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** main
*/

#include <signal.h>
#include "server.h"

int main(int ac, char *av[])
{
    server_t *server = get_struct_server();
    int check = check_arg(ac, av);

    if (check == RETURN_ERROR) {
        return (RETURN_ERROR);
    }
    if (check == RETURN_STOP) {
        return (RETURN_SUCCESS);
    }
    signal(SIGPIPE, handle_quit_signal);
    signal(SIGINT, handle_quit_signal);
    if (!success_init_server(server, av))
        return (RETURN_ERROR);
    if (!success_loop(server))
        return (RETURN_ERROR);
    destroy_server();
    return (RETURN_SUCCESS);
}