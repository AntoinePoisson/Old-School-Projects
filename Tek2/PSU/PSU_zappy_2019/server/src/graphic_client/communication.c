/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** communication
*/

#include "zappy.h"

static void send_map_to_graphic(client_t *client, int size, server_t *server);
static int wait_for_write(int sock);
static void disconnect(client_t *client);

void send_map_to_graphics_clients(void)
{
    server_t *server = get_server();
    int size = server->arg.width * server->arg.height;

    for (client_t *cli = server->clients; cli; cli = cli->next) {
        if (cli->is_graphic && cli->close == false && cli->online &&
            cli->socket) {
            send_map_to_graphic(cli, size, server);
        }
    }
}

static void send_map_to_graphic(client_t *client, int size, server_t *server)
{
    char end_of_transition = '\n';

    if (wait_for_write(client->socket) <= 0 ||
        write(client->socket, &size, sizeof(int)) == -1) {
        client->close = true;
        return (disconnect(client));
    }
    for (int y = 0; y < server->arg.height; y++)
        for (int x = 0; x < server->arg.width; x++)
            if (wait_for_write(client->socket) <= 0 || write(client->socket,
                server->map[y][x], sizeof(cell_t)) == -1) {
                client->close = true;
                return (disconnect(client));
            }
    if (wait_for_write(client->socket) <= 0 ||
        write(client->socket, &end_of_transition, 1) == -1) {
        client->close = true;
        return (disconnect(client));
    }
}

static int wait_for_write(int sock)
{
    fd_set wset;
    struct timeval out = {1, 0};

    FD_ZERO(&wset);
    FD_SET(sock, &wset);
    return select(FD_SETSIZE, NULL, &wset, NULL, &out);
}

static void disconnect(client_t *client)
{
    if (client) {
        printf("Disconnect Client: %d | %s\n", client->socket, client->name);
        close(client->socket);
        memset(client->name, 0, strlen(client->name));
        memset(client->id, 0, strlen(client->id));
        client->buff = NULL;
        client->online = false;
        client->close = true;
        client->is_graphic = false;
        client->x = -1;
        client->y = -1;
        client->socket = 0;
    }
}