/*
** EPITECH PROJECT, 2019
** select_data.c
** File description:
** select data in parcing
*/

#include "parsing.h"

list_t *take_data(void)
{
    list_t *data = NULL;
    list_t *new_data = NULL;
    int fd = 0;
    char *stockage = (get_next_line(fd));

    while (stockage != NULL) {
        if ((new_data = malloc(sizeof(list_t))) == NULL)
            return (NULL);
        new_data->data = stockage;
        new_data->next = data;
        data = new_data;
        stockage = (get_next_line(fd));
    }
    return (data);
}

char **create_data(variable_t *var)
{
    list_t *data = take_data();
    list_t *save = data;
    int size = 0;

    if (data == NULL)
        return (NULL);
    for (; save; size++, save = save->next) {
    }
    var->data_arg = my_malloc_two_d(size + 1);
    for (int i = size - 1; i >= 0; i--) {
        var->data_arg[i] = select_begin(data->data);
        data = data->next;
    }
    return (var->data_arg);
}

int failure_parsing(variable_t *var)
{
    if (var->nbr_ants <= 0)
        return (84);
    if (var->start == NULL)
        return (84);
    if (var->end == NULL)
        return (84);
    if (var->room == NULL)
        return (84);
    if (check_end_start_link(var) == 84)
        return (84);
    return (0);
}

int is_extension_management_parsing(variable_t *var, int value_return, int cas,
    int i)
{
    if (cas == 1 && failure_parsing(var) != 84) {
        my_puterror("warning: '");
        my_puterror(var->data_arg[i]);
        my_puterror("' stopped the parsing.\n");
        my_puterror("warning: parsing success !\n");
        var->data_arg[i] = NULL;
        return (0);
    }
    my_puterror("warning: '");
    my_puterror(var->data_arg[i]);
    my_puterror("' stopped the parsing.\n");
    var->data_arg[i] = NULL;
    if (failure_parsing(var) == 84) {
        my_puterror("error: fatal errors parsing !\n");
        return (84);
    } else {
        my_puterror("warning: parsing success !\n");
        return (0);
    }
    return (value_return);
}
