/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** loop
*/

#include "server.h"

static void check_add_client(fd_set *readfds, server_t *server);
static void loop_client(server_t *server);
static void extension_loop(server_t *server);

bool success_loop(server_t *server)
{
    fd_set readfds;

    for (;;) {
        check_add_client(&readfds, server);
        loop_client(server);
    }
    return (true);
}

static void loop_client(server_t *server)
{
    struct timeval timeout = {0, 100};
    client_t *dup = server->client_list;
    volatile int max_fd = 0;
    fd_set readfds;

    FD_ZERO(&readfds);
    for (; dup; dup = dup->next) {
        if (dup->socket > max_fd)
            max_fd = dup->socket;
        if (dup->socket != 0)
            FD_SET(dup->socket, &readfds);
    }
    if (max_fd == 0 || select(max_fd + 1, &readfds, NULL, NULL, &timeout) < 0)
        return;
    for (client_t *save = server->client_list; save; save = save->next)
        if (FD_ISSET(save->socket, &readfds) && save->close == false)
            management_client(save);
    extension_loop(server);
}

static void check_add_client(fd_set *readfds, server_t *server)
{
    struct timeval timeout = {0, 100};
    volatile int new_socket = 0;
    socklen_t lenght = 0;

    FD_ZERO(readfds);
    FD_SET(server->sockfd, readfds);
    if (select(server->sockfd + 1, readfds, NULL, NULL,
        &timeout) < 0) {
        perror("select");
        exit(RETURN_ERROR);
    }
    if (FD_ISSET(server->sockfd, readfds)) {
        lenght = sizeof(server->addr);
        if ((new_socket = accept(server->sockfd,
            (struct sockaddr *)&server->addr, &lenght)) < 0) {
            perror("accept");
            exit(RETURN_ERROR);
        }
        add_client(new_socket, server);
    }
}

static void extension_loop(server_t *server)
{
    for (client_t *save = server->client_list; save; save = save->next) {
        if (save->close == true && save->next == NULL) {
            destroy_client(server, save);
            break;
        } else if (save->close == true) {
            destroy_client(server, save);
        }
    }
}