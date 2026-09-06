/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

Test(research_signal, research_signal_one)
{
    cr_expect_eq(research_signal(1, 123), 1);
}

Test(research_signal, research_signal_three)
{
    cr_expect_eq(research_signal(3, 123), 1);
}

Test(research_signal, research_signal_four)
{
    cr_expect_eq(research_signal(4, 123), 1);
}

Test(research_signal, research_signal_five)
{
    cr_expect_eq(research_signal(5, 123), 1);
}

Test(research_signal, research_signal_six)
{
    cr_expect_eq(research_signal(6, 123), 1);
}

Test(research_signal, research_signal_seven)
{
    cr_expect_eq(research_signal(7, 123), 1);
}

Test(research_signal, research_signal_eight)
{
    cr_expect_eq(research_signal(8, 123), 1);
}

Test(research_signal, research_signal_nine)
{
    cr_expect_eq(research_signal(9, 123), 1);
}

Test(research_signal_two, research_signal_ten)
{
    cr_expect_eq(research_signal_two(10, 123), 1);
}

Test(research_signal_two, research_signal_eleven)
{
    cr_expect_eq(research_signal_two(11, 123), 1);
}

Test(research_signal_two, research_signal_twelve)
{
    cr_expect_eq(research_signal_two(12, 123), 1);
}

Test(research_signal_two, research_signal_thirteen)
{
    cr_expect_eq(research_signal_two(13, 123), 1);
}

Test(research_signal_two, research_signal_fourteen)
{
    cr_expect_eq(research_signal_two(14, 123), 1);
}

Test(research_signal_two, research_signal_fiveteen)
{
    cr_expect_eq(research_signal_two(15, 123), 1);
}

Test(research_signal_two, research_signal_sixteen)
{
    cr_expect_eq(research_signal_two(16, 123), 1);
}

Test(research_signal_two, research_signal_four)
{
    cr_expect_eq(research_signal_two(24, 123), 1);
}

Test(research_signal_two, research_signal_twenty_four)
{
    cr_expect_eq(research_signal_three(25, 123), 1);
}

Test(research_signal_two, research_signal_twenty_five)
{
    cr_expect_eq(research_signal_three(23, 123), 0);
}

Test(research_signal_three, research_signal_twenty_six)
{
    cr_expect_eq(research_signal_three(27, 123), 1);
}

Test(research_signal_three, research_signal_twenty_seven)
{
    cr_expect_eq(research_signal_three(28, 123), 0);
}

Test(research_signal_three, research_signal_twenty_nine)
{
    cr_expect_eq(research_signal_three(29, 123), 1);
}

Test(research_signal_three, research_signal_thirty)
{
    cr_expect_eq(research_signal_three(30, 123), 1);
}

Test(research_signal_three, research_signal_thirty_one)
{
    cr_expect_eq(research_signal_three(31, 123), 1);
}

Test(research_signal_three, research_signal_thirty_two)
{
    cr_expect_eq(research_signal_three(32, 123), 1);
}

Test(research_signal_three, research_signal_thirty_three)
{
    cr_expect_eq(research_signal_three(33, 123), 1);
}

Test(research_signal_three, research_signal_thirty_four)
{
    cr_expect_eq(research_signal_ext_one(34, 123), 1);
}

Test(research_signal_three, research_signal_thirty_five)
{
    cr_expect_eq(research_signal_ext_one(35, 123), 1);
}

Test(research_signal_ext_one, research_signal_thirty_six)
{
    cr_expect_eq(research_signal_ext_one(36, 123), 1);
}

Test(research_signal_ext_one, research_signal_thirty_seven)
{
    cr_expect_eq(research_signal_ext_one(37, 123), 1);
}

Test(research_signal_ext_one, research_signal_thirty_eight)
{
    cr_expect_eq(research_signal_ext_one(38, 123), 1);
}

Test(research_signal_ext_one, research_signal_thirty_nine)
{
    cr_expect_eq(research_signal_ext_one(39, 123), 1);
}

Test(research_signal_ext_one, research_signal_forty)
{
    cr_expect_eq(research_signal_ext_one(40, 123), 1);
}

Test(research_signal_ext_one, research_signal_forty_one)
{
    cr_expect_eq(research_signal_ext_one(41, 123), 1);
}

Test(research_signal_ext_one, research_signal_forty_two)
{
    cr_expect_eq(research_signal_ext_two(42, 123), 1);
}

Test(research_signal_ext_one, research_signal_forty_three)
{
    cr_expect_eq(research_signal_ext_two(43, 123), 1);
}

Test(research_signal_ext_two, research_signal_forty_four)
{
    cr_expect_eq(research_signal_ext_two(44, 123), 1);
}

Test(research_signal_ext_two, research_signal_forty_five)
{
    cr_expect_eq(research_signal_ext_two(45, 123), 1);
}

Test(research_signal_ext_two, research_signal_forty_six)
{
    cr_expect_eq(research_signal_ext_two(46, 123), 1);
}

Test(research_signal_ext_two, research_signal_forty_seven)
{
    cr_expect_eq(research_signal_ext_two(47, 123), 1);
}

Test(research_signal_ext_two, research_signal_forty_eight)
{
    cr_expect_eq(research_signal_ext_two(48, 123), 1);
}

Test(research_signal, research_signal_out)
{
    cr_expect_eq(research_signal(48, 123), 0);
}

Test(research_signal_three, research_signal_out_two)
{
    cr_expect_eq(research_signal_three(26, 123), 1);
}

Test(research_signal_ext_one, research_signal_out_three)
{
    cr_expect_eq(research_signal_ext_one(48, 123), 0);
}

Test(research_signal_ext_two, research_signal_out_four)
{
    cr_expect_eq(research_signal_ext_two(40, 123), 0);
}