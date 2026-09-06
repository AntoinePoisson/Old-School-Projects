/*
** EPITECH PROJECT, 2018
** test_my_getnbr
** File description:
** test_my_getnbr
*/

#include <criterion/criterion.h>
//#include <criterion/redirect.h>

int nbrimpair(char const *chaine);
int char_to_int(char str);
int place_recovery_two(int nbr_chiffre, char stokage[], int int_return);
int place_recovery_one(char const *str, int i, int int_return);
int my_getnbr(char const *str);
/*
void redirect_all_s(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}*/

Test(my_getnbr, impairnbr_nbr)
{
    cr_expect_eq(nbrimpair("-123456789"), 0);
}

Test(my_getnbr, impairnbr_posi)
{
    cr_expect_eq(nbrimpair("--123456789"), 1);
}

Test(my_getnbr, char_to_int)
{
    cr_expect_eq(char_to_int('0'), 0);
}
/*
Test(my_getnbr, place_recovery_two_big)
{
    char nbr[] = "276447232";
    cr_expect_eq(place_recovery_two(9, nbr, 0), 0);
}

Test(my_getnbr, place_recovery_two_nor)
{
    char nbr[] = "276";
    int i = 0;
    int size = 0;
    cr_expect_eq(place_recovery_two(size, nbr, i), 276);
}

Test(my_getnbr, place_recovery_two_one)
{
    char const nbr[] = "276";
    int resul = 0;
    int i = 0;
    cr_expect_eq(place_recovery_one(nbr, i, resul), 276);
}
*/
Test(my_getnbr, my_getnbr)
{
    char const nbr[] = "276";
    printf("%d", my_getnbr(nbr));
    cr_expect_eq(my_getnbr(nbr), 6);
}