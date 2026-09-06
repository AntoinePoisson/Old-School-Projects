/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** eject
*/

#include "zappy.h"

static client_t *id_to_client(char *id);
static bool change_all_player_to_cell(int x, int y, client_t *client);
static void change_all_player_to_cell_norme(int x, int y, char *id, int look);
static void change_all_player_to_cell_norme_remove(client_t *client,
    server_t *server);

int eject(client_t *client, __attribute__((unused)) char **param)
{
    int x = client->x;
    int y = client->y;

    switch (client->look) {
        case Up: calcul_new_position(&x, &y, 0, -1);
            break;
        case Down: calcul_new_position(&x, &y, 0, 1);
            break;
        case Left: calcul_new_position(&x, &y, -1, 0);
            break;
        case Right: calcul_new_position(&x, &y, 1, 0);
            break;
        default: reply_server(404, client->socket, NULL);
            return (0);
    }
    if (change_all_player_to_cell(x, y, client))
        reply_server(200, client->socket, NULL);
    else
        reply_server(404, client->socket, NULL);
    return (0);
}

static client_t *id_to_client(char *id)
{
    if (!id || strlen(id) <= 2)
        return (NULL);
    for (client_t *cli = get_server()->clients; cli; cli = cli->next)
        if (strcmp(cli->id, id) == 0)
            return (cli);
    return (NULL);
}

static bool change_all_player_to_cell(int x, int y, client_t *client)
{
    server_t *server = get_server();
    bool at_least_one = false;

    for (int i = 0;
        strlen(server->map[client->y][client->x]->players[i].id); i++)
        if (strcmp(server->map[client->y][client->x]->players[i].id,
            client->id) != 0) {
            change_all_player_to_cell_norme(x, y,
            server->map[client->y][client->x]->players[i].id, client->look);
            add_player_to_cell(x, y,
            id_to_client(server->map[client->y][client->x]->players[i].id));
            at_least_one = true;
        }
    change_all_player_to_cell_norme_remove(client, server);
    return (at_least_one);
}

static void change_all_player_to_cell_norme(int x, int y, char *id, int look)
{
    for (client_t *cli = get_server()->clients; cli; cli = cli->next)
        if (strcmp(cli->id, id) == 0) {
            cli->x = x;
            cli->y = y;
            reply_server(203, cli->socket, direction_look_eject(look, cli));
        }
}

static void change_all_player_to_cell_norme_remove(client_t *client,
server_t *server)
{
    for (int i = 0; strlen(server->map[client->y][client->x]->players[i].id);)
        if (strcmp(server->map[client->y][client->x]->players[i].id,
            client->id) != 0) {
            remove_player_to_cell(client->x, client->y,
            id_to_client(server->map[client->y][client->x]->players[i].id));
        } else {
            i++;
        }
}