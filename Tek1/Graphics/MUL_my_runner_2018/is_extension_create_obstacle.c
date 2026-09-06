/*
** EPITECH PROJECT, 2018
** is_create_obstacle
** File description:
** is_create_obstacle
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "time.h"

char *get_next_line(int fd);
int my_putstr(char const *str);

int open_file(char *av[], int ac)
{
    int fd = 1;

    if (ac < 2) {
        my_putstr("Not enough argument.\n");
        return (-1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    return (fd);
}

void is_extension_func_add_element(variable_t *sf, list_obj_t *obj, int i)
{
    if (i == 1) {
        sf->obj->position.y = 643;
        sf->obj->rect.top = 0;
        sf->obj->rect.height = 136;
    }
    else {
        obj->position.y = 643;
        obj->rect.top = 0;
        obj->rect.height = 136;
    }
}

void add_element(int left, int i, variable_t *sf)
{
    list_obj_t *obj = malloc(sizeof(*obj));

    if (i == 1) {
        sf->obj = obj;
        sf->obj->position.x = ((i * 350) + 1600) + (rand() % ((20 - 10) + 10));
        is_extension_func_add_element(sf, obj, i);
        sf->obj->rect.left = left;
        sf->obj->rect.width = (73 + 73 * ((rand() % (3 - 1) + 1) / 2)) - 3;
        sf->obj->next = NULL;
    }
    else {
        obj->position.x = ((i * 350) + 1600) + (rand() % ((20 - 10) + 10));
        is_extension_func_add_element(sf, obj, i);
        obj->rect.left = left;
        obj->rect.width = (73 + (73 * ((rand() % (3 - 1) + 1) / 2))) - 3;
        obj->next = sf->obj;
        sf->obj = obj;
    }
}

int is_extension_gestion_obstacle(char charac)
{
    if (charac >= '1' && charac <= '9')
        return (1);
    return (0);
}