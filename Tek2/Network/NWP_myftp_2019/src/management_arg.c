/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** management_arg
*/

#include <sys/stat.h>
#include <unistd.h>
#include "server.h"

static bool init_bind_listen(server_t *server);
static char *check_right_path(char const *path, bool case_path);

int check_arg(int ac, char *av[])
{
    if (ac != 3) {
        if ((ac >= 2 && (strcmp(av[1], "-h") == 0 ||
            strcmp(av[1], "-help") == 0 || strcmp(av[1], "--help") == 0))
            || (ac == 1)) {
            display_flag_help();
            return (RETURN_STOP);
        }
        fprintf(stderr, "Invalide Parameter\n");
        return (RETURN_ERROR);
    }
    for (int i = 0; av[1][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9')) {
            fprintf(stderr, "Invalide Port Argument\n");
            return (RETURN_ERROR);
        }
    return (check_right_path(av[2], false) ? RETURN_SUCCESS : RETURN_ERROR);
}

char *get_pwd(void)
{
    char *res = calloc(9999, 1);
    char *pwd = NULL;

    if (!res || getcwd(res, 9999) == NULL) {
        perror("getcwd");
        return (NULL);
    }
    if (!res)
        return (NULL);
    pwd = strdup(res);
    free(res);
    return (pwd);
}

bool success_init_server(server_t *server, char *av[])
{
    server->port = atoi(av[1]);
    server->path = check_right_path(av[2], true);
    if (!server->path)
        return (false);
    server->client_list = NULL;
    server->sockfd = socket(AF_INET, SOCK_STREAM,
        getprotobyname("TCP")->p_proto);
    if (server->sockfd == -1) {
        perror("socket");
        return (false);
    }
    if (!init_bind_listen(server))
        return (false);
    return (true);
}

static bool init_bind_listen(server_t *server)
{
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(server->port);
    if (bind(server->sockfd, (struct sockaddr *)&server->addr,
        sizeof(server->addr))) {
        perror("bind");
        destroy_server();
        return (false);
    }
    if (listen(server->sockfd, 10)) {
        perror("listen");
        destroy_server();
        return (false);
    }
    if (FD_SETSIZE < server->sockfd + 1) {
        fprintf(stderr, "Too big File Descriptor\n");
        return (false);
    }
    return (true);
}

static char *check_right_path(char const *path, bool case_path)
{
    char *pwd = calloc(9999, 1);
    char *res = "okay";

    if (!pwd || getcwd(pwd, 9999) == NULL) {
        perror("getcwd");
        return (NULL);
    }
    if (chdir(path) == -1) {
        perror("chdir");
        return (NULL);
    }
    if (case_path)
        res = get_pwd();
    if (chdir(pwd) == -1) {
        perror("chdir");
        return (NULL);
    }
    free(pwd);
    return (res);
}