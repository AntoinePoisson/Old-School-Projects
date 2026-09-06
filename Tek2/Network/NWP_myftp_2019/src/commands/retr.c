/*
** EPITECH PROJECT, 2020
** new
** File description:
** retr
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "server.h"

static bool check_path(char *path);
static bool fock_cmd_retr(char *path, client_t *client);
static bool transfere_file(char *path, client_t *client);
static int special_case_port(int port, client_t *client);

int retr(client_t *client, char *param)
{
    if (client->is_socket_data == NO_EXIST) {
        reply_server(425, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if (!check_path(param)) {
        reply_server(500, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if (fock_cmd_retr(param, client) == false) {
        return (RETURN_ERROR);
    }
    return (RETURN_SUCCESS);
}

static bool check_path(char *path)
{
    struct stat sb;

    if (path == NULL)
        return (false);
    if (stat(path, &sb) == -1)
        return (false);
    if (access(path, R_OK) == -1)
        return (false);
    return (true);
}

static bool fock_cmd_retr(char *path, client_t *client)
{
    pid_t pid;

    if ((pid = fork()) == -1)
        return (false);
    if (pid == 0) {
        if (((client->is_socket_data == PORT) && ((client->socket_data =
            special_case_port(client->socket_data, client)) == -1))
            || ((client->is_socket_data == PASV) && ((client->socket_data =
            special_case_pasv(client->socket_data, client)) == -1))
            || (!transfere_file(path, client)))
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

static bool transfere_file(char *path, client_t *client)
{
    int fd = open(path, O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);
    char *data = calloc(((size <= 0) ? (1) : (size + 5)), 1);

    if (fd == -1 || size == -1 || !data || lseek(fd, 0, SEEK_SET) == -1
        || read(fd, data, size) <= 0) {
        close(fd);
        return (false);
    }
    if (write(client->socket_data, data, size) == -1) {
        close(fd);
        return (false);
    }
    free(data);
    close(fd);
    close(client->socket_data);
    reply_server(226, client->socket, NULL);
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