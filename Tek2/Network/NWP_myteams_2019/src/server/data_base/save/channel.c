/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel
*/

#include "data_base.h"

bool save_channels(void)
{
    data_base_t *db = get_data_base();
    channel_t *save = db->channels;
    int size = 0;
    char size_str[30] = {0};
    int fd = open("./.data_base/save_file_channels.txt", O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if ((fd = open("./.data_base/save_file_channels.txt", O_RDWR)) == -1)
        return (false);
    for (; db->channels; db->channels = db->channels->next)
        size++;
    db->channels = save;
    sprintf(size_str, "%d\n", size);
    write(fd, MAGIC_NBR, strlen(MAGIC_NBR));
    write(fd, size_str, strlen(size_str));
    for (channel_t *tmp = save; tmp; tmp = tmp->next)
        write(fd, tmp, sizeof(*tmp));
    close(fd);
    return (true);
}

bool restore_channels(void)
{
    data_base_t *db = get_data_base();
    channel_t *tmp = calloc(1, sizeof(channel_t));
    FILE *fd = fopen("./.data_base/save_file_channels.txt", "rb");
    char *line = calloc(123, 1);
    size_t size_read = 0;

    if ((fd == NULL)) return (false);
    if ((getline(&line, &size_read, fd) < 0) || !line
        || (strcmp(line, MAGIC_NBR) != 0) ||
        (getline(&line, &size_read, fd) < 0) || !line)
        return (fclose(fd) && false);
    for (int size = atoi(line); size > 0; size--) {
        if (fread(tmp, sizeof(channel_t), 1, fd) == 0 || !tmp ||
            !add_new_channel_init(tmp->name, tmp->linked_id_team, tmp->id,
            tmp->description)) {
            db->channels = NULL;
            return (fclose(fd) && false);
        }
    }
    return (!fclose(fd) && true);
}
