/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cdup
*/

#include "server.h"

static char *find_path_parent(char *path);

int cdup(client_t *client, char *param)
{
    char *pwd = find_path_parent(client->path_current);

    if (param) {}
    if ((pwd == NULL) || (chdir(pwd) == -1)) {
        reply_server(550, client->socket, NULL);
        return (RETURN_ERROR);
    }
    pwd = get_pwd();
    if (!pwd) {
        reply_server(550, client->socket, NULL);
        return (RETURN_ERROR);
    }
    free(client->path_current);
    client->path_current = pwd;
    reply_server(200, client->socket, NULL);
    return (RETURN_SUCCESS);
}

static char *find_path_parent(char *path)
{
    int count_dir = 0;
    int last_occ = 0;
    int size = 0;

    if (!path)
        return (NULL);
    for (int i = 0; path[i]; i++)
        if (path[i] == '/') {
            count_dir++;
            last_occ = i;
        }
    if (count_dir <= 1)
        return (strdup("/"));
    size = strlen(path);
    for (int i = last_occ; i < size; i++)
        path[i] = '\0';
    return (strdup(path));
}