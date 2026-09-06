/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#include "data_base.h"

client_t *add_new_client(client_t *new_client)
{
    data_base_t *db = get_data_base();

    if (db->clients)
        new_client->next = db->clients;
    else
        new_client->next = NULL;
    db->clients = new_client;
    return (new_client);
}

client_t *add_new_client_init(char *user_name, char *id)
{
    data_base_t *db = get_data_base();
    client_t *new_client = calloc(1, sizeof(*new_client));

    if (!new_client)
        return (NULL);
    strcpy(new_client->id, (id && strlen(id)) ? id : generate_uuid());
    new_client->login_password = false;
    new_client->client_close = false;
    new_client->online = true;
    new_client->socket = 0;
    new_client->team = NULL;
    strcpy(new_client->user_name,
        (user_name && strlen(user_name) <= DEFAULT_NAME_LENGTH &&
        strlen(user_name)) ? user_name : "No Name Client");
    new_client->next = NULL;
    if (db->clients)
        new_client->next = db->clients;
    db->clients = new_client;
    return (new_client);
}

client_t *add_client_to_team(char *id_client, char *id_team)
{
    data_base_t *db = get_data_base();
    client_t *head = db->clients;
    client_t *save = NULL;
    list_index_t *new_element = calloc(1, sizeof(*new_element));

    if (!new_element || !id_team || !strlen(id_team)
        || !id_client || !strlen(id_client)) return (NULL);
    while (db->clients) {
        if (strcmp(db->clients->id, id_client) == 0) {
            strcpy(new_element->id, id_team);
            new_element->next = db->clients->team;
            db->clients->team = new_element;
            save = db->clients;
            db->clients = head;
            return (save);
        }
        db->clients = db->clients->next;
    }
    db->clients = head;
    return (NULL);
}

client_t *find_client_by_id(char *id)
{
    data_base_t *db = get_data_base();
    client_t *head = db->clients;
    client_t *save = NULL;

    if (!id || strlen(id) == 0)
        return (NULL);
    while (db->clients) {
        if (strcmp(db->clients->id, id) == 0) {
            save = db->clients;
            db->clients = head;
            return (save);
        }
        db->clients = db->clients->next;
    }
    db->clients = head;
    return (NULL);
}

client_t *find_client_by_name(char *name)
{
    data_base_t *db = get_data_base();
    client_t *head = db->clients;
    client_t *save = NULL;

    if (!name || strlen(name) == 0)
        return (NULL);
    while (db->clients) {
        if (strcmp(db->clients->user_name, name) == 0) {
            save = db->clients;
            db->clients = head;
            return (save);
        }
        db->clients = db->clients->next;
    }
    db->clients = head;
    return (NULL);
}
