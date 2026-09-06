/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** data_base
*/

#include "data_base.h"
#include "logging_server.h"

data_base_t *get_data_base(void)
{
    static data_base_t db = {0};

    return (&db);
}

data_base_t *init_data_base(data_base_t *db)
{
    if (!(restore_teams() && restore_channels() && restore_threads()
        && restore_comments() && restore_discussions()
        && restore_clients())) {
        fprintf(stdout, "\n[Error] Fail Recovery Data Base\n");
        db->teams = NULL;
        db->channels = NULL;
        db->threads = NULL;
        db->comments = NULL;
        db->discussions = NULL;
        db->clients = NULL;
    } else {
        for (client_t *s = db->clients; s; s = s->next)
            server_event_user_loaded(s->id, s->user_name);
        fprintf(stdout, "\n[Success] Recovery Data Base\n");
    }
    return (db);
}

bool save_data_base(void)
{
    bool not_stop_save = true;

    if ((not_stop_save = save_teams()) == false)
        remove("./save/.data_base/save_file_teams.txt");
    if (not_stop_save && (not_stop_save = save_channels()) == false)
        remove("./save/.data_base/save_file_channels.txt");
    if (not_stop_save && (not_stop_save = save_threads()) == false)
        remove("./save/.data_base/save_file_threads.txt");
    if (not_stop_save && (not_stop_save = save_comments()) == false)
        remove("./save/.data_base/save_file_comments.txt");
    if (not_stop_save && (not_stop_save = save_discussions()) == false)
        remove("./save/.data_base/save_file_discussions.txt");
    if (not_stop_save && (not_stop_save = save_clients()) == false)
        remove("./save/.data_base/save_file_clients.txt");
    if (!not_stop_save)
        fprintf(stdout, "\n[Error] Fail Save Data Base\n");
    else
        fprintf(stdout, "\n[Success] Save Data Base\n");
    return (not_stop_save ? true : false);
}

char *generate_uuid(void)
{
    uuid_t binuuid;
    char uuid[37] = {0};

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    return (strdup(uuid));
}