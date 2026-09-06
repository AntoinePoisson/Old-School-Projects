/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment
*/

#include "data_base.h"

bool save_comments(void)
{
    data_base_t *db = get_data_base();
    comment_t *save = db->comments;
    int size = 0;
    char size_str[30] = {0};
    int fd = open("./.data_base/save_file_comments.txt", O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if ((fd = open("./.data_base/save_file_comments.txt", O_RDWR)) == -1)
        return (false);
    for (; db->comments; db->comments = db->comments->next)
        size++;
    db->comments = save;
    sprintf(size_str, "%d\n", size);
    write(fd, MAGIC_NBR, strlen(MAGIC_NBR));
    write(fd, size_str, strlen(size_str));
    for (comment_t *tmp = save; tmp; tmp = tmp->next)
        write(fd, tmp, sizeof(*tmp));
    close(fd);
    return (true);
}

bool restore_comments(void)
{
    data_base_t *db = get_data_base();
    comment_t *tmp = calloc(1, sizeof(comment_t));
    FILE *fd = fopen("./.data_base/save_file_comments.txt", "rb");
    char *line = calloc(123, 1);
    size_t size_read = 0;

    if ((fd == NULL))
        return (false);
    if ((getline(&line, &size_read, fd) < 0) || !line
        || (strcmp(line, MAGIC_NBR) != 0) ||
        (getline(&line, &size_read, fd) < 0) || !line)
        return (fclose(fd) && false);
    for (int size = atoi(line); size > 0; size--)
        if (fread(tmp, sizeof(comment_t), 1, fd) == 0 || !tmp ||
            !add_new_comment_init(tmp->message,
            tmp->linked_id_thread, tmp->id, &tmp->timestamp)) {
            db->comments = NULL;
            return (fclose(fd) && false);
        }
    return (!fclose(fd) && true);
}

void display_client_info(client_t *client)
{
    if (client == NULL)
        return;
    fprintf(stdout, "+---------------------------+\n");
    fprintf(stdout, " - id: '%s'\n", client->id);
    fprintf(stdout, " - user_name: '%s'\n", client->user_name);
    fprintf(stdout, " - login_password: %s\n", client->login_password ? "true"
    : "false");
    fprintf(stdout, " - client_close: %s\n", client->client_close ? "true"
    : "false");
    fprintf(stdout, " - online: %s\n", client->online ? "true" : "false");
    fprintf(stdout, " - socket: %d\n - list_team: ", client->socket);
    for (list_index_t *it = client->team; it; it = it->next) {
        fprintf(stdout, "%s, ", it->id);
    }
    if (!client->next)
        fprintf(stdout, "\n+---------------------------+\n");
    else
        fprintf(stdout, "\n");
}

void display_list_clients_info(void)
{
    data_base_t *db = get_data_base();
    client_t *save = db->clients;

    if (!db->clients)
        return;
    fprintf(stdout, "\n");
    while (db->clients) {
        display_client_info(db->clients);
        db->clients = db->clients->next;
    }
    fprintf(stdout, "\n");
    db->clients = save;
}
