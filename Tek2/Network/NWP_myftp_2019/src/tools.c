/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** tools
*/

#include "server.h"

server_t *get_struct_server(void)
{
    static server_t server;

    return (&server);
}

void handle_quit_signal(int useless)
{
    if (useless || !useless) {
        destroy_server();
        printf("\n");
    }
    exit(RETURN_SUCCESS);
}

void add_client(volatile int new_socket, server_t *server)
{
    client_t *new = malloc(sizeof(*new));

    if (new == NULL) {
        reply_server(421, new_socket, NULL);
        exit(RETURN_ERROR);
    }
    new->socket = new_socket;
    new->socket_data = -1;
    new->login_user = 0;
    new->login_password = false;
    new->close = false;
    new->path_root = strdup(server->path);
    new->path_current = strdup(server->path);
    new->is_socket_data = NO_EXIST;
    new->buff_cmd = NULL;
    new->next = server->client_list;
    server->client_list = new;
    printf("Connection from %s:%d\n",
        inet_ntoa(server->addr.sin_addr), server->port);
    reply_server(220, new_socket, NULL);
}

void destroy_server(void)
{
    server_t *server = get_struct_server();
    client_t *save = NULL;

    for (bool first = true; server->client_list; first = false) {
        if (!first)
            free(save);
        save = server->client_list;
        free(save->path_current);
        save->path_current = NULL;
        free(save->path_root);
        save->path_root = NULL;
        free(save->buff_cmd);
        save->buff_cmd = NULL;
        close(save->socket);
        close(save->socket_data);
        server->client_list = server->client_list->next;
    }
    free(save);
    close(server->sockfd);
    free(server->path);
}

server_t *destroy_client(server_t *server, client_t *save)
{
    client_t *tmp = server->client_list;

    if (server->client_list == save) {
        server->client_list = server->client_list->next;
    } else {
        for (; tmp && tmp->next != save; tmp = tmp->next);
        if (tmp == NULL)
            return (server);
        tmp->next = tmp->next->next;
    }
    free(save->path_current);
    save->path_current = NULL;
    free(save->buff_cmd);
    save->buff_cmd = NULL;
    free(save->path_root);
    save->path_root = NULL;
    free(save);
    return (server);
}