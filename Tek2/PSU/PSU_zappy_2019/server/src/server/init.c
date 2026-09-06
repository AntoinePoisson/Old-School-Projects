/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** init
*/

#include "zappy.h"

static void init_struture_server(server_t *server);
static value_return_t start_server(server_t *server);
static int bind_server(socket_t *sock, const char *port);
static int set_address(socket_t *sock, const char *port);

bool init_server(void)
{
    server_t *server = get_server();

    init_struture_server(server);
    if (create_map() == false)
        return (false);
    return (start_server(server) == Err ? false : true);
}

static void init_struture_server(server_t *server)
{
    server->quit_server = false;
}

static value_return_t start_server(server_t *server)
{
    server->sock.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock.socket < 0)
        THROW("failed to create socket");
    server->sock.len = sizeof(struct sockaddr_in);
    if (bind_server(&server->sock, server->arg.port) != Ok)
        THROW("ip/port already used");
    if (listen(server->sock.socket, SOMAXCONN) < 0)
        THROW("failed to create queue");
    fprintf(stdout, "Server Start on port: %s\n", server->arg.port);
    return (Ok);
}

static int bind_server(socket_t *sock, const char *port)
{
    if (memset(&sock->addr, 0, sock->len) == NULL)
        THROW("memset function failed");
    if (set_address(sock, port) == true)
        THROW("invalid port number");
    return bind(sock->socket, (const struct sockaddr *)&sock->addr, sock->len);
}

static int set_address(socket_t *sock, const char *port)
{
    char *end = NULL;

    errno = 0;
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_addr.s_addr = INADDR_ANY;
    sock->addr.sin_port = htons(strtol(port, &end, 10));
    return (errno || *end);
}