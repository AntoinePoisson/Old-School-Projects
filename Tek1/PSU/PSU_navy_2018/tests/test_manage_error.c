/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/navy.h"

int main(int ac, char **av);
int error_handling(int ac, char **av);
int game_help(void);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error_handling, error_handling_too_arg)
{
    int ac = 8;
    char **av = malloc(sizeof(char *) * 4);

    av[0] = "2:C1:C2";
    av[1] = "3:D4:F4";
    av[2] = "4:B5:B8";
    av[3] = "5:D7:H7";
    cr_expect_neq(error_handling(ac, av), 84);
}

Test(error_handling, error_handling_ac_two)
{
    int ac = 2;
    char **av = malloc(sizeof(char *) * 4);

    av[0] = "2:C1:C2";
    av[1] = "3:D4:F4";
    av[2] = "4:B5:B8";
    av[3] = "5:D7:H7";
    cr_expect_neq(error_handling(ac, av), 84);
}

Test(error_handling, error_handling_arg_one)
{
    int ac = 1;
    char **av = malloc(sizeof(char *) * 4);

    av[0] = "2:C1:C2";
    av[1] = "3:D4:F4";
    av[2] = "4:B5:B8";
    av[3] = "5:D7:H7";
    cr_expect_neq(error_handling(ac, av), 84);
}

Test(game_help, game_help, .init = redirect_all_stdout)
{
    game_help();
    cr_stdout_match_str("USAGE\n\t./navy [first_player_pid] navy_positions\n"
        "DESCRIPTION\n\tfirst_player_pid: only for the 2nd player."
        " pid of the first player.\n\tnavy_positions: file"
        " representing the positions of the ships.\n");
}

Test(game_help, game_help_return)
{
    cr_expect_eq(game_help(), 0);
}
