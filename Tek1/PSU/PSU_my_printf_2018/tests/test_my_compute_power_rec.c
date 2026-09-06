/*
** EPITECH PROJECT, 2018
** test_my_compute_power_rec
** File description:
** test my compute power rec
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_put_nbr(int nb);
int my_compute_power_rec(int nb, int p);
char *my_itoa(int nbr, int neg);

void redirect_all_stdou(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_compute_power_rec, nbr_posi, .init = redirect_all_stdou)
{
    my_put_nbr(my_compute_power_rec(10, 5));
    cr_stdout_match_str(my_itoa(10000, 0));
}

Test(my_compute_power_rec, nbr_neg, .init = redirect_all_stdou)
{
    my_put_nbr(my_compute_power_rec(-10, 5));
    cr_stdout_match_str(my_itoa(-10000, 1));
}

Test(my_compute_power_rec, nbr_zero, .init = redirect_all_stdou)
{
    my_put_nbr(my_compute_power_rec(0, 0));
    cr_stdout_match_str(my_itoa(0, 0));
}

Test(my_compute_power_rec, nbr_neg_two, .init = redirect_all_stdou)
{
    my_put_nbr(my_compute_power_rec(0, -1));
    cr_stdout_match_str(my_itoa(0, 0));
}
