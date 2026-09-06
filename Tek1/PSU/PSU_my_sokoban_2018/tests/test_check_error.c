/*
** EPITECH PROJECT, 2018
** test_my_sokoban
** File description:
** test_my_sokoban
*/

#include  <criterion/criterion.h>
#include <criterion/redirect.h>

void option_h(void);
int check_error(int ac, char *av[]);
int check_error_two(char **map, int nb_rows, int nb_cols);
void check_error_last_first_line(char **map, int *nb_cols, int *nb_rows);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(option_h, option_h, .init = redirect_all_std)
{
    option_h();
    cr_stdout_match_str("USAGE\n     ./my_sokoban map\n     'q' in order to quit.\n"
                        "     'ESPACE' in order to reset map.\nDESCRIPTION\n"
                        "     map file representing the warehouse map, containi"
                        "ng ‘#’ for walls,\n          ‘P’ for the player, ‘X’ "
                        "for boxes and ‘O’ for storage locations.\n");
}

Test(check_error, check_error_option, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;

    av[0] = "23";
    av[1] = "-h";
    check_error(ac, av);
   // cr_expect_eq(check_error(ac, av), 84);
    cr_stdout_match_str("USAGE\n     ./my_sokoban map\n     'q' in order to quit.\n"
                        "     'ESPACE' in order to reset map.\nDESCRIPTION\n"
                        "     map file representing the warehouse map, containi"
                        "ng ‘#’ for walls,\n          ‘P’ for the player, ‘X’ "
                        "for boxes and ‘O’ for storage locations.\n");
    free(av);
}

Test(check_error, check_error, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;

    av[0] = "23";
    av[1] = "21";
    check_error(ac, av);
    cr_stdout_match_str("Invalid Input, please check -h\n");
    free(av);
}

Test(check_error, check_error_normal, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;

    av[0] = "23";
    av[1] = "12";
    check_error(ac, av);
    cr_expect_eq(check_error(ac, av), 1);
    free(av);
}

Test(check_error_two, check_error_two_normal)
{
    char **av = malloc(sizeof(char *) * 4);
    int cols = 3;
    int rows = 3;

    av[0] = "####";
    av[1] = "#O##";
    av[2] = "##P#";
    av[3] = "####";
    
    cr_expect_eq(check_error_two(av, rows, cols), 1);
    free(av);
}

Test(check_error_two, check_error_two_no_perso)
{
    char **av = malloc(sizeof(char *) * 4);
    int cols = 3;
    int rows = 3;

    av[0] = "####";
    av[1] = "#O##";
    av[2] = "####";
    av[3] = "####";
    
    cr_expect_eq(check_error_two(av, rows, cols), 0);
    free(av);
}

Test(check_error_two, check_error_two_no_o)
{
    char **av = malloc(sizeof(char *) * 4);
    int cols = 3;
    int rows = 3;

    av[0] = "####";
    av[1] = "#P##";
    av[2] = "####";
    av[3] = "####";
    
    cr_expect_eq(check_error_two(av, rows, cols), 0);
    free(av);
}

Test(check_error_last_first_line, check_error_last_first_line_no_first,
    .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 3);
    int three = 4;

    av[0] = "A1A1";
    av[1] = "#O##";
    av[2] = "##P#";
    av[3] = "####";
    check_error_last_first_line(av, &three, &three);
    cr_stdout_match_str("Invalide file\n");
    free(av);
}

Test(check_error_last_first_line, check_error_last_first_line_no_last,
    .init = redirect_all_std)
{
    char **av = malloc(sizeof(char *) * 4);
    int three = 4;

    av[0] = "####";
    av[1] = "#O##";
    av[2] = "##P#";
    av[3] = "A1A1";
    check_error_last_first_line(av, &three, &three);
    cr_stdout_match_str("Invalide file\n");
    free(av);
}