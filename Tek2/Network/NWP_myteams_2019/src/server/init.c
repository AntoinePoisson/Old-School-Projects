/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** init.c
*/

#include "my_teams.h"

static int set_address(socket_t *sock, const char *port)
{
    char *end = NULL;

    errno = 0;
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_addr.s_addr = INADDR_ANY;
    sock->addr.sin_port = htons(strtol(port, &end, 10));
    return (errno || *end);
}

static int bind_server(socket_t *sock, const char *port)
{
    if (memset(&sock->addr, 0, sock->len) == NULL)
        THROW("memset function failed");
    if (set_address(sock, port) == true)
        THROW("invalid port number");
    return bind(sock->fd, (const struct sockaddr *)&sock->addr, sock->len);
}

int init_server(server_t *server, const char *port)
{
    server->sock.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock.fd < 0)
        THROW("failed to create socket");
    server->sock.len = sizeof(struct sockaddr_in);
    if (bind_server(&server->sock, port) != Ok)
        THROW("ip/port already used");
    if (listen(server->sock.fd, SOMAXCONN) < 0)
        THROW("failed to create queue");
    printf("Server Start on port: %s\n", port);
    return Ok;
}