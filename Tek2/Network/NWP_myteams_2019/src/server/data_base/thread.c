/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread
*/

#include "data_base.h"

static thread_t *add_new_thread_init_norme(char *name, char *body,
thread_t *new_thread);

thread_t *add_new_thread_init(char *name, char *id_channel, char *id,
    char *creator, time_t *timestamp, char *body)
{
    data_base_t *db = get_data_base();
    thread_t *new_thread = calloc(1, sizeof(*new_thread));

    if (!new_thread || !id_channel || (strlen(id_channel) != SIZE_ID_UUID - 1)
        || !creator || (strlen(creator) != SIZE_ID_UUID - 1))
        return (NULL);
    strcpy(new_thread->id, (id && strlen(id)) ? id : generate_uuid());
    strcpy(new_thread->linked_id_channel, id_channel);
    strcpy(new_thread->creator, creator);
    new_thread->timestamp = (timestamp) ? time(timestamp) : time(NULL);
    new_thread = add_new_thread_init_norme(name, body, new_thread);
    new_thread->next = NULL;
    if (db->threads)
        new_thread->next = db->threads;
    db->threads = new_thread;
    return (new_thread);
}

thread_t *find_thread(char *id)
{
    data_base_t *db = get_data_base();
    thread_t *head = db->threads;
    thread_t *save = NULL;

    if (!id || strlen(id) == 0)
        return (NULL);
    while (db->threads) {
        if (strcmp(db->threads->id, id) == 0) {
            save = db->threads;
            db->threads = head;
            return (save);
        }
        db->threads = db->threads->next;
    }
    db->threads = head;
    return (NULL);
}

void display_thread_info(thread_t *thread)
{
    if (thread == NULL)
        return;
    fprintf(stdout, "+---------------------------+\n");
    fprintf(stdout, " - id: '%s'\n", thread->id);
    fprintf(stdout, " - linked_id_channel: '%s'\n", thread->linked_id_channel);
    fprintf(stdout, " - name: '%s'\n", thread->name);
    fprintf(stdout, " - creator: '%s'\n", thread->creator);
    fprintf(stdout, " - body: '%s'\n", thread->body);
    if (!thread->next)
        fprintf(stdout, "+---------------------------+\n");
}

void display_list_threads_info(void)
{
    data_base_t *db = get_data_base();
    thread_t *save = db->threads;

    if (!db->threads)
        return;
    fprintf(stdout, "\n");
    while (db->threads) {
        display_thread_info(db->threads);
        db->threads = db->threads->next;
    }
    fprintf(stdout, "\n");
    db->threads = save;
}

static thread_t *add_new_thread_init_norme(char *name, char *body,
    thread_t *new_thread)
{
    if (name && strlen(name) <= DEFAULT_NAME_LENGTH && strlen(name))
        strcpy(new_thread->name, name);
    else
        strcpy(new_thread->name, "No Name Thread");
    if (body && strlen(body) <= DEFAULT_BODY_LENGTH && strlen(body))
        strcpy(new_thread->body, body);
    else
        strcpy(new_thread->body, "No Body");
    return (new_thread);
}