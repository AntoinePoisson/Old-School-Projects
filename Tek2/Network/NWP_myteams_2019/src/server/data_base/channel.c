/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel
*/

#include "data_base.h"

channel_t *add_new_channel_init(char *name, char *id_team, char *id,
    char *description)
{
    data_base_t *db = get_data_base();
    channel_t *new_channel = calloc(1, sizeof(*new_channel));

    if (!new_channel || !id_team || (strlen(id_team)) != SIZE_ID_UUID - 1)
        return (NULL);
    strcpy(new_channel->id, (id && strlen(id)) ? id : generate_uuid());
    strcpy(new_channel->linked_id_team, id_team);
    if (name && strlen(name) <= DEFAULT_NAME_LENGTH && strlen(name))
        strcpy(new_channel->name, name);
    else
        strcpy(new_channel->name, "No Name Channel");
    if (description && strlen(description) <= DEFAULT_NAME_LENGTH &&
        strlen(description))
        strcpy(new_channel->description, description);
    else
        strcpy(new_channel->description, "No Description");
    new_channel->next = NULL;
    if (db->channels) new_channel->next = db->channels;
    db->channels = new_channel;
    return (new_channel);
}

channel_t *find_channel(char *id)
{
    data_base_t *db = get_data_base();
    channel_t *head = db->channels;
    channel_t *save = NULL;

    if (!id || strlen(id) == 0)
        return (NULL);
    while (db->channels) {
        if (strcmp(db->channels->id, id) == 0) {
            save = db->channels;
            db->channels = head;
            return (save);
        }
        db->channels = db->channels->next;
    }
    db->channels = head;
    return (NULL);
}

void display_channel_info(channel_t *channel)
{
    if (channel == NULL)
        return;
    fprintf(stdout, "+---------------------------+\n");
    fprintf(stdout, " - id: '%s'\n", channel->id);
    fprintf(stdout, " - linked_id_team: '%s'\n", channel->linked_id_team);
    fprintf(stdout, " - name: '%s'\n", channel->name);
    fprintf(stdout, " - description: '%s'\n", channel->description);
    if (!channel->next)
        fprintf(stdout, "+---------------------------+\n");
}

void display_list_channels_info(void)
{
    data_base_t *db = get_data_base();
    channel_t *save = db->channels;

    if (!db->channels)
        return;
    fprintf(stdout, "\n");
    while (db->channels) {
        display_channel_info(db->channels);
        db->channels = db->channels->next;
    }
    fprintf(stdout, "\n");
    db->channels = save;
}
