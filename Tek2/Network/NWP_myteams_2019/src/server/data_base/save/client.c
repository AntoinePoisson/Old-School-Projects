/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#include "data_base.h"

static void write_one_client(int fd, client_t *client);
static bool read_list_index_client(FILE *fd, char *id);
static client_t *close_client(client_t *client);

bool save_clients(void)
{
    data_base_t *db = get_data_base();
    client_t *save = db->clients;
    int size = 0;
    char size_str[30] = {0};
    int fd = open("./.data_base/save_file_clients.txt", O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if ((fd = open("./.data_base/save_file_clients.txt", O_RDWR)) == -1)
        return (false);
    for (; db->clients; db->clients = db->clients->next)
        size++;
    db->clients = save;
    sprintf(size_str, "%d\n", size);
    write(fd, MAGIC_NBR, strlen(MAGIC_NBR));
    write(fd, size_str, strlen(size_str));
    for (client_t *tmp = save; tmp; tmp = tmp->next)
        write_one_client(fd, close_client(tmp));
    close(fd);
    return (true);
}

bool restore_clients(void)
{
    data_base_t *db = get_data_base();
    client_t *tmp = calloc(1, sizeof(client_t));
    FILE *fd = fopen("./.data_base/save_file_clients.txt", "rb");
    char *line = calloc(123, 1);
    size_t size_read = 0;

    if ((fd == NULL))
        return (false);
    if ((getline(&line, &size_read, fd) < 0) || !line
        || (strcmp(line, MAGIC_NBR) != 0) ||
        (getline(&line, &size_read, fd) < 0) || !line)
        return (fclose(fd) && false);
    for (int size = atoi(line); size > 0; size--)
        if (fread(tmp, sizeof(client_t), 1, fd) == 0 || !tmp ||
            !add_new_client_init(tmp->user_name, tmp->id) ||
            !read_list_index_client(fd, tmp->id)) {
            db->clients = NULL;
            return (fclose(fd) && false);
        }
    return (!fclose(fd) && true);
}

static void write_one_client(int fd, client_t *client)
{
    list_index_t *element = client->team;
    int size_team = 0;
    char size_str[30] = {0};

    write(fd, client, sizeof(*client));
    for (; client->team; client->team = client->team->next) {
        size_team++;
    }
    client->team = element;
    sprintf(size_str, "%d\n", size_team);
    write(fd, size_str, strlen(size_str));
    for (list_index_t *it = element; it; it = it->next) {
        write(fd, it, sizeof(list_index_t));
    }
}

static bool read_list_index_client(FILE *fd, char *id)
{
    char *line = calloc(123, 1);
    size_t size_read = 0;
    list_index_t *new_element = calloc(1, sizeof(*new_element));

    if (getline(&line, &size_read, fd) < 0 || !line || !strlen(line)
        || !(line[0] >= '0' && line[0] <= '9') || !id)
        return (false);
    for (int nbr_element = atoi(line); nbr_element > 0; nbr_element--) {
        if (fread(new_element, sizeof(list_index_t), 1, fd) == 0
            || !add_client_to_team(id, new_element->id)) {
            return (false);
        }
    }
    return (true);
}

static client_t *close_client(client_t *client)
{
    if (client) {
        client->client_close = true;
        client->login_password = false;
        client->online = false;
        client->socket = 0;
        memset(client->use_channel, 0, strlen(client->use_channel));
        memset(client->use_team, 0, strlen(client->use_team));
        memset(client->use_thread, 0, strlen(client->use_thread));
    }
    return (client);
}