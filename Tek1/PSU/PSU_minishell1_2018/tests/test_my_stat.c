/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "stddef.h"
#include "my_lib.h"
#include "my_struct.h"

static char is_type(struct stat sb);
static char is_permission(char const *dir);
char my_stat(char const *dir, int cas);

Test(my_stat, my_stat_cas_zero)
{
    cr_expect_eq(my_stat("./lib/", 0), 'd');
}

Test(my_stat, my_stat_cas_one)
{
    cr_expect_eq(my_stat("./lib/", 1), 'x');
}

Test(my_stat, my_stat_error_null)
{
    cr_expect_eq(my_stat(NULL, 1), 'e');
}

Test(my_stat, my_stat_error_cas)
{
    cr_expect_eq(my_stat("./lib/", 99), 'e');
}

Test(my_stat, my_stat_error_fault_file)
{
    cr_expect_eq(my_stat("./azeaze/", 1), 'e');
}

Test(is_permission, is_permission_access)
{
    cr_expect_eq(my_stat("./lib/", 1), 'x');
}

Test(is_permission, is_permission_no_access)
{
    cr_expect_eq(my_stat("/root/", 1), 'e');
}

Test(is_type, is_type_file)
{
    cr_expect_eq(my_stat("./includes/my_struct.h", 0), 'f');
}

Test(is_type, is_type_link)
{
    cr_expect_eq(my_stat("/bin", 0), 'd');
}