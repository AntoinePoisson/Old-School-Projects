/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** special_case_egg
*/

#include "zappy.h"

static void change_name_egg_in_map(client_t *cli, server_t *server);
static client_t *reset_client(client_t *client);

bool special_case_egg(client_t *client, int index_team_name)
{
    server_t *server = get_server();
    client_t *egg = NULL;

    for (client_t *i = server->clients; i; i = i->next)
        if (strncmp(EGG_TEAM_NAME, i->name, strlen(EGG_TEAM_NAME)) == 0 &&
            strcmp(&i->name[strlen(EGG_TEAM_NAME)],
            server->arg.teams[index_team_name]->name) == 0)
            egg = i;
    if (egg == NULL)
        return (false);
    strcpy(egg->name, server->arg.teams[index_team_name]->name);
    change_name_egg_in_map(egg, server);
    egg->online = true;
    egg->socket = client->socket;
    client = reset_client(client);
    return (true);
}

void special_case_fork_norme(server_t *server, client_t *cli)
{
    client_t *new_client = calloc(1, sizeof(*new_client));

    if (!new_client)
        return;
    free(cli->buff_curr_cmd);
    cli->buff_curr_cmd = strdup("Fork true\n");
    strcpy(new_client->id, generate_uuid());
    strcpy(new_client->name, EGG_TEAM_NAME);
    strcpy(&new_client->name[strlen(EGG_TEAM_NAME)], cli->name);
    new_client->level = 1;
    new_client->tick_remaining = 600;
    new_client->x = cli->x;
    new_client->y = cli->y;
    new_client->look = (rand() % Left) + 1;
    new_client->food = 15;
    new_client->socket = 0;
    new_client->next = server->clients;
    server->clients = new_client;
    add_player_to_cell(cli->x, cli->y, new_client);
}

static void change_name_egg_in_map(client_t *cli, server_t *server)
{
    for (int i = 0; strlen(server->map[cli->y][cli->x]->players[i].id); i++)
        if (strcmp(server->map[cli->y][cli->x]->players[i].id, cli->id) == 0) {
            strcpy(server->map[cli->y][cli->x]->players[i].player_team,
                cli->name);
        }
}

static client_t *reset_client(client_t *client)
{
    memset(client->name, 0, DEFAULT_TEAM_NAME_LENGTH);
    client->level = 0;
    client->socket = 0;
    client->buff = NULL;
    client->tick_remaining = 99;
    client->online = false;
    client->is_graphic = false;
    client->x = -1;
    client->y = -1;
    client->look = None;
    client->tick_food = 200;
    client->linemate = 0;
    client->deraumere = 0;
    client->sibur = 0;
    client->mendiane = 0;
    client->phiras = 0;
    client->thystame = 0;
    return (client);
}