/*
** EPITECH PROJECT, 2018
** test_my_sokoban
** File description:
** test_my_sokoban
*/

#include  <criterion/criterion.h>
#include <criterion/redirect.h>

int count_rows(char *map);
int count_cols(char *map);
void is_exten_count_cols_check(int *cols_max, int *count_cols);
int count_cols_check(char *map);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(count_rows, count_rows)
{
    char *av = "#\n#\n#\n";

    cr_expect_eq(count_rows(av), 3);
}

Test(count_cols, count_cols)
{
    char *av = "#\n#\n#\n";

    cr_expect_eq(count_cols(av), 1);
}

Test(is_exten_count_cols_check, is_exten_count_cols_check,
    .init = redirect_all_stdout)
{
    int ten = 10;
    int four = 4;
    int *cols = &four;
    int *cols_max = &ten;

    is_exten_count_cols_check(cols_max, cols);
    cr_stdout_match_str("Invalide file\n");
}

Test(count_cols_check, count_cols_check_nor)
{
    char *av = "#\n#\n#\n";

    cr_expect_eq(count_cols_check(av), 1);
}

Test(count_cols_check, count_cols_check)
{
    char *av = "112#\n123#\n3333#\n";

    count_cols_check(av);
    cr_stdout_match_str("Invalide file\n");
}