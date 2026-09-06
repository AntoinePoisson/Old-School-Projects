/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** redirect
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
