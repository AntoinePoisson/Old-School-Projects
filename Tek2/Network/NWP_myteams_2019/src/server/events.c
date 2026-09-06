/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** events.c
*/

#include "my_teams.h"

int handle_events(server_t *server)
{
    if (FD_ISSET(server->sock.fd, &server->set[0])) {
        if (handle_new_client(server) == Err)
            MINOR_THROW("connection failed");
        return Ok;
    }
    for (client_t *tmp = get_data_base()->clients; tmp; tmp = tmp->next)
        if (FD_ISSET(tmp->socket, &server->set[0]) &&
            read_data_from_client(server, tmp) == Err)
            fprintf(stdout, "failed to read/interpret");
    return Ok;
}

int wait_for_events(server_t *sv)
{
    struct timeval out = {60, 0};
    int val = select(FD_SETSIZE, &sv->set[0], NULL, NULL, &out);

    switch (val) {
        case -1: return Timeout;
        case 0: RET_TIMEOUT(60);
        default: return val;
    }
}