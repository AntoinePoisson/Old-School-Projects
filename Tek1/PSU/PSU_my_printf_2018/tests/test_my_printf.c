/*
** EPITECH PROJECT, 2018
** test_my_printf
** File description:
** test my printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int is_extension_printf_four(char *str, int i, va_list ap, int previous);
int is_extension_printf_three(char *str, int i, va_list ap);
int is_extension_printf_two(char *str, int i, va_list ap);
int is_extension_printf(char *str, int i, va_list ap);
int is_extension_my_printf(char *str, int i);
int my_printf(char *str, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_extension_printf, pourcentd, .init = redirect_all_std)
{
    int nbr = 1234567;

    my_printf("%d", nbr);
    cr_stdout_match_str("1234567");
}

Test(is_extension_printf, pourcentdneg, .init = redirect_all_std)
{
    int nbr = -123456;

    my_printf("%d", nbr);
    cr_stdout_match_str("-123456");
}

Test(is_extension_printf, pourcenti, .init = redirect_all_std)
{
    int nbr = 12345678;

    my_printf("%i", nbr);
    cr_stdout_match_str("12345678");
}

Test(is_extension_printf, pourcentineg, .init = redirect_all_std)
{
    int nbr = -12345678;

    my_printf("%i", nbr);
    cr_stdout_match_str("-12345678");
}

Test(is_extension_printf, pourcentc, .init = redirect_all_std)
{
    my_printf("%c", 'A');
    cr_stdout_match_str("A");
}

Test(is_extension_printf, pourcentb, .init = redirect_all_std)
{
    int nbr = 123;

    my_printf("%b", nbr);
    cr_stdout_match_str("1111011");
}

Test(is_extension_printf, pourcentX, .init = redirect_all_std)
{
    int nbr = 123;

    my_printf("%X", nbr);
    cr_stdout_match_str("7B");
}

Test(is_extension_printf_two, pourcentx, .init = redirect_all_std)
{
    int nbr = 123;

    my_printf("%x", nbr);
    cr_stdout_match_str("7b");
}

Test(is_extension_printf_two, pourcents, .init = redirect_all_std)
{
    char chara[] = "TEST_UNITAIRE";

    my_printf("%s", chara);
    cr_stdout_match_str("TEST_UNITAIRE");
}

Test(is_extension_printf_two, pourcents_null, .init = redirect_all_std)
{
    void *chara = NULL;

    my_printf("%s", chara);
    cr_stdout_match_str("(null)");
}

Test(is_extension_printf, normal_print, .init = redirect_all_std)
{
    my_printf("123NBR\nCHarac");
    cr_stdout_match_str("123NBR\nCHarac");
}

Test(is_extension_printf_two, pourcentpourcent, .init = redirect_all_std)
{
    my_printf("%%");
    cr_stdout_match_str("%");
}

Test(is_extension_printf_three, pourcentS, .init = redirect_all_std)
{
    my_printf("%S", '\r');
    cr_stdout_match_str("015");
}

Test(is_extension_printf_three, pourcentS2, .init = redirect_all_std)
{
    my_printf("%S", '\a');
    cr_stdout_match_str("007");
}

Test(is_extension_printf_three, pourcentS3, .init = redirect_all_std)
{
    my_printf("%S", 'A');
    cr_stdout_match_str("A");
}

Test(is_extension_printf_three, pourcento, .init = redirect_all_std)
{
    int nbr = 123;

    my_printf("%o", nbr);
    cr_stdout_match_str("173");
}

Test(is_extension_printf_three, pourcentlu, .init = redirect_all_std)
{
    int nbr = -123456789;

    my_printf("%lu", nbr);
    cr_stdout_match_str("123456789");
}

Test(is_extension_printf_four, pourcentld, .init = redirect_all_std)
{
    int nbr = 123456789;

    my_printf("%ld", nbr);
    cr_stdout_match_str("123456789");
}

Test(is_extension_printf_four, pourcentu, .init = redirect_all_std)
{
    int nbr = -123;

    my_printf("%u", nbr);
    cr_stdout_match_str("123");
}

Test(my_printf, pourcentp, .init = redirect_all_std)
{
    int nbr = 5;
    int *pointor = &nbr;
    char string[1000];

    my_printf("%p", pointor);
    sprintf(string, "%p", pointor);
    cr_stdout_match_str(string);
}

Test(my_printf, pourcentp_null, .init = redirect_all_std)
{
    int *pointor = NULL;
    char string[1000];

    my_printf("%p", pointor);
    sprintf(string, "%p", pointor);
    cr_stdout_match_str(string);
}

Test(is_extension_my_printf, pourcentn, .init = redirect_all_std)
{
    my_printf("1 2 3 4 5%n 1 2 3 4 5");
    cr_stdout_match_str("9");
}
