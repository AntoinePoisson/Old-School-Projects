/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#include "zappy.h"

static char *get_cmd(client_t *client);
static void special_case_fork(client_t *cli);

server_t *get_server(void)
{
    static server_t db = {0};

    return (&db);
}

client_t *destroy_client(client_t *save)
{
    server_t *server = get_server();
    client_t *tmp = server->clients;

    if (server->clients == save && save != NULL) {
        server->clients = server->clients->next;
    } else {
        for (; tmp && tmp->next != save; tmp = tmp->next) {
        }
        if (tmp == NULL)
            return (save);
        tmp->next = tmp->next->next;
    }
    if (save->socket)
        close(save->socket);
    free(save);
    save = NULL;
    return (save);
}

void take_next_command(client_t *client)
{
    char *cmd = get_cmd(client);

    if (!cmd || !strlen(cmd))
        return;
    client->buff_curr_cmd = cmd;
    for (int i = 0; list_commands[i].name; i++)
        if (strncmp(list_commands[i].name, cmd,
            strlen(list_commands[i].name)) == 0) {
            client->tick_remaining = list_commands[i].tick_cost;
            if (strncmp(client->buff_curr_cmd, "Fork", 4) == 0)
                special_case_fork(client);
            special_case_ritual(client);
            return;
        }
    client->tick_remaining = 0;
}

static char *get_cmd(client_t *client)
{
    int count = 0;
    char *res = NULL;

    for (int i = 0; client->buff &&
        client->buff[i] && client->buff[i] != '\n'; i++, count++) {
    }
    if (client->buff && client->buff[count] == '\n')
        count++;
    else if (client->buff && !client->buff[count])
        return (NULL);
    if (!client->buff || strlen(client->buff) == 0)
        return (NULL);
    if ((res = calloc(count + 1, sizeof(char))) == NULL)
        return (NULL);
    strncpy(res, client->buff, count);
    client->buff = &client->buff[count];
    return (res);
}

static void special_case_fork(client_t *cli)
{
    server_t *server = get_server();
    int index = 0;

    if (strcmp(cli->buff_curr_cmd, "Fork\n") != 0) {
        if (strncmp(cli->buff_curr_cmd, "Fork", 4) == 0) {
            free(cli->buff_curr_cmd);
            cli->buff_curr_cmd = strdup("Fork false\n");
        }
        return;
    }
    for (int i = 0; server->arg.teams[i]; i++)
        if (strcmp(server->arg.teams[i]->name, cli->name) == 0)
            index = i;
    if (server->arg.teams[index]->nbr_current + 1 >=
        server->arg.teams[index]->nbr_max) {
        free(cli->buff_curr_cmd);
        cli->buff_curr_cmd = strdup("Fork false\n");
        return;
    }
    special_case_fork_norme(server, cli);
}