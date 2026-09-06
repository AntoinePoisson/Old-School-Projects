/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** conn.c
*/

#include "my_teams.h"

int close_server(server_t *server, int ret)
{
    for (client_t *cli = get_data_base()->clients; cli; cli = cli->next) {
        if (cli->online && cli->socket) {
            printf("Close socket: %d | user_name: '%s'\n", cli->socket,
            cli->user_name);
            close(cli->socket);
        }
    }
    close(server->sock.fd);
    return ret;
}

void disconnect(server_t *server, client_t *client)
{
    if (server) {
    }
    if (client) {
        close(client->socket);
        client->login_password = false;
        client->client_close = false;
        client->online = false;
        memset(client->use_team, 0, strlen(client->use_team));
        memset(client->use_channel, 0, strlen(client->use_channel));
        memset(client->use_thread, 0, strlen(client->use_thread));
        client->socket = 0;
        printf("Disconnect Client\n");
    }
}

int handle_new_client(server_t *server)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr_in);
    int sock = accept(server->sock.fd, (struct sockaddr *)&addr, &len);

    if (sock < 0 || !add_new_client_init(NULL, NULL))
        THROW("failed to host client");
    reply_server(266, sock, NULL, get_data_base()->clients->id);
    fprintf(stdout, "New Connection\n");
    get_data_base()->clients->socket = sock;
    return Ok;
}
