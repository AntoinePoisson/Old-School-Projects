/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** check_arg
*/

#include "zappy.h"

static int print_help(void);
static bool fill_server(server_t *server, int ac, char **av);
static bool is_only_nbr(char *str, bool point);
static bool add_squad(char **av, server_t *serv, int ac);

int check_arg(int ac, char **av, char **env)
{
    server_t *server = get_server();

    if (ac == 2 && (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0 ||
        strcmp(av[1], "--help") == 0))
        return (print_help());
    server->arg.port = NULL;
    server->arg.width = -1;
    server->arg.height = -1;
    server->arg.teams = NULL;
    server->arg.clients_nbr = -1;
    server->arg.freq = 100;
    if (!env || !av || !fill_server(server, ac, av) ||
        server->arg.port == NULL || server->arg.width <= 1 || server->arg.height
        <= 1 || server->arg.teams == NULL || server->arg.clients_nbr <= 0
        || server->arg.freq <= 0 || strcmp(server->arg.port, "0") == 0) {
        printf("Invalid or Missing Argument. Look at: ./zappy_server -h\n");
        return (Err);
    }
    change_value_teams_liste_nbr_client(server->arg.clients_nbr);
    return (check_param_width_and_height(server));
}

static int print_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 ");
    printf("name2 ... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n\tfre");
    printf("q\t\tis the reciprocal of time unit for execution of actions\n");
    return (Stop);
}

static bool fill_server(server_t *serv, int ac, char **av)
{
    int opt = 0;

    for (bool tmp = false; (opt = getopt(ac, av, "p:x:y:c:f:n:")) != -1;
        tmp = false) {
        if (opt == 'p' && ((tmp = is_only_nbr(optarg, false))) == true)
            serv->arg.port = strdup(optarg);
        if (!tmp && opt == 'x' && ((tmp = is_only_nbr(optarg, false))) == true)
            serv->arg.width = atoi(optarg);
        if (!tmp && opt == 'y' && ((tmp = is_only_nbr(optarg, false))) == true)
            serv->arg.height = atoi(optarg);
        if (!tmp && opt == 'n' && ((tmp = add_squad(av, serv, ac))) == true) {
        }
        if (!tmp && opt == 'c' && ((tmp = is_only_nbr(optarg, false))) == true)
            serv->arg.clients_nbr = atoi(optarg);
        if (!tmp && opt == 'f' && ((tmp = is_only_nbr(optarg, true))) == true)
            serv->arg.freq = atoi(optarg);
        if (tmp == false)
            return (false);
    }
    return (true);
}

static bool is_only_nbr(char *str, bool point)
{
    if (!str)
        return (false);
    for (int i = 0; str && str[i]; i++) {
        if (!('0' <= str[i] && '9' >= str[i]) && (point && str[i] == '.' && i))
            continue;
        if (!('0' <= str[i] && '9' >= str[i]))
            return (false);
    }
    return (true);
}

static bool add_squad(char **av, server_t *serv, int ac)
{
    int size = optarg ? 2 : 0;
    int index = 0;

    if (size == 0)
        return (false);
    for (int i = optind; i < ac && av[i] && av[i][0] != '-'; i++)
        size++;
    if ((serv->arg.teams = calloc(size, sizeof(team_t *))) == NULL)
        return (false);
    for (int i = optind - 1; i < ac && av[i] && av[i][0] != '-'; i++, index++) {
        serv->arg.teams[index] = create_new_team(strdup(av[i]), 1);
        if (!serv->arg.teams[index] || strlen(av[i]) >= DEFAULT_TEAM_NAME_LENGTH
            || strcmp(av[i], GRAPHICS_TEAM_NAME) == 0 || !strlen(av[i]))
            return (false);
        for (int s = 0; s < index; s++)
            if (strcmp(av[i], serv->arg.teams[s]->name) == 0)
                return (false);
    }
    return (true);
}