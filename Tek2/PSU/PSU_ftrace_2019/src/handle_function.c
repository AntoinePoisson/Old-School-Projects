/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** handle_function
*/

#include "ftrace.h"

static funct_t *add_function(ftrace_t *ftrace, long long value, char *name);
static bool check_type_symb(unsigned char info, uint64_t flag);
static bool check_name_symb(char *name);
static char *create_name(char *name, long long value);

funct_t *handle_display_function(ftrace_t *ftrace,
    struct user_regs_struct *regs)
{
    for (Elf64_Sym *i = ftrace->start; i < ftrace->end; i++) {
        if (ftrace->tab_sym && i->st_info != STT_FILE && i->st_info !=
            STT_SECTION && check_type_symb(i->st_info,
            ftrace->shdr[i->st_shndx].sh_flags) && check_name_symb(
            &ftrace->strtab[i->st_name]) && (int)i->st_value ==
            (int)regs->rip) {
            fprintf(stdout, "Entering function %s at 0x%llx\n",
            &ftrace->strtab[i->st_name], regs->rip);
            return (add_function(ftrace, regs->rip,
            &ftrace->strtab[i->st_name]));
        } else if (!ftrace->tab_sym && i->st_info != STT_FILE &&
            i->st_info != STT_SECTION && check_type_symb(i->st_info,
            ftrace->shdr[i->st_shndx].sh_flags) && (int)i->st_value
            == (int)regs->rip) {
            fprintf(stdout, "Entering function 0x%s\n",
            create_name(ftrace->av_one, (int)regs->rip));
            return (add_function(ftrace, regs->rip, NULL));
        }
    }
    return (ftrace->list);
}

static bool check_type_symb(unsigned char info, uint64_t flag)
{
    if (!((ELF64_ST_BIND(info) == SHT_PROGBITS) &&
        (flag == (SHF_ALLOC | SHF_EXECINSTR))))
        return (false);
    return (true);
}

static bool check_name_symb(char *name)
{
    if (!name || strlen(name) == 0)
        return (false);
    for (int i = 0; name[i]; i++)
        if ((name[i] == '@') || (name[i] == '.') ||
            (i == 0 && name[0] == '_'))
            return (false);
    return (true);
}

static funct_t *add_function(ftrace_t *ftrace, long long value, char *name)
{
    funct_t *new = malloc(sizeof(*new));
    funct_t *save = ftrace->list;

    if (!new)
        exit(84);
    new->name = name ? name : create_name(ftrace->av_one, value);
    new->next = NULL;
    if (!ftrace->list) {
        ftrace->list = new;
        return (ftrace->list);
    }
    while (ftrace->list->next)
        ftrace->list = ftrace->list->next;
    ftrace->list->next = new;
    ftrace->list = save;
    return (ftrace->list);
}

static char *create_name(char *name, long long value)
{
    int size = 30 + strlen(name);
    char *res = calloc(size, 1);

    if (!res)
        return ("OKKO");
    sprintf(res, "func_0x%llx@%s", value, name);
    return (res);
}