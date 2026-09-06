/*
** EPITECH PROJECT, 2018
** random_choose
** File description:
** random_choose
*/

#include "random_choose.h"

void is_ext_random_choose_person_w_o_w_t(variable_t *sf, int perso_have_choise)
{
    if (perso_have_choise == 0)
        create_dalton_w_t(sf);
    if (perso_have_choise == 1)
        create_jinx_w_t(sf);
}

void random_choose_person_w_o_w_t(variable_t *sf)
{
    int perso_have_choise = rand_person();

    is_ext_random_choose_person_w_o_w_t(sf, perso_have_choise);
    if (perso_have_choise == 2)
        create_riven_w_t(sf);
    if (perso_have_choise == 3)
        create_robot_w_t(sf);
    if (perso_have_choise == 4)
        create_cowboy_w_t(sf);
    if (perso_have_choise == 5)
        create_lucky_luke_w_t(sf);
    if (perso_have_choise == 6)
        create_mf_w_t(sf);
    if (perso_have_choise == 7)
        create_mccree_w_t(sf);
    if (perso_have_choise == 8)
        create_mccree_two_w_t(sf);
    if (perso_have_choise == 9)
        create_boss_w_t(sf);
}

void is_ext_random_choose_person_w_o(variable_t *sf, int perso_have_choise)
{
    if (perso_have_choise == 0)
        create_dalton_w_o(sf);
    if (perso_have_choise == 1)
        create_jinx_w_o(sf);
}

void random_choose_person_w_o(variable_t *sf)
{
    int perso_have_choise = rand_person();

    is_ext_random_choose_person_w_o(sf, perso_have_choise);
    if (perso_have_choise == 2)
        create_riven_w_o(sf);
    if (perso_have_choise == 3)
        create_robot_w_o(sf);
    if (perso_have_choise == 4)
        create_cowboy_w_o(sf);
    if (perso_have_choise == 5)
        create_lucky_luke_w_o(sf);
    if (perso_have_choise == 6)
        create_mf_w_o(sf);
    if (perso_have_choise == 7)
        create_mccree_w_o(sf);
    if (perso_have_choise == 8)
        create_mccree_two_w_o(sf);
    if (perso_have_choise == 9)
        create_boss_w_o(sf);
}

void is_ext_random_choose_person_d_o(variable_t *sf, int perso_have_choise)
{
    if (perso_have_choise == 0)
        create_dalton_d_o(sf);
    if (perso_have_choise == 1)
        create_jinx_d_o(sf);
}
