/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#include "data_base.h"

team_t *add_new_team_init(char *name, char *descript, char *id)
{
    data_base_t *db = get_data_base();
    team_t *new_team = calloc(1, sizeof(*new_team));

    if (!new_team) return (NULL);
    strcpy(new_team->id, (id && strlen(id)) ? id : generate_uuid());
    if (name && strlen(name) <= DEFAULT_NAME_LENGTH && strlen(name))
        strcpy(new_team->name, name);
    else
        strcpy(new_team->name, "No Name Team");
    if (descript && strlen(descript) <= DEFAULT_BODY_LENGTH &&
        strlen(descript))
        strcpy(new_team->description, descript);
    else
        strcpy(new_team->description, "No Description");
    new_team->next = NULL;
    if (db->teams)
        new_team->next = db->teams;
    db->teams = new_team;
    return (new_team);
}

team_t *find_team(char *id)
{
    data_base_t *db = get_data_base();
    team_t *head = db->teams;
    team_t *save = NULL;

    if (!id || strlen(id) == 0)
        return (NULL);
    while (db->teams) {
        if (strcmp(db->teams->id, id) == 0) {
            save = db->teams;
            db->teams = head;
            return (save);
        }
        db->teams = db->teams->next;
    }
    db->teams = head;
    return (NULL);
}

void display_team_info(team_t *team)
{
    if (team == NULL)
        return;
    fprintf(stdout, "+---------------------------+\n");
    fprintf(stdout, " - id: '%s'\n", team->id);
    fprintf(stdout, " - name: '%s'\n", team->name);
    fprintf(stdout, " - description: '%s'\n", team->description);
    if (!team->next)
        fprintf(stdout, "+---------------------------+\n");
}

void display_list_teams_info(void)
{
    data_base_t *db = get_data_base();
    team_t *save = db->teams;

    if (!db->teams)
        return;
    fprintf(stdout, "\n");
    while (db->teams) {
        display_team_info(db->teams);
        db->teams = db->teams->next;
    }
    fprintf(stdout, "\n");
    db->teams = save;
}
