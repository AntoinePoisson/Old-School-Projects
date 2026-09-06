/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** parse
*/

#include "nm.h"

static bool reset_list_sym(data_elf_t *elf, int fd)
{
    node_t *tmp = NULL;

    close(fd);
    if (elf->list_sym == NULL)
        return (true);
    while (elf->list_sym) {
        if (tmp && tmp->name_sort) {
            free(tmp->name_sort);
            tmp->name_sort = NULL;
            free(tmp);
            tmp = NULL;
        }
        tmp = elf->list_sym;
        elf->list_sym = elf->list_sym->next;
    }
    elf->list_sym = NULL;
    return (true);
}

static int open_file(char const *name, unsigned int *size)
{
    struct stat size_file;
    int fd = open(name, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "my_nm: '%s': No such file\n", name);
        return (-1);
    } else if (fstat(fd, &size_file) == -1) {
        close(fd);
        perror("fstat");
        return (-1);
    }
    *size = size_file.st_size;
    return (fd);
}

static bool fill_my_elf(data_elf_t *elf, int fd,
    char const *name, size_t shoff)
{
    if ((EI_VERSION > EI_NIDENT) || (elf->ehdr->e_ident[EI_CLASS] ==
        ELFCLASSNONE) || (elf->ehdr->e_ident[EI_VERSION] == EV_NONE)
        || (elf->ehdr->e_ident[EI_DATA] == ELFDATANONE) ||
        (!elf->not_normal_bit && elf->length_file < sizeof(Elf64_Ehdr)) ||
        ((elf->ehdr + shoff) > (elf->ehdr + elf->length_file))) {
        fprintf(stderr, "my_nm: %s: File format not recognized\n", name);
        return (false);
    }
    if (elf->not_normal_bit) {
        elf->shdr_ = (void *)elf->ehdr_ + elf->ehdr_->e_shoff;
        elf->strtab = (void *)elf->ehdr_ +
        elf->shdr_[elf->ehdr_->e_shstrndx].sh_offset;
    } else {
        elf->shdr = (void *)elf->ehdr + elf->ehdr->e_shoff;
        elf->strtab = (void *)elf->ehdr +
        elf->shdr[elf->ehdr->e_shstrndx].sh_offset;
    }
    return (reset_list_sym(elf, fd));
}

bool success_parsing_file(char const *name, data_elf_t *elf)
{
    unsigned int size_file = 0;
    int fd = open_file(name, &size_file);
    void *tmp = NULL;

    if (fd == -1)
        return (false);
    elf->length_file = size_file;
    tmp = mmap(NULL, size_file, PROT_READ, MAP_SHARED, fd, 0);
    if (elf->length_file < sizeof(Elf32_Ehdr) || tmp == MAP_FAILED ||
        memcmp(tmp, "\177ELF", 4) != 0) {
        fprintf(stderr, "my_nm: %s: File format not recognized\n", name);
        return (false);
    }
    elf->ehdr = (Elf64_Ehdr *)tmp;
    if (elf->ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
        elf->ehdr_ = (Elf32_Ehdr *)tmp;
        elf->not_normal_bit = true;
    }
    return (fill_my_elf(elf, fd, name, elf->not_normal_bit ?
        elf->ehdr_->e_shoff : elf->ehdr->e_shoff));
}
