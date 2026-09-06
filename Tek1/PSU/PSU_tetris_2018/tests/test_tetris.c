/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>
#include "my_tetris.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(size_list, size_list, .init = redirect_all_stdout)
{
    options_t *opt = malloc(sizeof(options_t *));

    opt->map = NULL;
    cr_expect_eq(size_list(opt), 0);
}

Test(take_obj_random, take_obj_random, .init = redirect_all_stdout)
{
    options_t opt;

    opt.map = malloc(sizeof(tetrimino_t *));
    opt.map->tetrimino = malloc(sizeof(char *));
    opt.nbr_tetrimino = 2;
    opt.size.col = 6;
    opt.size.row = 6;
    opt.obj = NULL;
    cr_expect_eq(take_obj_random(&opt), 0);
}

Test(check_move_down, check_move_down, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = malloc(sizeof(char *) * 6);
    opt.plan[0] = "       ";
    opt.plan[1] = "       ";
    opt.plan[2] = "       ";
    opt.plan[3] = "       ";
    opt.plan[4] = "       ";
    opt.plan[5] = NULL;
    cr_expect_eq(check_move_down(&opt, opt.plan), true);
}

Test(check_move_right, check_move_right, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = malloc(sizeof(char *) * 6);
    opt.plan[0] = "       ";
    opt.plan[1] = "       ";
    opt.plan[2] = "       ";
    opt.plan[3] = "       ";
    opt.plan[4] = "       ";
    opt.plan[5] = NULL;
    cr_expect_eq(check_move_right(&opt, opt.plan), true);
}

Test(check_move_left, check_move_left, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = malloc(sizeof(char *) * 6);
    opt.plan[0] = "       ";
    opt.plan[1] = "       ";
    opt.plan[2] = "       ";
    opt.plan[3] = "       ";
    opt.plan[4] = "       ";
    opt.plan[5] = NULL;
    cr_expect_eq(check_move_left(&opt, opt.plan), true);
}

Test(move_down, move_down, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = malloc(sizeof(char *) * 6);
    opt.plan[0] = "       ";
    opt.plan[1] = "       ";
    opt.plan[2] = "       ";
    opt.plan[3] = "       ";
    opt.plan[4] = "       ";
    opt.plan[5] = NULL;
    cr_expect_eq(move_down(&opt), 0);
}

Test(move_right, move_right, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = malloc(sizeof(char *) * 6);
    opt.plan[0] = "       ";
    opt.plan[1] = "       ";
    opt.plan[2] = "       ";
    opt.plan[3] = "       ";
    opt.plan[4] = "       ";
    opt.plan[5] = NULL;
    cr_expect_eq(move_right(&opt), 0);
}

Test(move_left, move_left, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = malloc(sizeof(char *) * 6);
    opt.plan[0] = "       ";
    opt.plan[1] = "       ";
    opt.plan[2] = "       ";
    opt.plan[3] = "       ";
    opt.plan[4] = "       ";
    opt.plan[5] = NULL;
    cr_expect_eq(move_left(&opt), 0);
}

Test(check_kill_line, check_kill_line, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    opt.plan = my_malloc_two_d(2);
    cr_expect_eq(check_kill_line(&opt), 0);
}

Test(init_map, init_map, .init = redirect_all_stdout)
{
    options_t opt;

    opt.size.col = 5;
    opt.size.row = 5;
    cr_expect_neq(init_map(&opt), NULL);
}

Test(insert_obj, insert_obj, .init = redirect_all_stdout)
{
    options_t opt;

    opt.obj = malloc(sizeof(random_obj_t));
    opt.obj->posi_spawn = 2;
    cr_expect_neq(insert_obj(&opt, NULL), 0);
}

Test(stat_size, stat_size, .init = redirect_all_stdout)
{
    cr_expect_neq(stat_size("./Makefile"), 0);
}

Test(add_node, add_node, .init = redirect_all_stdout)
{
    options_t *opt = malloc(sizeof(options_t *));

    cr_expect_eq(add_node(opt), 0);
}

Test(set_newterm, set_newterm, .init = redirect_all_stdout)
{
    cr_expect_neq(set_newterm(), 84);
}

Test(free_node, free_node, .init = redirect_all_stdout)
{
    options_t *opt = malloc(sizeof(options_t *));

    cr_expect_eq(free_node(opt), 0);
}

Test(free_node, free_node_two, .init = redirect_all_stdout)
{
    options_t *opt = malloc(sizeof(options_t *));
    tetrimino_t *one = malloc(sizeof(tetrimino_t *));
    tetrimino_t *two = malloc(sizeof(tetrimino_t *));

    two->next = NULL;
    opt->map = one;
    opt->map->next = two;
    cr_expect_eq(free_node(opt), 0);
}

