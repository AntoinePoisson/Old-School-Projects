/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/nm.h"

bool check_all_no_value(node_t *list);
char type_symbole(unsigned char info, uint16_t shndx, uint32_t flag,
uint32_t type);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(success_parsing_file, false_parsing_file)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    cr_expect_eq(success_parsing_file("./zzzzzz", elf), false);
}

Test(success_parsing_file, false_parsing_file_two)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    cr_expect_eq(success_parsing_file("./src", elf), false);
}

Test(type_symbole, fails_type_symbole)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    cr_expect_neq(type_symbole('0', 0, 0, 0), '?');
}

Test(check_all_no_value, check_all_no_value)
{
    node_t *elf = malloc(sizeof(*elf));

    cr_expect_eq(check_all_no_value(elf), false);
}

Test(add_node, add_node)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    cr_expect_neq(add_node(elf, "ZZ", 10, 'c'), NULL);
}

Test(display_list, display_list, .init = redirect_all_stdout)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    elf->list_sym = NULL;
    display_list(elf);
    cr_expect_stdout_neq_str("A");
}

Test(is_extension_sort_list, is_extension_sort_list)
{
    data_elf_t *elf = malloc(sizeof(*elf));

    elf->list_sym = NULL;
    cr_expect_eq(is_extension_sort_list(elf), false);
}