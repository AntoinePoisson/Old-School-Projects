/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init struct with file
*/

#include <fcntl.h>
#include "my_tab.h"
#include "my_rpg.h"

void find_var(char *line, game_t *game)
{
    char **tab = str_to_word_array(line, '=');

    for (long unsigned int j = 0; j < (sizeof(VAR) / sizeof(*VAR)); j++)
        for (int i = 0; tab[i]; i++)
            if (my_strncmp(VAR[j], tab[i], my_strlen(VAR[j])) == 0) {
                if (tab[++i])
                    assign_value(j, tab[i], game);
                return;
            }
}

void use_safe_file(game_t *game)
{
    int fd = open(".safe", 0);
    char **tab;

    if ((tab = fill_tab(fd)) == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        find_var(tab[i], game);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void init_struct(game_t *game)
{
    int fd;
    char *file = create_file1(&fd, ".conf");
    char **tab;

    init_game_var(game);
    if (file == NULL)
        return;
    if ((tab = fill_tab(fd)) == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        find_var(tab[i], game);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    use_safe_file(game);
}

void save_file(game_t *game)
{
    int fd;
    char *file = create_file2(&fd, ".safe");

    if (file == NULL)
        return;
    write_in_file(fd, game);
    close(fd);
}
