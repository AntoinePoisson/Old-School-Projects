/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** display_header
*/

#include "objdump.h"

static void display_message_flags(char const *message, bool display, int value)
{
    static bool first = true;

    if (value == 0)
        first = true;
    if (!display)
        return;
    if (first) {
        printf("%s", message);
        first = false;
    } else {
        printf(", %s", message);
    }
}

static void display_symbole(data_elf_t *elf, int *res, bool display)
{
    unsigned short type = elf->not_normal_bit ?
        elf->ehdr_->e_type : elf->ehdr->e_type;
    unsigned short e_shnum = elf->not_normal_bit ?
        elf->ehdr_->e_shnum : elf->ehdr->e_shnum;
    char *sym = "";

    if (type == ET_REL) {
        display_message_flags("HAS_RELOC", display, *res);
        *res |= HAS_RELOC;
    }
    if (type == ET_EXEC) {
        display_message_flags("EXEC_P", display, *res);
        *res |= EXEC_P;
    }
    if (elf->strtab) {
        for (int i = 0; i < e_shnum; i++) {
            sym = elf->not_normal_bit ? elf->strtab + elf->shdr_[i].sh_name
                : elf->strtab + elf->shdr[i].sh_name;
            if (strcmp(sym, ".dynsym") == 0 || strcmp(sym, ".symtab") == 0) {
                display_message_flags("HAS_SYMS", display, *res);
                *res |= HAS_SYMS;
                return;
            }
        }
    }
    return;
}

static int display_flags(data_elf_t *elf, uint16_t e_phnum, bool display)
{
    unsigned short type = elf->not_normal_bit ? elf->ehdr_->e_type :
        elf->ehdr->e_type;
    int res = 0x00;

    if (type == ET_NONE) {
        if (display)
            printf("\n");
        return (res);
    }
    display_symbole(elf, &res, display);
    if (type == ET_DYN) {
        display_message_flags("DYNAMIC", display, res);
        res |= DYNAMIC;
    }
    if (e_phnum != 0) {
        display_message_flags("D_PAGED", display, res);
        res |= D_PAGED;
    }
    return (res);
}

static char *display_archi(Elf64_Half e_machine, data_elf_t *elf)
{
    switch (e_machine) {
        case EM_NONE: return ("None");
        case EM_M32: return ("WE32100");
        case EM_SPARC: return ("Sparc");
        case EM_386: return ("i386");
        case EM_860: return ("i860");
        case EM_PARISC: return ("HPPA");
        case EM_PPC: return ("PowerPC");
        case EM_PPC64: return ("PowerPC64");
        case EM_ARM: return ("ARM");
        default: return (elf->not_normal_bit ? "i386" : "i386:x86-64");
    }
}

void display_header(data_elf_t *elf, char const *filename)
{
    printf("\n%s:     file format %s\n", filename,
    elf->not_normal_bit ? "elf32-i386" : "elf64-x86-64");
    if (elf->f_flag && elf->not_normal_bit) {
        printf("architecture: %s, flags 0x%08x:\n",
        display_archi(elf->ehdr_->e_machine, elf),
        display_flags(elf, elf->ehdr_->e_phnum, false));
        display_flags(elf, elf->ehdr_->e_phnum, true);
        printf("\nstart address 0x%08lx\n",
        (long unsigned int)elf->ehdr_->e_entry);
    } else if (elf->f_flag) {
        printf("architecture: %s, flags 0x%08x:\n",
        display_archi(elf->ehdr->e_machine, elf),
        display_flags(elf, elf->ehdr->e_phnum, false));
        display_flags(elf, elf->ehdr->e_phnum, true);
        printf("\nstart address 0x%016lx\n", elf->ehdr->e_entry);
    }
    printf("\n");
}