/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "objdump.h"

bool checker_cond_extension(data_elf_t *elf, int current_sec, bool cas)
{
    if ((!cas && elf->shdr[current_sec].sh_size &&
        elf->shdr[current_sec].sh_type != SHT_NOBITS &&
        elf->shdr[current_sec].sh_type != SHT_SYMTAB &&
        elf->shdr[current_sec].sh_type != SHT_STRTAB &&
        strncmp(&elf->strtab[elf->shdr[current_sec].sh_name], ".rela", 5)
        != 0) || (!cas &&
        strcmp(&elf->strtab[elf->shdr[current_sec].sh_name], ".dynstr")
        == 0) || (!cas &&
        strcmp(&elf->strtab[elf->shdr[current_sec].sh_name], ".rela.dyn")
        == 0) || (!cas &&
        strcmp(&elf->strtab[elf->shdr[current_sec].sh_name], ".rela.plt")
        == 0))
        return (true);
    return (false);
}

static bool checker_flags(char const *str)
{
    if (strcmp("-s", str) == 0 || strcmp("-f", str) == 0 ||
        strcmp("-sf", str) == 0 || strcmp("-fs", str) == 0)
        return (false);
    return (true);
}

static data_elf_t *init_struct(data_elf_t *elf)
{
    elf->ehdr = NULL;
    elf->ehdr_ = NULL;
    elf->shdr = NULL;
    elf->shdr_ = NULL;
    elf->strtab = NULL;
    elf->length_file = 0;
    elf->s_flag = true;
    elf->f_flag = true;
    elf->not_normal_bit = false;
    return (elf);
}

data_elf_t *create_struct(data_elf_t *elf, int ac, char *av[], int *size)
{
    if (elf == NULL)
        return (NULL);
    elf = init_struct(elf);
    for (int i = 1; i < ac; i++) {
        if (strcmp("-s", av[i]) == 0 || strcmp("-sf", av[i]) == 0
            || strcmp("-fs", av[i]) == 0)
            elf->s_flag = true;
        if (strcmp("-f", av[i]) == 0 || strcmp("-sf", av[i]) == 0
            || strcmp("-fs", av[i]) == 0)
            elf->f_flag = true;
        if (checker_flags(av[i]))
            *size = *size + 1;
    }
    return (elf);
}

int main(int ac, char *av[])
{
    int size_arg = 0;
    data_elf_t *elf = malloc(sizeof(*elf));

    elf = create_struct(elf, ac, av, &size_arg);
    if (elf == NULL || (elf->f_flag == false && elf->s_flag == false)) {
        fprintf(stderr, "Usage: objdump <option(s)> <file(s)>\n");
        return (84);
    }
    if (size_arg == 0) {
        if (!success_parsing_file(elf, "a.out"))
            return (1);
        display_file(elf, "a.out");
        return (0);
    }
    for (int i = 1; i < ac; i++)
        if (checker_flags(av[i]) && success_parsing_file(elf, av[i]))
            display_file(elf, av[i]);
    return (0);
}
