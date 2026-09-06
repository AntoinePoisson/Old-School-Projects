/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lem_in.h"
#include "parsing.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test, test, .init = redirect_all_std)
{
    cr_expect_eq(0, 0);
}

Test(check_error, error, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(check_error(var), 0);
}

Test(main_bis, error1, .init = redirect_all_std)
{
    cr_assert_eq(main_bis(4, (char **)42), 84);
}

Test(is_command, return_zero, .init = redirect_all_std)
{
    char const *str = "##s";
    variable_t *var = malloc(sizeof(*var));
    int z = 0;

    cr_assert_eq(is_command(var, str, &z), 0);
}

Test(select_element_pasring, return_erro, .init = redirect_all_std)
{
    char *str = NULL;
    variable_t *var = malloc(sizeof(*var));
    int z = 0;

    cr_assert_eq(select_element_parsing(var, str, &z), 1);
}

Test(select_element_parsing, return_command, .init = redirect_all_std)
{
    char *str = "##s";
    variable_t *var = malloc(sizeof(*var));
    int z = 0;

    cr_assert_eq(select_element_parsing(var, str, &z),
        is_command(var, str, &z));
}

Test(check_end_start_link, return_com, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(check_end_start_link(var), 84);
}

Test(check_same_data, return_displ, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));
    node_t *element = malloc(sizeof(*element));

    cr_assert_eq(check_same_data(var, element), 1);
}

Test(check_error, return_dip, .init = redirect_all_std)
{
    variable_t *var = NULL;

    cr_assert_eq(check_error(var), 84);
}

Test(check_error, return_di, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(check_error(var), 0);
}

Test(tab_len, return_tab, .init = redirect_all_std)
{
    int **arr = malloc(sizeof(int *) * 1);

    arr[0] = malloc(sizeof(int) * 1);
    arr[0][0] = -1;
    cr_assert_eq(tab_len(arr), 0);
}

Test(convert_list, return_arr, .init = redirect_all_std)
{
    int **arr = NULL;
    path_t *path = malloc(sizeof(*path));

    cr_assert_eq(convert_list(arr, path), NULL);
}

Test(convert_list, tab, .init = redirect_all_std)
{
    int **arr = malloc(sizeof(int *) * 1);
    path_t *path = malloc(sizeof(*path));

    arr = NULL;
    cr_assert_eq(convert_list(arr, path), arr);
}

Test(display_parse, tabarr, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));
    int cas = 0;

    cr_assert_eq(display_parse(var, cas), 84);
}

Test(find_all_path, tabar, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(find_all_path(var), 0);
}

Test(initialization_algo, taba, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(initialization_algo(var), 0);
}

Test(initialization_algo, tb, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(initialization_algo(var), 0);
}

Test(is_room, bat, .init = redirect_all_std)
{
    char const *str = "##";

    cr_assert_eq(is_room(str), 84);
}

Test(is_room, batlle, .init = redirect_all_std)
{
    char const *str = NULL;

    cr_assert_eq(is_room(str), 84);
}

Test(final_check, batle, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(final_check(var), 84);
}

Test(failure_parsing, bale, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(failure_parsing(var), 84);
}

Test(find_begin, balle, .init = redirect_all_std)
{
    char const *str = "aaaa ";
    int a = find_begin(str);

    cr_assert_eq(find_begin(str), a);
}

Test(find_begin, gareth, .init = redirect_all_std)
{
    char const *str = "1 2 5";
    int a = find_begin(str);

    cr_assert_eq(find_begin(str), a);
}

Test(count_word, gare, .init = redirect_all_std)
{
    char const *str = NULL;

    cr_assert_eq(count_word(str), 0);
}

Test(count_word, gar, .init = redirect_all_std)
{
    char const *str = "1 5 0 #";

    cr_assert_neq(count_word(str), 3468464564);
}

Test(count_word, ga, .init = redirect_all_std)
{
    char const *str = "1 5 0";

    cr_assert_neq(count_word(str), 3468464564);
}

Test(nbr_ants, glac, .init = redirect_all_std)
{
    char const *str = "1 5 0";

    cr_assert_neq(nbr_ants(str), 84);
}

Test(nbr_ants, glc, .init = redirect_all_std)
{
    char const *str = "1 5 0";

    cr_assert_eq(nbr_ants(str), 0);
}

Test(is_link_room, gnl, .init = redirect_all_std)
{
    char const *str = "1 5 0";

    cr_assert_neq(is_link_room(str), 0);
}

