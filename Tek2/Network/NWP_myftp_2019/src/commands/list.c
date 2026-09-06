/*
** EPITECH PROJECT, 2020
** new
** File description:
** list
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "server.h"

static char *check_path(char *path);
static bool do_list(char *path, client_t *client);
static bool fock_cmd_list(char *path, client_t *client);
static int special_case_port(int port, client_t *client);

int list(client_t *client, char *param)
{
    char *path = param ? param : "./";

    if (client->is_socket_data == NO_EXIST) {
        reply_server(425, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if ((path = check_path(path)) == NULL) {
        reply_server(500, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if (fock_cmd_list(path, client) == false) {
        return (RETURN_ERROR);
    }
    return (RETURN_SUCCESS);
}

static char *check_path(char *path)
{
    struct stat sb;
    char *res = NULL;

    if (stat(path, &sb) == -1)
        return (NULL);
    res = calloc(8 + strlen(path), 1);
    if (!res)
        return (NULL);
    strcpy(res, "ls -l ");
    strcpy(&res[6], path);
    return (res);
}

static bool fock_cmd_list(char *path, client_t *client)
{
    pid_t pid;

    if ((pid = fork()) == -1)
        return (false);
    if (pid == 0) {
        if (((client->is_socket_data == PORT) && ((client->socket_data =
            special_case_port(client->socket_data, client)) == -1))
            || ((client->is_socket_data == PASV) && ((client->socket_data =
            special_case_pasv(client->socket_data, client)) == -1))
            || (!do_list(path, client)))
            exit(RETURN_ERROR);
        client->socket_data = -1;
        destroy_server();
        exit(RETURN_SUCCESS);
    }
    close(client->socket_data);
    client->socket_data = -1;
    client->is_socket_data = NO_EXIST;
    return (true);
}

static int special_case_port(int port, client_t *client)
{
    volatile int sockfd = socket(AF_INET, SOCK_STREAM,
        getprotobyname("TCP")->p_proto);
    struct sockaddr_in addr;

    if (sockfd == -1) {
        reply_server(425, client->socket, NULL);
        return (-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr))) {
        reply_server(425, client->socket, NULL);
        return (-1);
    }
    reply_server(150, client->socket, NULL);
    return (sockfd);
}

static bool do_list(char *path, client_t *client)
{
    FILE *fd = popen(path, "r");

    if (fd == NULL) {
        return (false);
    }
    for (char buff[1] = {0}; fread(buff, 1, 1, fd) > 0;) {
        if (buff[0] != '\n' &&
            write(client->socket_data, buff, 1) == -1) {
            reply_server(451, client->socket, NULL);
            return (false);
        } else if (buff[0] == '\n' &&
            write(client->socket_data, "\r\n", 2) == -1) {
            reply_server(451, client->socket, NULL);
            return (false);
        }
    }
    pclose(fd);
    close(client->socket_data);
    reply_server(226, client->socket, NULL);
    return (true);
}