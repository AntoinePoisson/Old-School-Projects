/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

    /* Includes System */
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <netdb.h>
#include <sys/select.h>
#include <stdbool.h>

    /* Includes Project */

    /* Define Project */
#define MAX_LINE 1024


    /* Enumeration */
enum {
    RETURN_SUCCESS = 0,
    RETURN_STOP = 1,
    RETURN_ERROR = 84,
};

enum socket_data_t {
    NO_EXIST,
    PASV,
    PORT,
};


    /* Structures */
typedef struct client_s
{
    int login_user;
    volatile int socket;
    volatile int socket_data;
    enum socket_data_t is_socket_data;
    bool login_password;
    bool close;
    char *path_root;
    char *path_current;
    char *buff_cmd;
    struct client_s *next;
} client_t;

typedef struct server_s
{
    volatile int sockfd;
    int port;
    char *path;
    struct sockaddr_in addr;
    client_t *client_list;
} server_t;

typedef struct cmd_s
{
    char *name;
    int (*fnct)(client_t *, char *);
    int nbr_param;
    bool change_directory;
} cmd_t;

typedef struct reply_server_s
{
    int code;
    char *message;
} reply_server_t;

    /* Prototypes */
// Tools
server_t *get_struct_server(void);
void handle_quit_signal(int useless);
void add_client(volatile int new_socket, server_t *server);
void destroy_server(void);
char **my_str_to_word_array(char const *str);
char **check_commands(char *cmd, int *code);
server_t *destroy_client(server_t *server, client_t *save);
bool checker_crlf(char *cmd);
char *get_pwd(void);
int special_case_pasv(int port, client_t *client);

// Message
void display_flag_help(void);

// Management - Handler
int check_arg(int ac, char *av[]);
bool success_init_server(server_t *server, char *av[]);
int management_client(client_t *client);
bool reply_server(int code, int socket, char *message);

// Loop
bool success_loop(server_t *server);

// Commands
int nothing(client_t *client, char *param);
int user(client_t *client, char *param);
int password(client_t *client, char *param);
int quit(client_t *client, char *param);
int cwd(client_t *client, char *param);
int cdup(client_t *client, char *param);
int dele(client_t *client, char *param);
int pwd(client_t *client, char *param);
int pasv(client_t *client, char *param);
int port(client_t *client, char *param);
int help(client_t *client, char *param);
int noop(client_t *client, char *param);
int retr(client_t *client, char *param);
int stor(client_t *client, char *param);
int list(client_t *client, char *param);

    /* List Commands */
static const cmd_t list_commands[34] = {
    {"USER", &user, 1, false}, //
    {"PASS", &password, -1, false},  //
    {"ACCT", &nothing, 1, false},
    {"CWD", &cwd, 1, true}, //
    {"CDUP", &cdup, 0, true}, //
    {"SMNT", &nothing, 1, false},
    {"QUIT", &quit, 0, false}, //
    {"REIN", &nothing, 0, false},
    {"PORT", &port, 1, false}, //
    {"PASV", &pasv, 0, false}, //
    {"TYPE", &nothing, 1, false},
    {"STRU", &nothing, 1, false},
    {"MODE", &nothing, 1, false},
    {"RETR", &retr, 1, true}, // Data transf
    {"STOR", &stor, 1, true}, // Data transf
    {"STOU", &nothing, 0, false},
    {"APPE", &nothing, 1, false},
    {"ALLO", &nothing, 1, false},
    {"REST", &nothing, 1, false},
    {"RNFR", &nothing, 1, false},
    {"RNTO", &nothing, 1, false},
    {"ABOR", &nothing, 0, false},
    {"DELE", &dele, 1, true}, //
    {"RMD", &nothing, 1, false},
    {"MKD", &nothing, 1, false},
    {"PWD", &pwd, 0, true}, //
    {"LIST", &list, -1, true}, // Data transf
    {"NLST", &nothing, 1, false},
    {"SITE", &nothing, 1, false},
    {"SYST", &nothing, 0, false},
    {"STAT", &nothing, 1, false},
    {"HELP", &help, -1, false}, //
    {"NOOP", &noop, 0, false}, //
    {0, 0, 0, false}, //
};

static const reply_server_t list_reply[39] = {
    {120, "120 Service ready in %s minutes.\r\n"},
    {125, "125 Data connection already open; transfer starting.\r\n"},
    {150, "150 File status okay; about to open data connection.\r\n"},
    {200, "200 Command okay.\r\n"},
    {214, "214 %s.\r\n"},
    {220, "220 Service ready for new user.\r\n"},
    {221, "221 Service closing control connection.\r\n"},
    {226, "226 Closing data connection.\r\n"},
    {227, "227 Entering Passive Mode (%s).\r\n"},
    {230, "230 User logged in, proceed.\r\n"},
    {250, "250 Requested file action okay, completed.\r\n"},
    {257, "257 \"%s\" created.\r\n"},
    {331, "331 User name okay, need password.\r\n"},
    {332, "332 Need account for login.\r\n"},

    {500, "500 Syntax error, command unrecognized.\r\n"},
    {501, "501 Syntax error in parameters or arguments.\r\n"},
    {202, "202 Command not implemented, superfluous at this site.\r\n"},
    {502, "502 Command not implemented.\r\n"},
    {503, "503 Bad sequence of commands.\r\n"},
    {504, "504 Command not implemented for that parameter.\r\n"},
    {211, "211 System status, or system help reply.\r\n"},
    {212, "212 Directory status.\r\n"},
    {213, "213 File status.\r\n"},
    {225, "225 Data connection open; no transfer in progress.\r\n"},
    {425, "425 Can't open data connection.\r\n"},
    {426, "426 Connection closed; transfer aborted.\r\n"},
    {530, "530 Not logged in.\r\n"},
    {532, "532 Need account for storing files.\r\n"},
    {350, "350 Requested file action pending further information.\r\n"},
    {451, "451 Requested action aborted. Local error in processing.\r\n"},
    {551, "551 Requested action aborted. Page type unknown.\r\n"},
    {450, "450 Requested file action not taken.\r\n"},
    {452, "452 Requested action not taken.\r\n"},
    {552, "552 Requested file action aborted.\r\n"},
    {553, "553 Requested action not taken.\r\n"},
    {215, "215 NAME system type.\r\n"},
    {550, "550 Requested action not taken.\r\n"},
    {421, "421 Service not available, closing control connection.\r\n"},
    {0, 0},
};

#endif /* !SERVER_H_ */