Test(is_link_room, genius, .init = redirect_all_std)
{
    char const *str = "1 5 0";

    cr_assert_eq(is_link_room(str), 84);
}

Test(final_check, gen, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_eq(final_check(var), 84);
}

Test(final_check, gene, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));

    cr_assert_neq(final_check(var), 0);
}

Test(create_tab_node_element, gener, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(*var));
    node_t **a = create_tab_node_element(var);

    cr_assert_neq(create_tab_node_element(var), a);
}

Test(is_room, generic, .init = redirect_all_std)
{
    char const *str = "1 0 1";
    int a = is_room(str);

    cr_assert_eq(is_room(str), a);
}

Test(my_printf, test00, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, test01, .init = redirect_all_std)
{
    my_printf("hello %d world", 49);
    cr_stdout_match_str("hello 49 world");
}

Test(my_printf, test02, .init = redirect_all_std)
{
    my_printf("hello %i world", 49);
    cr_stdout_match_str("hello 49 world");
}

Test(my_printf, test03, .init = redirect_all_std)
{
    my_printf("hello %i world", 79);
    cr_stdout_match_str("hello 79 world");
}

Test(my_printf, test04, .init = redirect_all_std)
{
    my_printf("hello %d world", -49);
    cr_stdout_match_str("hello -49 world");
}

Test(my_printf, test05, .init = redirect_all_std)
{
    my_printf("hello %i world", -49);
    cr_stdout_match_str("hello -49 world");
}

Test(my_printf, test06, .init = redirect_all_std)
{
    my_printf("hello %i world", 49);
    cr_stdout_match_str("hello 49 world");
}

Test(my_printf, test07, .init = redirect_all_std)
{
    my_printf("hello %i world", 49);
    cr_stdout_match_str("hello 49 world");
}

Test(my_printf, test08, .init = redirect_all_std)
{
    my_printf("hello %i world", -49);
    cr_stdout_match_str("hello 4294967147 world");
}

Test(my_printf, test09, .init = redirect_all_std)
{
    my_printf("hello %x world", -49);
    cr_stdout_match_str("hello 4294967147 world");
}

Test(my_printf, test10, .init = redirect_all_std)
{
    my_printf("hello %x world", 8);
    cr_stdout_match_str("hello 8 world");
}

Test(my_printf, test11, .init = redirect_all_std)
{
    my_printf("hello %x world", 29);
    cr_stdout_match_str("hello 1d world");
}

Test(my_printf, test12, .init = redirect_all_std)
{
    my_printf("hello %X world", -49);
    cr_stdout_match_str("hello 4294967147 world");
}

Test(my_printf, test13, .init = redirect_all_std)
{
    my_printf("hello %X world", 8);
    cr_stdout_match_str("hello 8 world");
}

Test(my_printf, test14, .init = redirect_all_std)
{
    my_printf("hello %X world", 29);
    cr_stdout_match_str("hello 1D world");
}

Test(my_printf, test015, .init = redirect_all_std)
{
    my_printf("hello % world", -49);
    cr_stdout_match_str("hello 4294967147 world");
}

Test(my_printf, test16, .init = redirect_all_std)
{
    my_printf("hello %o world", 6);
    cr_stdout_match_str("hello 6 world");
}

Test(my_printf, test17, .init = redirect_all_std)
{
    my_printf("hello %o world", 8);
    cr_stdout_match_str("hello 10 world");
}

Test(my_printf, test18, .init = redirect_all_std)
{
    my_printf("%S", "6");
    cr_stdout_match_str("\006");
}

Test(my_printf, test19, .init = redirect_all_std)
{
    my_printf("%S", "101");
    cr_stdout_match_str("A");
}

Test(my_printf, test20, .init = redirect_all_std)
{
    my_printf("%b", -6);
    cr_stdout_match_str("11111111111111111111111111111010");
}

Test(my_printf, test21, .init = redirect_all_std)
{
    my_printf("%s", "joli");
    cr_stdout_match_str("joli");
}

Test(my_printf, test22, .init = redirect_all_std)
{
    my_printf("%c", "b");
    cr_stdout_match_str("b");
}

Test(my_printf, test23, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 6;
    my_printf("%S\n", str);
    cr_stdout_match_str("t\006to");
}

Test(my_printf, test24, .init = redirect_all_std)
{
    my_printf("%S", "63");
    cr_stdout_match_str("\077");
}

Test(my_printf, test25, .init = redirect_all_std)
{
    my_printf("%S", "63");
    cr_stdout_match_str("?");
}
