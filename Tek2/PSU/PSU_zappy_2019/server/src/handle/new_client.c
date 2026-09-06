/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** new_client
*/

#include "zappy.h"

static client_t *add_new_client_init(void);

int handle_new_client(server_t *server)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr_in);
    int sock = accept(server->sock.socket, (struct sockaddr *)&addr, &len);

    if (sock < 0 || !add_new_client_init())
        THROW("failed to host client");
    fprintf(stdout, "New Connection\n");
    server->clients->socket = sock;
    write(sock, "WELCOME\n", 8);
    return (Ok);
}

client_t *add_new_client_init(void)
{
    server_t *serv = get_server();
    client_t *new_client = calloc(1, sizeof(*new_client));

    if (!new_client)
        return (NULL);
    strcpy(new_client->id, generate_uuid());
    new_client->food = 10;
    new_client->buff = NULL;
    new_client->close = false;
    new_client->online = false;
    new_client->look = None;
    new_client->level = 1;
    new_client->socket = 0;
    new_client->x = -1;
    new_client->y = -1;
    new_client->next = NULL;
    if (serv->clients)
        new_client->next = serv->clients;
    serv->clients = new_client;
    return (new_client);
}