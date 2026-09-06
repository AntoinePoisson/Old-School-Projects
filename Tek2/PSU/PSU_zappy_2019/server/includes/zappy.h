/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** zappy
*/

#ifndef ZAPPY_H_
#define ZAPPY_H_

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
#include <time.h>
#include <math.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/queue.h>

    /* Define Project */
# define DEFAULT_MESSAGE_LENGTH 2048
# define DEFAULT_TEAM_NAME_LENGTH 512
# define DEFAULT_FOOD_UNIT 126
# define MAX_PLAYER_SAME_POSITION 128
# define CONDITION_WIN 6
# define SIZE_ID_UUID 37
# define TICKS 30
# define FOOD_CYCLE 126
# define GRAPHICS_TEAM_NAME "GRAPHIC"
# define EGG_TEAM_NAME "__EGG_OF_TEAM_"
# define GOD_MODE false
# define DEF_RES_CASE 5000
# define M_PI 3.14159265358979323846

    /* Enumeration */
typedef enum value_return_e {
    Ok = 0,
    Err = 84,
    Stop = 1,
    Usage = 2,
    Timeout = -1,
} value_return_t;

typedef enum look_direction_e {
    None,
    Up,
    Down,
    Left,
    Right,
} look_direction_t;

    /* Macro */
# define THROW(message) do { fprintf(stderr, "fatal error: %s.\n", message);\
    return Err; } while (0)
# define MINOR_THROW(message) do { fprintf(stderr, "error: %s.\n", message);\
    return Ok; } while (0)
# define RET_TIMEOUT(mess) do { fprintf(stdout, "%d Timeout ...\n", mess);\
    return Timeout; } while (0)

    /* Global */

    /* Structures */
typedef struct socket_s
{
    volatile int socket;
    socklen_t len;
    struct sockaddr_in addr;
} socket_t;

typedef struct client_s
{
    char id[SIZE_ID_UUID];
    char name[DEFAULT_TEAM_NAME_LENGTH];
    int level;
    char *buff;
    char *buff_curr_cmd;
    unsigned int tick_remaining;
    bool online;
    bool close;
    bool is_graphic;
    int x;
    int y;
    look_direction_t look;
    int tick_food;
    uint16_t food;
    uint16_t linemate;
    uint16_t deraumere;
    uint16_t sibur;
    uint16_t mendiane;
    uint16_t phiras;
    uint16_t thystame;
    volatile int socket;
    struct client_s *next;
} client_t;

typedef struct cell_player_s
{
    char id[SIZE_ID_UUID];
    char player_team[DEFAULT_TEAM_NAME_LENGTH];
    look_direction_t look;
} cell_player_t;

typedef struct cell_s
{
    int x;
    int y;
    unsigned int food;
    unsigned int linemate;
    unsigned int deraumere;
    unsigned int sibur;
    unsigned int mendiane;
    unsigned int phiras;
    unsigned int thystame;
    cell_player_t players[MAX_PLAYER_SAME_POSITION];
} cell_t;

typedef struct team_s
{
    char *name;
    int nbr_max;
    int nbr_current;
    int nbr_online;
} team_t;

typedef struct arg_s
{
    char *port;
    int width;
    int height;
    team_t **teams;
    int clients_nbr;
    int freq;
} arg_t;

typedef struct server_s
{
    bool quit_server;
    fd_set set[3];
    arg_t arg;
    cell_t ***map;
    client_t *clients;
    socket_t sock;
} server_t;

typedef struct reply_server_s
{
    int code;
    char *message;
} reply_server_t;

typedef struct cmd_s
{
    char *name;
    int (*fnct)(client_t *, char **);
    int nbr_param;
    int tick_cost;
} cmd_t;

typedef struct ritual_s
{
    int level;
    int nbr_player;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} ritual_t;

    /* Prototypes */
// Main
int server_start(int ac, char *av[], char *env[]);

