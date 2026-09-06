/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/


#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdint.h>
#include <time.h>

    /* Includes System */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/queue.h>

#include "data_base.h"
#include "logging_client.h"
    /* Define Project */
# define DEFAULT_NAME_LENGTH 32
# define DEFAULT_DESCRIPTION_LENGTH 255
# define DEFAULT_BODY_LENGTH 512

# define DEFAULT_MESSAGE_LENGTH 1024

enum
{
    Ok = 0,
    Err = 84,
    Stop = 1,
    Usage = 2,
    Timeout = -1,
};

    /* Macro */
# define THROW(message) do { fprintf(stdout, "error: %s.\n", message);\
    return Err; } while (0)
# define MINOR_THROW(message) do { fprintf(stdout, "error: %s.\n", message);\
    return Ok; } while (0)
# define RET_USAGE() do { fprintf(stdout, "%s.\n", USAGE_MESS);\
    return Usage; } while (0)
# define RET_TIMEOUT(mess) do { fprintf(stdout, "%d Timeout ...\n", mess);\
    return Timeout; } while (0)

    /* Global */
static const char *const USAGE_FLAG = "-help";
static const char *const USAGE_MESS ="USAGE: ./myteams_server port\n\
    \tport\tis the port number on which the server socket listens\n";

char **management_multi_cmd(char *cmd);
int go_to_code(char **tab, char **tab_no_code, char *buff);
char *parser_commandes(char *cmd);
int check_code(char *buff);
int is_num(char c);
int check_args(const char *av1, int ac);
int read_stdin(fd_set *readfds, int client);
void reset_select(fd_set *readfds, int server);
int my_teams_client(const char *ip, const char *port);
int setup_server(struct sockaddr_in *server, const char *port, const char *ip);
int loop(int client);
int end(int value);
void print_buff(char *buff);
int cmd_300(char **tab);
int cmd_301(char **tab);
int cmd_302(char **tab);
int cmd_303(char **tab);
int cmd_304(char **tab);
int cmd_305(char **tab);
int cmd_306(char **tab);
int cmd_307(char **tab);
int cmd_308(char **tab);
int cmd_309(char **tab);
int cmd_310(char **tab);
int cmd_311(char **tab);
int cmd_312(char **tab);
int cmd_313(char **tab);
int cmd_314(char **tab);
int cmd_315(char **tab);
int cmd_316(char **tab);
int cmd_317(char **tab);
int cmd_318(char **tab);
int cmd_319(char **tab);
int cmd_320(char **tab);
int cmd_321(char **tab);
int cmd_322(char **tab);
int cmd_324(char **tab);
int cmd_400(char **tab);
int cmd_401(char **tab);
int cmd_402(char **tab);
int cmd_403(char **tab);
int cmd_404(char **tab);
int cmd_405(char **tab);

typedef struct cmd_s
{
    char *code;
    int (*fnct) (char **);
    int nbr_param;
} cmd_t;

static const cmd_t list_commands_code[31] = {
    {"300", &cmd_300, 0},
    {"301", &cmd_301, 1},
    {"302", &cmd_302, 0},
    {"303", &cmd_303, 0},
    {"304", &cmd_304, -1},
    {"305", &cmd_305, 1},
    {"306", &cmd_306, 1},
    {"307", &cmd_307, 0},
    {"308", &cmd_308, 0},
    {"309", &cmd_309, 1},
    {"310", &cmd_310, -1},
    {"311", &cmd_311, -1},
    {"312", &cmd_312, -1},
    {"313", &cmd_313, 0},
    {"314", &cmd_314, 0},
    {"315", &cmd_315, 0},
    {"316", &cmd_316, 0},
    {"317", &cmd_317, 0},
    {"318", &cmd_318, 0},
    {"319", &cmd_319, 0},
    {"320", &cmd_320, 0},
    {"321", &cmd_321, 0},
    {"322", &cmd_322, 0},
    {"324", &cmd_324, 0},
    {"400", &cmd_400, 0},
    {"401", &cmd_401, 0},
    {"402", &cmd_402, 0},
    {"403", &cmd_403, 0},
    {"404", &cmd_404, 0},
    {"405", &cmd_405, 0},
    {0, 0, 0},
};

char **my_str_to_word_tab(char *str, char c);

#endif /* CLIENT_H__ */
