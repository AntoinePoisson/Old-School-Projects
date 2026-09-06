/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "nm.h"

static data_elf_t *init_struct(void)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    if (!elf)
        return (NULL);
    elf->ehdr = NULL;
    elf->ehdr_ = NULL;
    elf->shdr = NULL;
    elf->shdr_ = NULL;
    elf->strtab = NULL;
    elf->list_sym = NULL;
    elf->length_file = 0;
    elf->not_normal_bit = false;
    return (elf);
}

int main(int ac, char *av[])
{
    data_elf_t *elf = init_struct();

    if (elf == NULL)
        return (84);
    for (int i = 1; i < ac; i++)
        if (strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0) {
            printf("Usage: nm [option(s)] [file(s)]\n");
            return (0);
        }
    if (ac == 1 || ac == 2) {
        if (!success_parsing_file(ac == 2 ? av[1] : "a.out", elf))
            return (1);
        display_file(ac == 2 ? av[1] : "a.out", elf, false);
        return (0);
    }
    for (int i = 1; i < ac; i++)
        if (success_parsing_file(av[i], elf)) {
            display_file(av[i], elf, true);
        }
    return (0);
}