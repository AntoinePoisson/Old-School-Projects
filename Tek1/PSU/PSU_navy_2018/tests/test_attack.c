/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/navy.h"

int end_of_game(char **my_map, char **enemy_map, int end);
int torpedo(char **av, battleship_t *navy, int round);
int battleship(char **av);
int check_hit(char **av, battleship_t *navy, int round);
int connection(char **av, battleship_t *navy);
int fill_map(char ***my_map, char ***enemy_map, char **av);
char *my_itoa(int nbr, int ng);

Test(battleship, battleship)
{
    cr_expect_eq(battleship(NULL), 84);
}

Test(end_of_game, end_of_game)
{
    char **my = malloc(sizeof(char *) * 4);
    char **enemy = malloc(sizeof(char *) * 4);
    int nbr = 0;

    my[2] = NULL;
    enemy[2] = NULL;
    cr_expect_neq(end_of_game(my, enemy, nbr), 84);
}

Test(fill_map, fill_map)
{
    char **my = malloc(sizeof(char *) * 4);
    char **enemy = malloc(sizeof(char *) * 4);
    char **av = malloc(sizeof(char *) * 3);

    my[2] = NULL;
    enemy[2] = NULL;
    cr_expect_eq(fill_map(&my, &enemy, av), -1);
}

Test(connection, connection)
{
    char **av = malloc(sizeof(char *) * 4);
    battleship_t *navy = malloc(sizeof(battleship_t));

    navy->enemy_pid = getpid();
    navy->my_pid = getpid();
    av[0] = NULL;
    av[1] = my_itoa(getpid(), 0);
    av[2] = my_itoa(getpid(), 0);
    av[3] = NULL;
    cr_expect_eq(connection(av, navy), -1);
}
