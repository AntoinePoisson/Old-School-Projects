/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** print_map
*/

#include "zappy.h"

static void split_print_map_one(server_t *s, int y);
static void split_print_map_norme(server_t *s, int y);

void print_map(void)
{
    server_t *s = get_server();
    int size_name_team = 8;
    char name_team[8 + 1] = {0};

    for (int y = 0; s->map[y]; y++) {
        split_print_map_one(s, y);
        for (int x = 0; s->map[y][x]; x++) {
            memset(name_team, 0, size_name_team + 1);
            if (s->map[y][x]->players[0].player_team)
                strncpy(name_team, s->map[y][x]->players[0].player_team,
                size_name_team);
            printf("| thys: %d, Team: %s\t", s->map[y][x]->thystame,
                strlen(name_team) ? name_team : "");
        }
        split_print_map_norme(s, y);
    }
    printf("\n");
    for (int x = 0; s->map[0][x]; x++)
        printf("-----------------------");
    printf("\n");
}

static void split_print_map_one(server_t *s, int y)
{
    printf("\n");
    for (int x = 0; s->map[y][x]; x++)
        printf("-----------------------");
    printf("\n\n");
    for (int x = 0; s->map[y][x]; x++)
        printf("|    x: %d,    y: %d\t", s->map[y][x]->x, s->map[y][x]->y);
    printf("\n");
    for (int x = 0; s->map[y][x]; x++)
        printf("| food: %d, line: %d\t", s->map[y][x]->food,
        s->map[y][x]->linemate);
    printf("\n");
    for (int x = 0; s->map[y][x]; x++)
        printf("| dera: %d, sibu: %d\t", s->map[y][x]->deraumere,
        s->map[y][x]->sibur);
    printf("\n");
    for (int x = 0; s->map[y][x]; x++)
        printf("| mend: %d, phir: %d\t", s->map[y][x]->mendiane,
        s->map[y][x]->phiras);
    printf("\n");
}

static void split_print_map_norme(server_t *s, int y)
{
    printf("\n");
    for (int x = 0; s->map[y][x]; x++) {
        if (s->map[y][x]->players[0].look == Up)
            printf("| mend: %s,         \t", "Up");
        if (s->map[y][x]->players[0].look == Down)
            printf("| mend: %s,         \t", "Down");
        if (s->map[y][x]->players[0].look == Left)
            printf("| mend: %s,         \t", "Left");
        if (s->map[y][x]->players[0].look == Right)
            printf("| mend: %s,         \t", "Right");
        if (s->map[y][x]->players[0].look == None)
            printf("| mend: %s,        \t", "None");
    }
    printf("\n");
}