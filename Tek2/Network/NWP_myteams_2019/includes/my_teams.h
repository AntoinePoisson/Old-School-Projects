/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_teams
*/

#ifndef MY_TEAMS_H_
# define MY_TEAMS_H_

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
#include "logging_server.h"

    /* Define Project */
# define DEFAULT_NAME_LENGTH 32
# define DEFAULT_DESCRIPTION_LENGTH 255
# define DEFAULT_BODY_LENGTH 512

# define DEFAULT_MESSAGE_LENGTH 1024

    /* Enumeration */
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
static const char *const USAGE_MESS = "USAGE: ./myteams_server port\n\
    port\tis the port number on which the server socket listens";

    /* Structures */
typedef struct socket_s
{
    int fd;
    socklen_t len;
    struct sockaddr_in addr;
} socket_t;

typedef struct server_s
{
    socket_t sock;
    fd_set set[3];
} server_t;

typedef struct reply_server_s
{
    int code;
    char *message;
    bool (*fnct)(client_t *);
} reply_server_t;

typedef struct cmd_s
{
    char *name;
    int (*fnct)(client_t *, char **);
    int nbr_param;
    bool must_be_log;
} cmd_t;

    /* Prototypes */
//Server
int wait_for_events(server_t *sv);
int handle_events(server_t *server);
int my_teams_server(const char *port);
int read_data_from_client(server_t *server, client_t *client);
int close_server(server_t *server, int ret);
void disconnect(server_t *server, client_t *client);
int handle_new_client(server_t *server);
int init_server(server_t *server, const char *port);

// Tools
int nothing(client_t *client, char **param);
char **my_str_to_word_array(char const *str);
char **check_right_commands(client_t *client, char *cmd, bool is_online);
char **management_multi_cmd(char *cmd);
char *transform_name(char *name);
int create_reply(client_t *client, char *descript, data_base_t *db);

// Message - Reply Server
bool reply_server(int code, int socket, char *message, char *current_user_id);

// Management - Handler

// Loop

// Commands
int help(client_t *client, char **param);
int logout(client_t *client, char **param);
int send_message(client_t *client, char **param);
int subscribe(client_t *client, char **param);
int login(client_t *client, char **param);
int users(client_t *client, char **param);
int user(client_t *client, char **param);
int messages(client_t *client, char **param);
int list(client_t *client, char **param);
int info(client_t *client, char **param);
int unsubscribe(client_t *client, char **param);
int use(client_t *client, char **param);
int create(client_t *client, char **param);
int subscribed(client_t *client, char **param);

    /* List Commands */
static const cmd_t list_commands[15] = {
    {"/help", &help, 0, false},
    {"/login", &login, -1, false},
    {"/logout", &logout, 0, true},
    {"/users", &users, 0, true},
    {"/send", &send_message, -1, true},
    {"/user", &user, 1, true},
    {"/messages", &messages, 1, true},
    {"/list", &list, 0, true},
    {"/subscribe", &subscribe, 1, true},
    {"/info", &info, 0, true},
    {"/unsubscribe", &unsubscribe, 1, true},
    {"/use", &use, -1, true},
    {"/create", &create, -1, true},
    {"/subscribed", &subscribed, -1, true},
    {0, 0, 0, false},
};

static const reply_server_t list_reply[39] = {
    {266, "266|Service Ready\n", NULL},
    {200, "200|read doc to see all commands: ./doc/\n", NULL},
    {201, "201|[%s]\n", NULL},

    {300, "300|%s\n", NULL},
    {301, "301|%s\n", NULL},
    {302, "302|%s\n", NULL},
    {303, "303|%s\n", NULL},
    {304, "304|%s\n", NULL},
    {305, "305|%s\n", NULL},
    {306, "306|%s\n", NULL},
    {307, "307|%s\n", NULL},
    {308, "308|%s\n", NULL},
    {309, "309|%s\n", NULL},
    {310, "310|%s\n", NULL},
    {311, "311|%s\n", NULL},
    {312, "312|%s\n", NULL},
    {313, "313|%s\n", NULL},
    {314, "314|%s\n", NULL},
    {315, "315|%s\n", NULL},
    {316, "316|%s\n", NULL},
    {317, "317|%s\n", NULL},
    {318, "318|%s\n", NULL},
    {319, "319|%s\n", NULL},
    {320, "320|%s\n", NULL},
    {321, "321|%s\n", NULL},
    {322, "322|%s\n", NULL},
    {324, "324|%s\n", NULL},

    {400, "400\n", NULL},
    {401, "401|%s\n", NULL},
    {402, "402|%s\n", NULL},
    {403, "403|%s\n", NULL},
    {404, "404|%s\n", NULL},
    {405, "405\n", NULL},

    {500, "500|Command not found\n", NULL},
    {503, "503|Invalid parameter syntax\n", NULL},
    {504, "504|Invalid parameter\n", NULL},
    {566, "566|Intern server error\n", NULL},
    {567, "567|Invalid command\n", NULL},
    {0, NULL, NULL},
};

#endif
