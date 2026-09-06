/*
** EPITECH PROJECT, 2018
** random_choose_two
** File description:
** random_choose_two
*/

#include "random_choose_two.h"

void random_choose_person_d_o(variable_t *sf)
{
    int perso_have_choise = rand_person();

    is_ext_random_choose_person_d_o(sf, perso_have_choise);
    if (perso_have_choise == 2)
        create_riven_d_o(sf);
    if (perso_have_choise == 3)
        create_robot_d_o(sf);
    if (perso_have_choise == 4)
        create_cowboy_d_o(sf);
    if (perso_have_choise == 5)
        create_lucky_luke_d_o(sf);
    if (perso_have_choise == 6)
        create_mf_d_o(sf);
    if (perso_have_choise == 7)
        create_mccree_d_o(sf);
    if (perso_have_choise == 8)
        create_mccree_two_d_o(sf);
    if (perso_have_choise == 9)
        create_boss_d_o(sf);
}

void is_ext_random_choose_person_d_t(variable_t *sf, int perso_have_choise)
{
    if (perso_have_choise == 0)
        create_dalton_d_t(sf);
    if (perso_have_choise == 1)
        create_jinx_d_t(sf);
}

void random_choose_person_d_t(variable_t *sf)
{
    int perso_have_choise = rand_person();

    is_ext_random_choose_person_d_t(sf, perso_have_choise);
    if (perso_have_choise == 2)
        create_riven_d_t(sf);
    if (perso_have_choise == 3)
        create_robot_d_t(sf);
    if (perso_have_choise == 4)
        create_cowboy_d_t(sf);
    if (perso_have_choise == 5)
        create_lucky_luke_d_t(sf);
    if (perso_have_choise == 6)
        create_mf_d_t(sf);
    if (perso_have_choise == 7)
        create_mccree_d_t(sf);
    if (perso_have_choise == 8)
        create_mccree_two_d_t(sf);
    if (perso_have_choise == 9)
        create_boss_d_t(sf);
}

void is_ext_random_choose_person_b(variable_t *sf, int perso_have_choise)
{
    if (perso_have_choise == 0)
        create_dalton_b(sf);
    if (perso_have_choise == 1)
        create_jinx_b(sf);
}

void random_choose_person_b(variable_t *sf)
{
    int perso_have_choise = rand_person();

    is_ext_random_choose_person_b(sf, perso_have_choise);
    if (perso_have_choise == 2)
        create_riven_b(sf);
    if (perso_have_choise == 3)
        create_robot_b(sf);
    if (perso_have_choise == 4)
        create_cowboy_b(sf);
    if (perso_have_choise == 5)
        create_lucky_luke_b(sf);
    if (perso_have_choise == 6)
        create_mf_b(sf);
    if (perso_have_choise == 7)
        create_mccree_b(sf);
    if (perso_have_choise == 8)
        create_mccree_two_b(sf);
    if (perso_have_choise == 9)
        create_boss_b(sf);
}
