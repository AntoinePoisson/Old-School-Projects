/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** data_base
*/

#ifndef DATA_BASE_H_
#define DATA_BASE_H_

    /* Includes System */
#include <stdbool.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>


    /* Defines */
# define MAGIC_NBR "32za3\n"
# define DEFAULT_NAME_LENGTH 32
# define DEFAULT_DESCRIPTION_LENGTH 255
# define DEFAULT_BODY_LENGTH 512
# define SIZE_ID_UUID 37


    /* Structure */
// Tools
typedef struct list_index_s
{
    char id[SIZE_ID_UUID];
    struct list_index_s *next;
} list_index_t;


// Data
typedef struct team_s
{
    char id[SIZE_ID_UUID];

    char name[DEFAULT_NAME_LENGTH];
    char description[DEFAULT_BODY_LENGTH];
    struct team_s *next;
} team_t;

typedef struct channel_s
{
    char id[SIZE_ID_UUID];
    char linked_id_team[SIZE_ID_UUID];

    char name[DEFAULT_NAME_LENGTH];
    char description[DEFAULT_BODY_LENGTH];
    struct channel_s *next;
} channel_t;

typedef struct thread_s
{
    char id[SIZE_ID_UUID];
    char linked_id_channel[SIZE_ID_UUID];

    char name[DEFAULT_NAME_LENGTH];
    char creator[SIZE_ID_UUID];
    time_t timestamp;
    char body[DEFAULT_BODY_LENGTH];
    struct thread_s *next;
} thread_t;

typedef struct comment_s
{
    char id[SIZE_ID_UUID];
    char linked_id_thread[SIZE_ID_UUID];

    char message[DEFAULT_BODY_LENGTH];
    time_t timestamp;
    struct comment_s *next;
} comment_t;

typedef struct discussion_s
{
    char id_client_send[SIZE_ID_UUID];
    char id_client_reveice[SIZE_ID_UUID];

    char message[DEFAULT_BODY_LENGTH];
    time_t timestamp;
    struct discussion_s *next;
} discussion_t;

typedef struct client_s
{
    char id[SIZE_ID_UUID];
    char user_name[DEFAULT_NAME_LENGTH];
    char use_team[SIZE_ID_UUID];
    char use_channel[SIZE_ID_UUID];
    char use_thread[SIZE_ID_UUID];
    bool login_password;
    bool client_close;
    bool online;

    volatile int socket;
    list_index_t *team;
    struct client_s *next;
} client_t;


// Data Base
typedef struct data_base_s
{
    team_t *teams;
    channel_t *channels;
    thread_t *threads;
    comment_t *comments;
    discussion_t *discussions;
    client_t *clients;
} data_base_t;


    /* ProtoTypes */
// DataBase Tool
data_base_t *get_data_base(void);
data_base_t *init_data_base(data_base_t *db);
bool save_data_base(void);
char *generate_uuid(void);

// Client
client_t *add_new_client(client_t *new_client);
client_t *add_new_client_init(char *user_name, char *id);
client_t *add_client_to_team(char *id_client, char *id_team);
client_t *find_client_by_id(char *id);
client_t *find_client_by_name(char *name);
void display_client_info(client_t *client);
void display_list_clients_info(void);
bool save_clients(void);
bool restore_clients(void);

// Team
team_t *add_new_team_init(char *name, char *descript, char *id);
team_t *find_team(char *id);
void display_team_info(team_t *team);
void display_list_teams_info(void);
bool save_teams(void);
bool restore_teams(void);

// Channel
channel_t *add_new_channel_init(char *name, char *id_team, char *id,
    char *description);
channel_t *find_channel(char *id);
void display_channel_info(channel_t *channel);
void display_list_channels_info(void);
bool save_channels(void);
bool restore_channels(void);

// Thread
thread_t *add_new_thread_init(char *name, char *id_channel, char *id,
    char *creator, time_t *timestamp, char *body);
thread_t *find_thread(char *id);
void display_thread_info(thread_t *thread);
void display_list_threads_info(void);
bool save_threads(void);
bool restore_threads(void);

// Comment
comment_t *add_new_comment_init(char *message, char *id_thread,
    char *id, time_t *timestamp);
comment_t *find_comment(char *id);
void display_comment_info(comment_t *comment);
void display_list_comments_info(void);
bool save_comments(void);
bool restore_comments(void);

// Discussion
discussion_t *add_new_discussion_init(char *message, char *id_send,
    char *id_reveice, time_t *timestamp);
discussion_t *find_discussion_send_message_first(char *id_send);
discussion_t *find_discussion_reveice_message_first(char *id_client_reveice);
void display_discussion_info(discussion_t *discussion);
void display_list_discussions_info(void);
bool save_discussions(void);
bool restore_discussions(void);

#endif /* !DATA_BASE_H_ */