Test(tetris_title, tetris_title, .init = redirect_all_stdout)
{
    cr_expect_eq(tetris_title(), 0);
}

Test(init_colors, init_colors, .init = redirect_all_stdout)
{
    cr_expect_eq(init_colors(), 0);
}

Test(init_screen, init_screen, .init = redirect_all_stdout)
{
    cr_expect_eq(init_screen(), 0);
}

Test(help_opt, help_opt, .init = redirect_all_stdout)
{
    char const *str = "str";

    cr_expect_eq(help_opt(str), 0);
}

Test(change_name_of_file, change_name_of_file, .init = redirect_all_stdout)
{
    cr_expect_eq(change_name_of_file("AZE"), "AZE");
}

Test(change_name_of_file, change_name_of_file_two, .init = redirect_all_stdout)
{
    char test[] = "AZE.tetrimino";
    char *two = "AZE";

    cr_expect_neq(change_name_of_file(test), two);
}

Test(display_file_data, display_file_data, .init = redirect_all_stdout)
{
    tetrimino_t *tetris = malloc(sizeof(tetrimino_t *));

    tetris->tetrimino = NULL;
    cr_expect_eq(display_file_data(tetris), 0);
}

Test(display_file_data, display_file_data_one, .init = redirect_all_stdout)
{
    tetrimino_t *tetris = malloc(sizeof(tetrimino_t *));

    tetris->tetrimino = NULL;
    cr_expect_eq(display_file_data(tetris), 0);
}

Test(display_name_file, display_name_file_two, .init = redirect_all_stdout)
{
    tetrimino_t *tetris = malloc(sizeof(tetrimino_t *));

    tetris->tetrimino = NULL;
    cr_expect_eq(display_name_file(tetris), 1);
}

Test(display_name_file, display_name_file_two_three)
{
    cr_expect_eq(display_name_file(NULL), 1);
}

Test(display_debug_mode_file_part, display_debug_mode_file_part)
{
    options_t *opt = malloc(sizeof(options_t *));

    opt->map = NULL;
    cr_expect_eq(display_debug_mode_file_part(opt), 0);
}

Test(disp_key_bindings, disp_key_bindings)
{
    char const *str = "LOL";
    char *key = " t";

    cr_expect_eq(disp_key_bindings(str, key), 0);
}

Test(disp_key_bindings, disp_key_bindings_two)
{
    char const *str = "LOL";
    char *key = "an";

    cr_expect_eq(disp_key_bindings(str, key), 0);
}

Test(check_right_extension, check_right_extension)
{
    char const *str = "L.tetrimino";

    cr_expect_eq(check_right_extension(str), true);
}

Test(check_right_extension, check_right_extension_two)
{
    char const *str = ".tetrimino";

    cr_expect_eq(check_right_extension(str), false);
}

Test(check_right_extension, check_right_extension_three)
{
    char const *str = "A.tetriminoA";

    cr_expect_eq(check_right_extension(str), false);
}

Test(calcul_row, calcul_row)
{
    int col = 0;
    char **str = malloc(sizeof(char *) * 4);

    str[0] = "2 2 3";
    str[1] = "**";
    str[2] = "**";
    str[3] = NULL;
    cr_expect_eq(calcul_row(&col, str), 2);
}

Test(control_right_file, control_right_file_one)
{
    char **str = malloc(sizeof(char *) * 4);

    str[0] = "2 2 3";
    str[1] = "**";
    str[2] = "**";
    str[3] = NULL;
    cr_expect_eq(control_right_file(str, 0), 0);
}

Test(control_right_file, control_right_file)
{
    char **str = malloc(sizeof(char *) * 4);

    str[0] = "2 2 3";
    str[1] = "**";
    str[2] = "**";
    str[3] = NULL;
    cr_expect_eq(control_right_file(str, 1), 0);
}

Test(take_data, take_data)
{
    options_t *opt = malloc(sizeof(options_t *));

    cr_expect_eq(take_data(opt, "AZEAZEAZE"), 1);
}

Test(check_tetriminos, check_tetriminos)
{
    cr_expect_eq(check_tetriminos(), 0);
}

Test(tetris, tetris_main_loop)
{
    char *arg[2] = {"./tetris", NULL};

    cr_expect_neq(tetris((char const **)arg), 0);
}

Test(tetris, color_of_charac)
{
    cr_expect_eq(color_of_charac(NULL, 'a'), 14);
    cr_expect_eq(color_of_charac(NULL, '4'), 4);
    cr_expect_eq(color_of_charac(NULL, ' '), 14);
}
