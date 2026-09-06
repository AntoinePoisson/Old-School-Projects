/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** read_input
*/

#include "zappy.h"

static void disconnect(client_t *client);
static void add_new_commande(client_t *client, char *cmd);

int read_data_from_client(client_t *client)
{
    char buff[DEFAULT_MESSAGE_LENGTH + 5] = {0};

    for (int value = 1; value > 0; value = 0) {
        value = read(client->socket, buff, DEFAULT_MESSAGE_LENGTH);
        switch (value) {
            case -1:
                if (client->socket) disconnect(client);
                THROW("failed to read data from client");
            case 0: disconnect(client);
                return Ok;
            default:
                add_new_commande(client, buff);
                break;
        }
    }
    return Ok;
}

static void disconnect(client_t *client)
{
    if (client) {
        printf("Disconnect Client: %d | %s\n", client->socket, client->name);
        up_free_place_in_team(client);
        remove_player_to_cell(client->x, client->y, client);
        close(client->socket);
        memset(client->name, 0, strlen(client->name));
        memset(client->id, 0, strlen(client->id));
        client->buff = NULL;
        client->online = false;
        client->close = true;
        client->is_graphic = false;
        client->x = -1;
        client->y = -1;
        client->socket = 0;
    }
}

static void add_new_commande(client_t *client, char *cmd)
{
    int count = 0;
    int size = 0;
    char *res = NULL;

    for (int i = 0; client->buff && client->buff[i]; i++)
        if (client->buff[i] == '\n')
            count++;
    if (count > 10 || cmd == NULL) return;
    size = client->buff ? (strlen(client->buff) + strlen(cmd)) : (strlen(cmd));
    if (!(res = calloc(size + 1, sizeof(char))) ||
        (client->buff && !strcpy(res, client->buff)))
        return;
    for (int i = strlen(res); (i < (size + 1)) && count <= 10 && cmd[0]; i++) {
        if ((res[i] = cmd[0]) == '\n')
            count++;
        cmd = &cmd[1];
    }
    client->buff = NULL;
    if (strlen(res)) client->buff = res;
}