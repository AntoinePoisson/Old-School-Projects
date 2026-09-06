/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** manage_options.c
*/

#include "my_tetris.h"
#include <term.h>

options_t init_opt(void)
{
    options_t opt;

    opt.level = 0;
    if (setupterm(NULL, STDIN_FILENO, (int *)0) == ERR) return (opt);
    opt.keys.left = tigetstr("kcub1");
    opt.keys.right = tigetstr("kcuf1");
    opt.keys.turn = tigetstr("kcuu1");
    opt.keys.drop = tigetstr("kcud1");
    if (!opt.keys.left || !opt.keys.right || !opt.keys.turn || !opt.keys.drop)
        return (opt);
    opt.speed = 5;
    opt.map = NULL;
    opt.hide = false;
    opt.debug = false;
    opt.level = 1;
    opt.size.row = 20;
    opt.size.col = 10;
    opt.keys.quit = "q";
    opt.keys.pause = " ";
    return (opt);
}

int analyze_flags_opt(char const **av, options_t *opt)
{
    int check = -1;

    for (int a = 1; av[a] != NULL; a++) {
        check = is_level_opt(av, opt, &a);
        check = (check < 0) ? is_key_opt(av, opt, &a) : check;
        check = (check < 0) ? is_map_size_opt(av, opt, &a) : check;
        check = (check < 0) ? is_others_opt(av, opt, a) : check;
        if (check != 0)
            return (check < 0) ? write(2, "Wrong option.\n", 14) : EXIT_ERROR;
    }
    return (EXIT_SUCCESS);
}

int is_level_opt(char const **av, options_t *opt, int *a)
{
    int is_hook = 0;

    if (str_comp(av[*a], "-L") < 0 && my_strncmp(av[*a], "--level=", 8) < 0)
        return (-1);
    if (my_strncmp(av[*a], "--level=", 8) == 0) {
        is_hook = (av[*a][8] == '{') ? 9 : 8;
        if (is_num(&av[*a][is_hook]) < 0 || my_getnbr(&av[*a][is_hook]) < 1)
            return (write(2, "Wrong level number.\n", 20));
        opt->level = my_getnbr(&av[*a][is_hook]);
    } else {
        is_hook = (av[*a + 1] && av[*a + 1][0] == '{') ? 1 : 0;
        if (!av[*a + 1] || is_num(&av[*a + 1][is_hook]) < 0
            || my_getnbr(&av[*a + 1][is_hook]) < 1)
            return (write(2, "Wrong level number.\n", 20));
        opt->level = my_getnbr(&av[*a + 1][is_hook]);
        *a += 1;
    }
    return (EXIT_SUCCESS);
}

int is_others_opt(char const **av, options_t *opt, int a)
{
    if (str_comp(av[a], "-D") < 0 && str_comp(av[a], "--debug") < 0 &&
        str_comp(av[a], "-w") < 0 && str_comp(av[a], "--without-next") < 0)
        return (-1);
    if (str_comp(av[a], "-D") == 0 || str_comp(av[a], "--debug") == 0)
        opt->debug = true;
    else
        opt->hide = true;
    return (EXIT_SUCCESS);
}

int is_map_size_opt(char const **av, options_t *opt, int *a)
{
    char *tmp = NULL;

    if (my_strncmp(av[*a], "--map-size=", 11) < 0)
        return (-1);
    tmp = my_strchr((char *)&av[*a][11], ',');
    if (tmp) {
        if (my_getnbr(&av[*a][11]) <= 0 || !tmp || my_getnbr(&tmp[1]) <= 0 ||
            is_num(&tmp[1]) < 0)
            return (write(2, "Wrong size of map.\n", 19));
        opt->size.row = my_getnbr(&av[*a][11]);
        opt->size.col = my_getnbr(&tmp[1]);
    } else {
        if (my_getnbr(&av[*a][11]) <= 0 || !av[*a + 1] ||
            my_getnbr(&av[*a + 1][11]) <= 0 ||
            my_strncmp(av[*a + 1], "--map-size=", 11) < 0)
            return (write(2, "Wrong size of map.\n", 19));
        opt->size.row = my_getnbr(&av[(*a)++][11]);
        opt->size.col = my_getnbr(&av[*a][11]);
    }
    return (EXIT_SUCCESS);
}
