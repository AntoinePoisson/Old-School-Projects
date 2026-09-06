/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pasv
*/

#include "server.h"

static int create_data_socket(void);
static char *message_rep_server(int fd);
static char *get_port(int fd);
static char *get_ip(void);

int pasv(client_t *client, char *param)
{
    char *message = NULL;

    if (param) {}
    if (client->is_socket_data == PASV) {
        close(client->socket_data);
    }
    client->is_socket_data = PASV;
    client->socket_data = create_data_socket();
    if (client->socket_data == -1) {
        reply_server(500, client->socket, NULL);
        return (RETURN_ERROR);
    }
    message = message_rep_server(client->socket_data);
    if (!message) {
        reply_server(500, client->socket, NULL);
        return (RETURN_ERROR);
    }
    reply_server(227, client->socket, message);
    free(message);
    return (RETURN_SUCCESS);
}

static int create_data_socket(void)
{
    struct sockaddr_in addr;
    int fd = socket(AF_INET, SOCK_STREAM,
        getprotobyname("TCP")->p_proto);

    if (fd == -1)
        return (-1);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(0);
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)))
        return (-1);
    if (listen(fd, 10) || (FD_SETSIZE < fd + 1))
        return (-1);
    return (fd);
}

static char *message_rep_server(int fd)
{
    char *res = calloc(30, 1);
    char *ip = get_ip();
    char *port = get_port(fd);

    if (!res || !ip || !port)
        return (NULL);
    strcpy(res, ip);
    strcpy(&res[strlen(ip)], port);
    return (res);
}

static char *get_ip(void)
{
    server_t *server = get_struct_server();
    char *res = NULL;

    res = inet_ntoa(server->addr.sin_addr);
    if (strcmp(res, "0.0.0.0") == 0)
        res = "127.0.0.1";
    for (int i = 0; res && res[i]; i++)
        if (res[i] == '.')
            res[i] = ',';
    return (res);
}

static char *get_port(int fd)
{
    struct sockaddr_in addr;
    char *result = calloc(30, 1);
    socklen_t size = sizeof(addr);

    if ((!result) ||
        (getsockname(fd, (struct sockaddr *)&addr, &size) == -1))
        return (NULL);
    sprintf(result, ",%hu,%hu", (ntohs(addr.sin_port) / 256),
        (ntohs(addr.sin_port) % 256));
    if (!result)
        return (NULL);
    return (result);
}