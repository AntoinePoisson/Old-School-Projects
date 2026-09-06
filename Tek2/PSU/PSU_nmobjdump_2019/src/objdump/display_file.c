/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** display_file
*/

#include "objdump.h"

static bool checker_cond(data_elf_t *elf, int current_sec, bool cas)
{
    if ((cas && elf->shdr_[current_sec].sh_size &&
        elf->shdr_[current_sec].sh_type != SHT_NOBITS &&
        elf->shdr_[current_sec].sh_type != SHT_SYMTAB &&
        elf->shdr_[current_sec].sh_type != SHT_STRTAB &&
        strncmp(&elf->strtab[elf->shdr_[current_sec].sh_name], ".rela", 5)
        != 0) || (cas &&
        strcmp(&elf->strtab[elf->shdr_[current_sec].sh_name], ".dynstr")
        == 0) || (cas &&
        strcmp(&elf->strtab[elf->shdr_[current_sec].sh_name], ".rela.dyn")
        == 0) || (cas &&
        strcmp(&elf->strtab[elf->shdr_[current_sec].sh_name], ".rela.plt")
        == 0))
        return (true);
    return (checker_cond_extension(elf, current_sec, cas));
}

static void display_second_part(bool bit, int size_current,
    unsigned int index, data_elf_t *elf)
{
    unsigned char *tab = bit ? ((unsigned char *)(elf->ehdr_) + index) :
        ((unsigned char *)(elf->ehdr) + index);

    for (int count = 0; count < 16; count++) {
        if (count % 4 == 0)
            printf(" ");
        if (count < size_current) {
            printf("%02x", bit ? ((unsigned char *)(elf->ehdr_) +
            index)[count] : ((unsigned char *)(elf->ehdr) + index)[count]);
        } else
            printf("  ");
    }
    printf("  ");
    for (int x = 0; x < 16; x++) {
        if (x < size_current)
            printf("%c", !(isprint(tab[x])) ? '.' : tab[x]);
        else
            printf(" ");
    }
}

static void display_data(data_elf_t *elf, unsigned int index,
int current_sec, bool bit)
{
    int size_current = bit ? ((elf->shdr_[current_sec].sh_offset
        + elf->shdr_[current_sec].sh_size) - index) :
        ((elf->shdr[current_sec].sh_offset + elf->shdr[current_sec].sh_size)
        - index);

    printf(" %04x", bit ?
        ((int)(elf->shdr_[current_sec].sh_addr + (index -
        elf->shdr_[current_sec].sh_offset))) :
        ((int)(elf->shdr[current_sec].sh_addr + (index -
        elf->shdr[current_sec].sh_offset)))
    );
    display_second_part(bit, size_current, index, elf);
    printf("\n");
}

static void display_section(data_elf_t *elf, uint16_t lim)
{
    for (int current_sec = 0; current_sec < lim; current_sec++) {
        if (elf->not_normal_bit && checker_cond(elf, current_sec, true)) {
            printf("Contents of section %s:\n",
            &(elf->strtab[elf->shdr_[current_sec].sh_name]));
            for (unsigned int i = elf->shdr_[current_sec].sh_offset; i <
                elf->shdr_[current_sec].sh_offset +
                elf->shdr_[current_sec].sh_size; i += 16)
                display_data(elf, i, current_sec, true);
        }
        if (!elf->not_normal_bit && checker_cond(elf, current_sec, false)) {
            printf("Contents of section %s:\n",
            &(elf->strtab[elf->shdr[current_sec].sh_name]));
            for (unsigned int i = elf->shdr[current_sec].sh_offset; i <
                elf->shdr[current_sec].sh_offset +
                elf->shdr[current_sec].sh_size; i += 16)
                display_data(elf, i, current_sec, false);
        }
    }
}

bool display_file(data_elf_t *elf, char const *filename)
{
    display_header(elf, filename);
    if (elf->s_flag) {
        display_section(elf, elf->not_normal_bit ?
            elf->ehdr_->e_shnum : elf->ehdr->e_shnum);
    }
    return (true);
}