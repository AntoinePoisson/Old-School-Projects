/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** discussions
*/

#include "data_base.h"

discussion_t *add_new_discussion_init(char *message, char *id_send,
char *id_reveice, time_t *timestamp)
{
    data_base_t *db = get_data_base();
    discussion_t *new_discussion = calloc(1, sizeof(*new_discussion));

    if (!new_discussion || !id_send || (strlen(id_send)) != SIZE_ID_UUID - 1
        || !id_reveice || (strlen(id_reveice)) != SIZE_ID_UUID - 1)
        return (NULL);
    strcpy(new_discussion->id_client_send,
        (id_send && strlen(id_send)) ? id_send : generate_uuid());
    strcpy(new_discussion->id_client_reveice,
        (id_reveice && strlen(id_reveice)) ? id_reveice : generate_uuid());
    new_discussion->timestamp = *timestamp;
    if (message && strlen(message) <= DEFAULT_BODY_LENGTH && strlen(message))
        strcpy(new_discussion->message, message);
    else
        strcpy(new_discussion->message, "No Name Discussion");
    new_discussion->next = NULL;
    if (db->discussions)
        new_discussion->next = db->discussions;
    db->discussions = new_discussion;
    return (new_discussion);
}

discussion_t *find_discussion_send_message_first(char *id_send)
{
    data_base_t *db = get_data_base();
    discussion_t *head = db->discussions;
    discussion_t *save = NULL;

    while (db->discussions) {
        if (strcmp(db->discussions->id_client_send, id_send) == 0) {
            save = db->discussions;
            db->discussions = head;
            return (save);
        }
        db->discussions = db->discussions->next;
    }
    db->discussions = head;
    return (NULL);
}

discussion_t *find_discussion_reveice_message_first(char *id_client_reveice)
{
    data_base_t *db = get_data_base();
    discussion_t *head = db->discussions;
    discussion_t *save = NULL;

    if (!id_client_reveice || strlen(id_client_reveice) == 0)
        return (NULL);
    while (db->discussions) {
        if (strcmp(db->discussions->id_client_reveice,
            id_client_reveice) == 0) {
            save = db->discussions;
            db->discussions = head;
            return (save);
        }
        db->discussions = db->discussions->next;
    }
    db->discussions = head;
    return (NULL);
}

void display_discussion_info(discussion_t *discussion)
{
    if (discussion == NULL)
        return;
    fprintf(stdout, "+---------------------------+\n");
    fprintf(stdout, " - id_client_send: '%s'\n", discussion->id_client_send);
    fprintf(stdout, " - id_client_reveice: '%s'\n",
        discussion->id_client_reveice);
    fprintf(stdout, " - message: '%s'\n", discussion->message);
    if (!discussion->next)
        fprintf(stdout, "+---------------------------+\n");
}

void display_list_discussions_info(void)
{
    data_base_t *db = get_data_base();
    discussion_t *save = db->discussions;

    if (!db->discussions)
        return;
    fprintf(stdout, "\n");
    while (db->discussions) {
        display_discussion_info(db->discussions);
        db->discussions = db->discussions->next;
    }
    fprintf(stdout, "\n");
    db->discussions = save;
}
