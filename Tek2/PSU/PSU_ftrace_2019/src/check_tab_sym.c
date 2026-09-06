/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** check_tab_sym
*/

#include "ftrace.h"

static int file_management(char const *name, size_t *size);
static void fill_tab_sym(ftrace_t *ftrace);

bool check_tab_sym(ftrace_t *ftrace, char *path)
{
    size_t size_file = 0;
    int fd = file_management(path, &size_file);
    void *tmp = NULL;

    if (fd == -1 || size_file == 0)
        return (false);
    tmp = mmap(NULL, size_file, PROT_READ, MAP_SHARED, fd, 0);
    if (size_file < sizeof(Elf64_Ehdr) || tmp == MAP_FAILED ||
        memcmp(tmp, "\177ELF", 4) != 0)
        return (false);
    ftrace->ehdr = (Elf64_Ehdr *)tmp;
    if ((ftrace->ehdr->e_ident[EI_CLASS] != ELFCLASS64) ||
        (EI_VERSION > EI_NIDENT) || (ftrace->ehdr->e_ident[EI_CLASS] ==
        ELFCLASSNONE) || (ftrace->ehdr->e_ident[EI_VERSION] == EV_NONE)
        || ((ftrace->ehdr + ftrace->ehdr->e_shoff) >
        (ftrace->ehdr + size_file)))
        return (false);
    close(fd);
    fill_tab_sym(ftrace);
    return (true);
}

static int file_management(char const *name, size_t *size)
{
    struct stat size_file;
    int fd = open(name, O_RDONLY);

    if (fd == -1) {
        perror("open");
        return (-1);
    } else if (fstat(fd, &size_file) == -1) {
        close(fd);
        perror("fstat");
        return (-1);
    }
    *size = size_file.st_size;
    return (fd);
}

static void fill_tab_sym(ftrace_t *ftrace)
{
    ftrace->shdr = (void *)ftrace->ehdr + ftrace->ehdr->e_shoff;
    ftrace->shnum = ftrace->ehdr->e_shnum;
    for (int i = 0; i < ftrace->shnum; i++) {
        if (ftrace->shdr[i].sh_type == SHT_SYMTAB) {
            ftrace->start = (void *)ftrace->ehdr + ftrace->shdr[i].sh_offset;
            ftrace->end = (void *)ftrace->start + ftrace->shdr[i].sh_size;
            ftrace->strtab = (char *)ftrace->ehdr +
                ftrace->shdr[ftrace->shdr[i].sh_link].sh_offset;
            ftrace->tab_sym = true;
        }
    }
}