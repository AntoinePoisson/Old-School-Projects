/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** take_object
*/

#include "zappy.h"

static char *take_object_norme(char **param);
static bool check_exist_in_map(client_t *client, char *object);
static bool check_exist_in_map_norme(client_t *cli, char *object, server_t *s);
static bool check_exist_in_map_norme_(client_t *cli, char *object, server_t *s);

int take_object(client_t *client, char **param)
{
    char *object = take_object_norme(param);

    if (strcmp(object, "none") == 0 || !check_exist_in_map(client, object))
        return (reply_server(404, client->socket, NULL) ? 0 : 0);
    reply_server(200, client->socket, NULL);
    return (0);
}

static char *take_object_norme(char **param)
{
    if (strcasecmp(param[0], "food") == 0)
        return ("food");
    if (strcasecmp(param[0], "linemate") == 0)
        return ("linemate");
    if (strcasecmp(param[0], "deraumere") == 0)
        return ("deraumere");
    if (strcasecmp(param[0], "sibur") == 0)
        return ("sibur");
    if (strcasecmp(param[0], "mendiane") == 0)
        return ("mendiane");
    if (strcasecmp(param[0], "phiras") == 0)
        return ("phiras");
    if (strcasecmp(param[0], "thystame") == 0)
        return ("thystame");
    return ("none");
}

static bool check_exist_in_map(client_t *cli, char *object)
{
    server_t *s = get_server();

    if (!strcasecmp(object, "food") && s->map[cli->y][cli->x]->food) {
        s->map[cli->y][cli->x]->food -= 1;
        cli->food += 1;
        return (true);
    }
    if (!strcasecmp(object, "linemate") && s->map[cli->y][cli->x]->linemate) {
        s->map[cli->y][cli->x]->linemate -= 1;
        cli->linemate += 1;
        return (true);
    }
    if (!strcasecmp(object, "deraumere") && s->map[cli->y][cli->x]->deraumere) {
        s->map[cli->y][cli->x]->deraumere -= 1;
        cli->deraumere += 1;
        return (true);
    }
    return (check_exist_in_map_norme(cli, object, s));
}

static bool check_exist_in_map_norme(client_t *cli, char *object, server_t *s)
{
    if (!strcasecmp(object, "sibur") && s->map[cli->y][cli->x]->sibur) {
        s->map[cli->y][cli->x]->sibur -= 1;
        cli->sibur += 1;
        return (true);
    }
    if (!strcasecmp(object, "mendiane") && s->map[cli->y][cli->x]->mendiane) {
        s->map[cli->y][cli->x]->mendiane -= 1;
        cli->mendiane += 1;
        return (true);
    }
    return (check_exist_in_map_norme_(cli, object, s));
}

static bool check_exist_in_map_norme_(client_t *cli, char *object, server_t *s)
{
    if (!strcasecmp(object, "phiras") && s->map[cli->y][cli->x]->phiras) {
        s->map[cli->y][cli->x]->phiras -= 1;
        cli->phiras += 1;
        return (true);
    }
    if (!strcasecmp(object, "thystame") && s->map[cli->y][cli->x]->thystame) {
        s->map[cli->y][cli->x]->thystame -= 1;
        cli->thystame += 1;
        return (true);
    }
    return (false);
}