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
int open_file(char *av[], int ac);
void is_extension_func_add_element(variable_t *sf, list_obj_t *obj, int i);
void add_element(int left, int i, variable_t *sf);
int is_extension_gestion_obstacle(char charac);

int gestion_obstacle(char charac, variable_t *sf, int i)
{
    if (charac == '1')
        add_element(0, i, sf);
    if (charac == '2')
        add_element(73, i, sf);
    if (charac == '3')
        add_element(146, i, sf);
    if (charac == '4')
        add_element(219, i, sf);
    if (charac == '5')
        add_element(292, i, sf);
    if (charac == '6')
        add_element(365, i, sf);
    if (charac == '7')
        add_element(438, i, sf);
    if (charac == '8')
        add_element(511, i, sf);
    if (charac == '9')
        add_element(584, i, sf);
    return (is_extension_gestion_obstacle(charac));
}

void do_circular_linked_list(variable_t *sf)
{
    list_obj_t *save = sf->obj;

    while (sf->obj->next != NULL)
        sf->obj = sf->obj->next;
    sf->obj->next = save;
}

int is_extension_is_create_obstacle(variable_t *sf, int nbr_obstacle)
{
    sf->var_norm.nbr_obstacle = nbr_obstacle;
    do_circular_linked_list(sf);
    return (0);
}

int is_create_obstacle(char *av[], int ac, variable_t *sf)
{
    int fd = open_file(av, ac);
    static int nbr_obstacle = 0;
    static char *line;

    if (nbr_obstacle == 0)
        line = get_next_line(fd);
    else
        nbr_obstacle = 0;
    if (line == NULL || fd == -1) {
        my_putstr("Can not read the file.\n");
        return (84);
    }
    for (int i = 0; line[i] != '\0'; i++)
        nbr_obstacle += gestion_obstacle(line[i], sf, (i + 1));
    close(fd);
    if (nbr_obstacle == 0) {
        my_putstr("No obstacle in file.\n");
        return (84);
    }
    return (is_extension_is_create_obstacle(sf, nbr_obstacle));
}
