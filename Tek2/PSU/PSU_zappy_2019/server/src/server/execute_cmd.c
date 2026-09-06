/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** execute_cmd
*/

#include "zappy.h"

static int interpret(server_t *server, client_t *client, char *buff);
static int client_not_log_norme(server_t *s, client_t *cli, int i);
static int clear_memory_cmd_exec(client_t *client, char **cmd);
static value_return_t client_not_log(server_t *server, client_t *client,
    char *buff);

void loop_execute_cmd(void)
{
    server_t *server = get_server();

    for (client_t *cli = server->clients; cli; cli = cli->next) {
        if (cli->tick_food >= FOOD_CYCLE && cli->online && !cli->is_graphic &&
            !GOD_MODE) {
            cli->food -= 1;
            if (is_death(cli))
                continue;
        }
        if (cli->tick_remaining <= 0 && !cli->buff_curr_cmd)
            take_next_command(cli);
        if (cli->tick_remaining <= 0 &&
            cli->buff_curr_cmd && strlen(cli->buff_curr_cmd)) {
            interpret(server, cli, cli->buff_curr_cmd);
            free(cli->buff_curr_cmd);
            cli->buff_curr_cmd = NULL;
        } else if (cli->tick_remaining != 0)
            cli->tick_remaining -= 1;
        cli->tick_food += cli->online ? 1 : 0;
    }
}

static int interpret(server_t *server, client_t *client, char *buff)
{
    char **cmd = NULL;

    if (!buff || strlen(buff) == 0) return Ok;
    for (int i = 0; buff[i]; i++)
        if (buff[i] == '\r' || buff[i] == '\n' ||
            !(buff[i] >= ' ' && buff[i] <= '|')) {
            buff[i] = '\n';
            buff[i + 1] = '\0';
            break;
        }
    if (!client->online) return client_not_log(server, client, buff);
    if ((cmd = check_commands(client, buff)) == NULL) return Ok;
    for (int i = 0; list_commands[i].name; i++)
        if (strcmp(list_commands[i].name, cmd[0]) == 0) {
            list_commands[i].fnct(client, &cmd[1]);
            return Ok;
        }
    return clear_memory_cmd_exec(client, cmd);
}

static value_return_t client_not_log(server_t *server, client_t *client,
    char *buff)
{
    int index = 0;
    int ind_team = -1;

    if (strlen(buff)) buff[strlen(buff) - 1] = '\0';
    for (team_t **tmp = server->arg.teams; tmp && tmp[index]; index++)
        if (strcmp(buff, tmp[index]->name) == 0)
            ind_team = index;
    if (ind_team == -1 && strcmp(buff, GRAPHICS_TEAM_NAME) == 0) {
        client->is_graphic = true;
    } else if (ind_team == -1)
        return (write(client->socket, "ko\n", 3) && Ok);
    if (client_not_log_norme(server, client, ind_team) == 0) {
        client->is_graphic = false;
        return (Ok);
    }
    if (ind_team != -1 && special_case_egg(client, ind_team)) return (Ok);
    strcpy(client->name, buff);
    client->online = true;
    if (!client->is_graphic) place_random_player(client);
    return (Ok);
}

static int client_not_log_norme(server_t *s, client_t *cli, int i)
{
    char map_size[256] = {0};

    if (i != -1 &&
        s->arg.teams[i]->nbr_current <= s->arg.teams[i]->nbr_online) {
        write(cli->socket, "ko\n", 3);
        return (0);
    }
    if (i != -1)
        s->arg.teams[i]->nbr_online += 1;
    sprintf(map_size, "%d\n%d %d\n", (i == -1) ? (99) :
    (s->arg.teams[i]->nbr_current - s->arg.teams[i]->nbr_online), s->arg.width,
    s->arg.height);
    write(cli->socket, map_size, strlen(map_size));
    return (1);
}

static int clear_memory_cmd_exec(client_t *client, char **cmd)
{
    for (int i = 0; cmd && cmd[i]; i++) {
        free(cmd[i]);
        cmd[i] = NULL;
    }
    if (cmd) {
        free(cmd);
        cmd = NULL;
    }
    return reply_server(500, client->socket, NULL) && Ok;
}