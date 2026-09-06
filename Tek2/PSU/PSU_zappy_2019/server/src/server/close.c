/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** close
*/

#include "zappy.h"

static void destroy_map(server_t *server);
static void destroy_arg(server_t *server);
static void destroy_clients(server_t *server);

value_return_t destroy_server(void)
{
    server_t *s = get_server();

    for (client_t *cli = s->clients; cli; cli = cli->next)
        if (cli->socket) {
            printf("Close socket: %d | user_name: '%s'\n",
            cli->socket, cli->name);
            close(cli->socket);
        }
    close(s->sock.socket);
    destroy_map(s);
    destroy_arg(s);
    destroy_clients(s);
    return (Ok);
}

static void destroy_map(server_t *server)
{
    for (int y = 0; server->map && server->map[y]; y++)
        for (int x = 0; server->map[y][x]; x++) {
            free(server->map[y][x]);
            server->map[y][x] = NULL;
        }
    for (int y = 0; server->map && server->map[y]; y++) {
        free(server->map[y]);
    }
    if (server->map) {
        free(server->map);
        server->map = NULL;
    }
}

static void destroy_arg(server_t *server)
{
    if (server->arg.port) {
        free(server->arg.port);
        server->arg.port = NULL;
    }
    for (int i = 0; server->arg.teams && server->arg.teams[i]; i++) {
        if (server->arg.teams[i]->name) {
            free(server->arg.teams[i]->name);
            server->arg.teams[i]->name = NULL;
        }
        free(server->arg.teams[i]);
    }
    if (server->arg.teams) {
        free(server->arg.teams);
        server->arg.teams = NULL;
    }
}

static void destroy_clients(server_t *server)
{
    client_t *save = NULL;

    for (client_t *cli = server->clients; cli; cli = cli->next) {
        if (save) {
            free(save);
            save = NULL;
        }
        if (cli->buff_curr_cmd) {
            free(cli->buff_curr_cmd);
            cli->buff_curr_cmd = NULL;
        }
        save = cli;
    }
}