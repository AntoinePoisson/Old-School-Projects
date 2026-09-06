/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create hitbox map1
*/

#include <fcntl.h>
#include "my_rpg.h"

static int size_malloc_map_hitbox_beach(void)
{
    int fd = open("./assets/img/map/hitbox/before_donjon.txt", O_RDONLY);
    int size = 0;

    if (fd == -1)
        return (my_puterror("Cannot Open Map Hitbox of before donjon.\n"));
    for (char *line = NULL; line != NULL || size == 0; size++) {
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (size);
}

static int create_beach_map(game_t *game)
{
    int size = size_malloc_map_hitbox_beach();
    int fd = open("./assets/img/map/hitbox/before_donjon.txt", O_RDONLY);

    if (fd == -1 || size <= 2)
        return (84);
    if ((game->map.beach = malloc(sizeof(char *) * (999999))) == NULL)
        return (my_puterror("Failure Malloc.\n"));
    for (int i = 0; i < size; i++) {
        game->map.beach[i] = get_next_line(fd);
        game->map.beach[i + 1] = NULL;
    }
    close(fd);
    return (0);
}

int create_hitbox_map(game_t *game)
{
    if (create_beach_map(game) == 84)
        return (84);
    game->texture->donjon_hitbox =
        sfImage_createFromFile("./assets/img/map/hitbox/hitbox_donjon.png");
    if (game->texture->donjon_hitbox == NULL)
        return (84);
    return (0);
}
