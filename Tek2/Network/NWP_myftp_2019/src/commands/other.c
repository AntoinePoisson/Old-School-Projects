/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** other
*/

#include "server.h"

int nothing(client_t *client, char *param)
{
    if (client && param) {}
    reply_server(500, client->socket, NULL);
    return (RETURN_SUCCESS);
}

int special_case_pasv(int port, client_t *client)
{
    volatile int sockfd = 0;
    struct sockaddr_in addr;
    socklen_t lenght = sizeof(addr);

    if ((getsockname(port, (struct sockaddr *)&addr, &lenght) == -1)) {
        reply_server(425, client->socket, NULL);
        return (-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    if ((sockfd = accept(port, (struct sockaddr *)&addr, &lenght)) < 0) {
        reply_server(425, client->socket, NULL);
        return (-1);
    }
    reply_server(150, client->socket, NULL);
    return (sockfd);
}