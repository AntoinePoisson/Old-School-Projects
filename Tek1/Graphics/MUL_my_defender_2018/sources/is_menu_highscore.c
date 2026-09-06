/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "is_menu_highscore.h"

char *data_highscore_file(int cas)
{
    int fd = open_file_highscore();
    char *result = malloc(sizeof(char) * 99999);
    static char *buffer = NULL;
    static int i_two = 0;

    if (cas == 0) {
        buffer = malloc(sizeof(char) * 99999);
        i_two = 0;
    }
    if (result == NULL || buffer == NULL || fd == -1 || (cas == 0 &&
        read(fd, buffer, 99999) < 1))
        return ("ERROR");
    for (int i = 0; buffer[i_two] != '|' && buffer[i] != '\0'; i++, i_two++) {
        result[i] = buffer[i_two];
        result[i + 1] = '\0';
    }
    i_two++;
    close(fd);
    return (result);
}

int check_file_highscore(void)
{
    int fd = open_file_highscore();
    int nbr = 0;
    char *fil = malloc(sizeof(char) * 99999);

    if (read(fd, fil, 99999) < 1 || analyse_file(fil, nbr) != 0) {
        my_putstr("Invalid Highscore file, Play.\n");
        return (84);
    }
    close(fd);
    return (0);
}

void highscore(variable_t *sf)
{
    if (check_file_highscore() != 0)
        return;
    create_bg_highscore(sf);
    create_text_highscore(sf);
    sf->vector.select.y = 0;
    transition_menu_to_highscore(sf);
    sf->vector.select.y = 0;
    sfSprite_setPosition(sf->sprite.menu, sf->vector.select);
    sfFont_destroy(sf->text.font_highscore);
    sfText_destroy(sf->text.text_highscore);
    sfSprite_destroy(sf->sprite.bg_highscore);
    sfTexture_destroy(sf->texture.bg_highscore);
}
