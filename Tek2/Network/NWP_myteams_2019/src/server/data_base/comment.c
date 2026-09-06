/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment
*/

#include "data_base.h"

comment_t *add_new_comment_init(char *message, char *id_thread,
    char *id, time_t *timestamp)
{
    data_base_t *db = get_data_base();
    comment_t *new_comment = calloc(1, sizeof(*new_comment));

    if (!new_comment || !id_thread || (strlen(id_thread)) != SIZE_ID_UUID - 1)
        return (NULL);
    strcpy(new_comment->id, (id && strlen(id)) ? id : generate_uuid());
    strcpy(new_comment->linked_id_thread, id_thread);
    new_comment->timestamp = (timestamp) ? time(timestamp) : time(NULL);
    if (message && strlen(message) <= DEFAULT_BODY_LENGTH && strlen(message))
        strcpy(new_comment->message, message);
    else
        strcpy(new_comment->message, "No Name Comment");
    new_comment->next = NULL;
    if (db->comments)
        new_comment->next = db->comments;
    db->comments = new_comment;
    return (new_comment);
}

comment_t *find_comment(char *id)
{
    data_base_t *db = get_data_base();
    comment_t *head = db->comments;
    comment_t *save = NULL;

    if (!id || strlen(id) == 0)
        return (NULL);
    while (db->comments) {
        if (strcmp(db->comments->id, id) == 0) {
            save = db->comments;
            db->comments = head;
            return (save);
        }
        db->comments = db->comments->next;
    }
    db->comments = head;
    return (NULL);
}

void display_comment_info(comment_t *comment)
{
    if (comment == NULL)
        return;
    fprintf(stdout, "+---------------------------+\n");
    fprintf(stdout, " - id: '%s'\n", comment->id);
    fprintf(stdout, " - linked_id_thread: '%s'\n", comment->linked_id_thread);
    fprintf(stdout, " - message: '%s'\n", comment->message);
    if (!comment->next)
        fprintf(stdout, "+---------------------------+\n");
}

void display_list_comments_info(void)
{
    data_base_t *db = get_data_base();
    comment_t *save = db->comments;

    if (!db->comments)
        return;
    fprintf(stdout, "\n");
    while (db->comments) {
        display_comment_info(db->comments);
        db->comments = db->comments->next;
    }
    fprintf(stdout, "\n");
    db->comments = save;
}
