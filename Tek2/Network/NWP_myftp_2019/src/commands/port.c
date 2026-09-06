/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** port
*/

#include "server.h"

static int check_right_port(char *param);
static bool check_free_port(int param);

int port(client_t *client, char *param)
{
    if (!param || strlen(param) <= 2) {
        reply_server(501, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if (client->is_socket_data == PASV) {
        close(client->socket_data);
    }
    client->is_socket_data = PORT;
    client->socket_data = check_right_port(param);
    if (client->socket_data == -1 || check_free_port(client->socket_data)) {
        reply_server(501, client->socket, NULL);
        return (RETURN_ERROR);
    }
    reply_server(200, client->socket, NULL);
    return (RETURN_SUCCESS);
}

static int check_right_port(char *param)
{
    int res = 0;
    int port_one = -1;
    int port_two = -1;
    int i = 0;

    for (; param[i]; i++)
        if (param[i] == ',')
            res++;
    if (res != 1)
        return (-1);
    for (i = 0, res = -1; param[i]; i++) {
        if (!(param[i] >= '0' && param[i] <= '9')
            && !(param[i] == ',' && param[i + 1] != '\0'
            && i != 0))
            return (-1);
    }
    port_one = atoi(param);
    port_two = atoi(index(param, ',') + 1);
    return (port_one * 256 + port_two);
}

static bool check_free_port(int param)
{
    struct sockaddr_in addr;
    int fd = socket(AF_INET, SOCK_STREAM,
        getprotobyname("TCP")->p_proto);

    if (fd == -1)
        return (-1);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(param);
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr))) {
        close(fd);
        return (true);
    }
    close(fd);
    return (false);
}