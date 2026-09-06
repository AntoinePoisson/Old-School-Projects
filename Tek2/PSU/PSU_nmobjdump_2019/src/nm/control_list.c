/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** manipule_list
*/

#include "nm.h"

static char *create_sort_name(char *name)
{
    char *res = malloc((strlen(name) + 2));
    int cp = 0;

    if (res == NULL || name == NULL) {
        perror("malloc");
        exit(84);
    }
    for (int i = 0; name[i]; i++)
        if (name[i] != '_' && name[i] != '@') {
            res[cp++] = name[i];
            res[cp] = '\0';
        }
    return (res);
}

data_elf_t *add_node(data_elf_t *elf, char *name, unsigned int value,
char type)
{
    node_t *new = malloc(sizeof(*new));

    if (!new) {
        perror("malloc");
        exit(84);
    }
    new->name = name;
    new->name_sort = create_sort_name(name);
    new->value = value;
    new->type = type;
    new->next = NULL;
    if (!elf->list_sym) {
        elf->list_sym = new;
    } else {
        new->next = elf->list_sym;
        elf->list_sym = new;
    }
    return (elf);
}

void sort_list(data_elf_t *elf)
{
    bool modif = true;

    for (int count = 0; modif && count < 20; modif = false, count++) {
        modif = is_extension_sort_list(elf);
    }
}

bool check_all_no_value(node_t *list)
{
    node_t *tmp = list;

    while (tmp) {
        if (tmp->value != 0)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

void display_list(data_elf_t *elf)
{
    node_t *tmp = elf->list_sym;
    bool all_no_value = check_all_no_value(tmp);

    while (tmp) {
        if (tmp->value != 0 || all_no_value)
            printf(elf->not_normal_bit ? "%08x " : "%016x ", tmp->value);
        else
            printf(elf->not_normal_bit ? "         " : "                 ");
        printf("%c ", tmp->type);
        printf("%s\n", tmp->name);
        all_no_value = false;
        tmp = tmp->next;
    }
}
