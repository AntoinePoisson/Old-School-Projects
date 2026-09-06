/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#ifndef OBJDUMP_H
#define OBJDUMP_H

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <fcntl.h>
#include <string.h>

    //Structure
typedef struct data_elf_s
{
    Elf64_Ehdr *ehdr;
    Elf32_Ehdr *ehdr_;
    Elf64_Shdr *shdr;
    Elf32_Shdr *shdr_;
    char *strtab;
    size_t length_file;
    bool f_flag;
    bool s_flag;
    bool not_normal_bit;
} data_elf_t;

    //Prototype
bool success_parsing_file(data_elf_t *elf, char const *name);
bool display_file(data_elf_t *elf, char const *filename);
void display_header(data_elf_t *elf, char const *filename);
bool checker_cond_extension(data_elf_t *elf, int current_sec, bool cas);

    //Define
#ifndef __BFD_H_SEEN__
#define __BFD_H_SEEN__

#define HAS_RELOC       0x01
#define EXEC_P          0x02
#define HAS_SYMS        0x10
#define DYNAMIC         0x40
#define D_PAGED         0x100

#endif /* !__BFD_H_SEEN__ */

#endif /* !OBJDUMP_H_ */
