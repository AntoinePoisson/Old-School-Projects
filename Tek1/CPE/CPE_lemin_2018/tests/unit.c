/*
** EPITECH PROJECT, 2019
** test
** File description:
** unit.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lem_in.h"
#include "parsing.h"

void redirect_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sort_array, test, .init = redirect_std)
{
    int **tmp = malloc(sizeof(int *) * 2);

    tmp[0] = malloc(sizeof(int) * 3);
    tmp[1] = malloc(sizeof(int));
    tmp[1][0] = -1;
    tmp[0][0] = 4;
    tmp[0][1] = 2;
    tmp[0][2] = -1;
    cr_assert_neq(sort_array(tmp), tmp);
}

Test(disp, test, .init = redirect_std)
{
    disp(2, "2");
    cr_stdout_match_str("P2-2");
}

Test(move_ants, test, .init = redirect_std)
{
    variable_t *var = malloc(sizeof(*var));
    anthill_t anthill[1];
    int path[2] = {2, -1};
    int **tmp = malloc(sizeof(int *) * 2);

    anthill[0].index = 3;
    tmp[0] = malloc(sizeof(int) * 3);
    tmp[1] = malloc(sizeof(int));
    tmp[1][0] = -1;
    tmp[0][0] = 4;
    tmp[0][1] = 2;
    tmp[0][2] = -1;
    cr_expect_eq(move_ants(0, tmp, var), 0);
    cr_expect_eq(last_room(anthill, path, 0), 0);
    cr_expect_eq(last_room(anthill, path, 1), -1);
    cr_expect_eq(simple_path(0, path, var), 0);
}

Test(is_extension_simple_path, test0, .init = redirect_std)
{
    int print = 1;
    int path[4] = {2, 2, 2, -1};

    is_extension_simple_path(&print, path, 1, 1);
    cr_stdout_match_str(" ");
}

Test(is_extension_simple_path, test1, .init = redirect_std)
{
    int print = 1;
    int path[4] = {2, 2, -1, -1};
    is_extension_simple_path(&print, path, 1, 2);
    cr_stdout_match_str("\n");
}

Test(is_extension_simple_path, test, .init = redirect_std)
{
    int print = 1;
    int path[4] = {2, 2, 2, -1};

    is_extension_simple_path(&print, path, 1, 3);
    cr_stdout_match_str("\n");
}

Test(failure_parsing, test, .init = redirect_std)
{
    variable_t *var0 = malloc(sizeof(*var0));
    variable_t *var1 = malloc(sizeof(*var1));
    variable_t *var2 = malloc(sizeof(*var2));

    var0->nbr_ants = 2;
    var1->nbr_ants = 2;
    var2->nbr_ants = 2;
    var0->start = NULL;
    var1->start = malloc(sizeof(*var1->start));
    var2->start = malloc(sizeof(*var2->start));
    var1->end = NULL;
    var2->end = malloc(sizeof(*var2->end));
    var2->room = NULL;
    cr_assert_eq(failure_parsing(var0), 84);
    cr_assert_eq(failure_parsing(var1), 84);
    cr_assert_eq(failure_parsing(var2), 84);
}
