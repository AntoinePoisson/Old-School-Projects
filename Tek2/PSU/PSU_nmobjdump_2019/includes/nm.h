/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm
*/

#ifndef NM_H
#define NM_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <fcntl.h>
#include <string.h>

    // Structure
typedef struct node_s
{
    char *name_sort;
    char *name;
    unsigned int value;
    char type;
    struct node_s *next;
} node_t;


typedef struct data_elf_s
{
    Elf64_Ehdr *ehdr;
    Elf32_Ehdr *ehdr_;
    Elf64_Shdr *shdr;
    Elf32_Shdr *shdr_;
    Elf64_Sym *start;
    Elf32_Sym *start_;
    Elf64_Sym *end;
    Elf32_Sym *end_;
    node_t *list_sym;
    char *strtab;
    size_t length_file;
    bool not_normal_bit;
} data_elf_t;

    //Prototypes
bool success_parsing_file(char const *name, data_elf_t *elf);
bool display_file(char const *name, data_elf_t *elf, bool message);
void sort_list(data_elf_t *elf);
void display_list(data_elf_t *elf);
void my_swap_node(node_t *one, node_t *two);
bool swap_eq(node_t *one, node_t *two);
bool is_extension_sort_list(data_elf_t *elf);
data_elf_t *add_node(data_elf_t *elf, char *name, unsigned int value,
    char type);

#endif /* !NM_H_ */