// Tools
int check_arg(int ac, char **av, char **env);
server_t *get_server(void);
void print_map(void);
char *generate_uuid(void);
int nbr_player_on_cell(int x, int y);
bool add_player_to_cell(int x, int y, client_t *client);
bool remove_player_to_cell(int x, int y, client_t *client);
bool change_player_to_cell(int x_old, int y_old, int x_new, int y_new,
client_t *client);
client_t *destroy_client(client_t *save);
void send_map_to_graphics_clients(void);
void regene_resources_map(void);
void place_random_player(client_t *client);
void calcul_new_position(int *x, int *y, int offset_x, int offset_y);
void research_player_in_map(int *x, int *y, client_t *client);
void condition_win(void);
void regene_sibur(server_t *server);
void regene_mendiane(server_t *server);
void regene_phiras(server_t *server);
void regene_thystame(server_t *server);
void research_player_in_map(int *x, int *y, client_t *client);
team_t *create_new_team(char *name, int nbr_max);
void change_value_teams_liste_nbr_client(int nbr_max);
bool special_case_egg(client_t *client, int index_team_name);
void special_case_fork_norme(server_t *server, client_t *cli);
void condition_end(void);
void special_case_ritual(client_t *client);
void up_free_place_in_team(client_t *client);
int total_ressource_in_case(int x, int y);
int check_param_width_and_height(server_t *server);

// Message - Reply Server
bool reply_server(int code, int socket, char *message);

// Management - Handler
int handle_new_client(server_t *server);
bool init_server(void);
void handle_ctr_c(int useless);
int read_data_from_client(client_t *client);
value_return_t loop_server(void);
value_return_t launch_server(void);
value_return_t destroy_server(void);
char **handle_split_mutil_cmd(char *cmd);
bool create_map(void);
void place_random_player(client_t *client);
char **my_str_to_word_array(char const *str);

// Loop
void loop_execute_cmd(void);

// Commands
char **check_commands(client_t *client, char *cmd);
bool is_extension_of_write_cell(int x, int y, server_t *s);
bool is_death(client_t *client);
char *direction_look_eject(int look, client_t *cli);
void take_next_command(client_t *client);
int left(client_t *client, char **param);
int right(client_t *client, char **param);
int forward(client_t *client, char **param);
int look(client_t *client, char **param);
int inventory(client_t *client, char **param);
int connect_nbr(client_t *client, char **param);
int take_object(client_t *client, char **param);
int set_object(client_t *client, char **param);
int eject(client_t *client, char **param);
int fork_cmd(client_t *client, char **param);
int incantation(client_t *client, char **param);
int broadcast_transmit(client_t *client, char **param);

    /* List Commands */
static const cmd_t list_commands[13] = {
    {"Forward", &forward, 0, 7},
    {"Right", &right, 0, 7},
    {"Left", &left, 0, 7},
    {"Look", &look, 0, 7},
    {"Inventory", &inventory, 0, 1},
    {"Broadcast", &broadcast_transmit, -1, 7},
    {"Connect_nbr", &connect_nbr, 0, 0},
    {"Fork", &fork_cmd, 1, 42},
    {"Eject", &eject, 0, 7},
    {"Take", &take_object, 1, 7},
    {"Set", &set_object, 1, 7},
    {"Incantation", &incantation, 1, 300},
    {NULL, NULL, 0, 0},
};

static const reply_server_t list_reply[14] = {
    // Success (200):
    {200, "ok\n"},
    {201, "%s\n"}, // Connect nbr | BroadCast
    {202, "[%s]\n"}, // look and inventary
    {203, "eject: %s\n"}, // eject
    {204, "dead\n"}, // died
    {205, "%s\n"}, // win
    {206, "Elevation underway\n"}, // win
    {207, "Current level: %s\n"},
    // Error Classic (400):
    {404, "ko\n"},
    // Error Special (+500):
    {500, "ko\n"}, // Invalid command
    {501, "ko\n"}, // Parsing Erreur
    {502, "ko\n"}, // Command not found
    {503, "ko\n"}, // Invalid parameter
    {0, NULL},
};

static const ritual_t list_ritual[7] = {
    {1, 1, 1, 0, 0, 0, 0, 0},
    {2, 2, 1, 1, 1, 0, 0, 0},
    {3, 2, 2, 0, 1, 0, 2, 0},
    {4, 4, 1, 1, 2, 0, 1, 0},
    {5, 4, 1, 2, 1, 3, 0, 0},
    {6, 6, 1, 2, 3, 0, 1, 0},
    {7, 6, 2, 2, 2, 2, 2, 1},
};

#endif /* !ZAPPY_H_ */
