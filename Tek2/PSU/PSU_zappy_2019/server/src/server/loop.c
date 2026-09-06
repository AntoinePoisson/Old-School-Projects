/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** loop
*/

#include "zappy.h"

static void reset_sets(server_t *server);
static int look_for_events(server_t *sv);
static int handle_events(server_t *server);
static void ticking_management(void);

value_return_t loop_server(void)
{
    server_t *server = get_server();
    value_return_t ret = 0;

    while (!server->quit_server) {
        send_map_to_graphics_clients();
        reset_sets(server);
        ticking_management();
        ret = look_for_events(server);
        if (ret == Timeout)
            break;
        if (ret == Err || handle_events(server) == Err)
            return (Err);
        loop_execute_cmd();
        condition_win();
        condition_end();
    }
    return (Ok);
}

static void reset_sets(server_t *server)
{
    FD_ZERO(&server->set[0]);
    FD_SET(server->sock.socket, &server->set[0]);
    for (client_t *tmp = server->clients; tmp; tmp = tmp->next) {
        if (tmp->socket && tmp->close == false) {
            FD_SET(tmp->socket, &server->set[0]);
        }
    }
}

static int look_for_events(server_t *sv)
{
    struct timeval out = {0, 5};
    int val = select(FD_SETSIZE, &sv->set[0], NULL, NULL, &out);

    switch (val) {
        case -1: return Timeout;
        default: return val;
    }
}

static int handle_events(server_t *server)
{
    if (FD_ISSET(server->sock.socket, &server->set[0])) {
        if (handle_new_client(server) == Err)
            MINOR_THROW("connection failed");
        return (Ok);
    }
    for (client_t *tmp = server->clients; tmp; tmp = tmp->next) {
        if (FD_ISSET(tmp->socket, &server->set[0]) &&
            read_data_from_client(tmp) == Err) {
            MINOR_THROW("failed to read/interpret");
        }
    }
    for (client_t *tmp = server->clients; tmp;) {
        while (tmp && tmp->close)
            tmp = destroy_client(tmp);
        if (tmp)
            tmp = tmp->next;
    }
    return Ok;
}

static void ticking_management(void)
{
    server_t *s = get_server();
    static clock_t timer;
    static bool defined = false;
    static int regene = 0;

    if (!defined) {
        timer = clock();
        defined = true;
    }
    while (timer + (CLOCKS_PER_SEC / s->arg.freq) > clock() &&
        !s->quit_server) {
    }
    timer += CLOCKS_PER_SEC / s->arg.freq;
    if (regene > 7) {
        regene_resources_map();
        regene = 0;
    } else
        regene += 1;
}