/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** loop.c
*/

#include "my_teams.h"

static int end(int value)
{
    static int ref = 0;

    ref += value;
    return ref;
}

static void reset_sets(server_t *server)
{
    FD_ZERO(&server->set[0]);
    FD_SET(server->sock.fd, &server->set[0]);
    for (client_t *tmp = get_data_base()->clients; tmp; tmp = tmp->next)
        if (tmp->online && tmp->socket) {
            FD_SET(tmp->socket, &server->set[0]);
        }
}

static int server_loop(server_t *server)
{
    int ret = 0;

    while (!end(0)) {
        reset_sets(server);
        ret = wait_for_events(server);
        if (ret == Timeout)
            return close_server(server, Ok);
        if (handle_events(server) == Err)
            return close_server(server, Err);
    }
    return close_server(server, Ok);
}

int my_teams_server(const char *port)
{
    server_t server;
    int value = 0;

    signal(SIGINT, (void (*)(int))end);
    if (init_server(&server, port) == Err)
        THROW("failed to build server");
    init_data_base(get_data_base());
    value = server_loop(&server);
    save_data_base();
    return (value);
}