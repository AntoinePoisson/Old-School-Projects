/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** display_file
*/

#include "nm.h"

static char checker_up_or_low(char c, unsigned char info, bool bits, char *name)
{
    if (c == '?' && strstr(name, "fini_array") != NULL)
        c = 't';
    if (c == '?' && strstr(name, "init_array") != NULL)
        c = 't';
    if (c == '?' || c == 'u' || c == 'U' || c == 'W' || c == 'w')
        return (c);
    if (bits && ELF32_ST_BIND(info) == STB_LOCAL)
        return (c);
    if (!bits && ELF64_ST_BIND(info) == STB_LOCAL)
        return (c);
    return (c - ' ');
}

char type_symbole(unsigned char info, uint16_t shndx, uint32_t flag,
uint32_t type)
{
    switch (ELF64_ST_BIND(info)) {
        case STB_GNU_UNIQUE: return ('u');
        case STB_WEAK: return (ELF64_ST_TYPE(info) == STT_OBJECT ? 'v':
                                (shndx == SHN_UNDEF) ? 'w' : 'W');
    }
    switch (shndx) {
        case SHN_ABS: return ('a');
        case SHN_COMMON: return ('c');
        case SHN_UNDEF: return ('U');
    }
    switch (type) {
        case SHT_NOBITS: return ('b');
        case SHT_DYNAMIC: return ('d');
        case SHT_PROGBITS: return ((flag == (SHF_ALLOC | SHF_WRITE) ? 'd' :
                                    flag == (SHF_ALLOC | SHF_EXECINSTR) ? 't':
                                    'r'));
    }
    return ('?');
}

static bool take_symbole(data_elf_t *elf)
{
    if (elf->not_normal_bit) {
        for (Elf32_Sym *i = elf->start_; i < elf->end_; i++)
            if (i->st_info != STT_FILE && i->st_info != STT_SECTION &&
                elf->strtab[i->st_name] != '\0')
                add_node(elf, &elf->strtab[i->st_name], i->st_value,
                checker_up_or_low(type_symbole(i->st_info, i->st_shndx,
                elf->shdr_[i->st_shndx].sh_flags,
                elf->shdr_[i->st_shndx].sh_type), i->st_info, true,
                &elf->strtab[i->st_name]));
        return (true);
    }
    for (Elf64_Sym *i = elf->start; i < elf->end; i++)
        if (i->st_info != STT_FILE && i->st_info != STT_SECTION &&
            elf->strtab[i->st_name] != '\0') {
            add_node(elf, &elf->strtab[i->st_name], i->st_value,
            checker_up_or_low(type_symbole(i->st_info, i->st_shndx,
            elf->shdr[i->st_shndx].sh_flags, elf->shdr[i->st_shndx].sh_type),
            i->st_info, false, &elf->strtab[i->st_name]));
        }
    return (true);
}

static bool find_symbole(data_elf_t *elf)
{
    int shnum = elf->not_normal_bit ? elf->ehdr_->e_shnum : elf->ehdr->e_shnum;
    bool find_sym = false;

    for (int i = 0; i < shnum; i++) {
        if (elf->not_normal_bit && elf->shdr_[i].sh_type == SHT_SYMTAB) {
            elf->start_ = (void *)elf->ehdr_ + elf->shdr_[i].sh_offset;
            elf->end_ = (void *)elf->start_ + elf->shdr_[i].sh_size;
            elf->strtab = (char *)elf->ehdr_ +
            elf->shdr_[elf->shdr_[i].sh_link].sh_offset;
            find_sym = true;
        }
        if (!elf->not_normal_bit && elf->shdr[i].sh_type == SHT_SYMTAB) {
            elf->start = (void *)elf->ehdr + elf->shdr[i].sh_offset;
            elf->end = (void *)elf->start + elf->shdr[i].sh_size;
            elf->strtab = (char *)elf->ehdr +
            elf->shdr[elf->shdr[i].sh_link].sh_offset;
            find_sym = true;
        }
    }
    return (find_sym ? true : false);
}

bool display_file(char const *name, data_elf_t *elf, bool message)
{
    if (!find_symbole(elf) || !take_symbole(elf)) {
        if (!message)
            printf("my_nm: %s: no symbols\n", name);
        return (false);
    }
    if (name && message)
        printf("\n%s:\n", name);
    sort_list(elf);
    display_list(elf);
    return (true);
}