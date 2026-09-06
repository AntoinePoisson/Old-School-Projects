/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** debug_mode.c
*/

#include "my_tetris.h"

int disp_key_bindings(char const *str, char *key)
{
    my_putstr(str);
    if (key[0] == 27)
        write(1, "^E", 2);
    if (key[1] == 't')
        return (my_putstr("(tab)\n"));
    if (key[1] == 'n')
        return (my_putstr("(enter)\n"));
    if (key[0] == ' ')
        return (my_putstr("(space)\n"));
    if (key[0] ^ 27)
        my_putstr(key);
    else
        my_putstr(&key[1]);
    return (write(1, "\n", 1));
}

int debug_mode(options_t *opt)
{
    if (opt->debug) {
        my_putstr("*** DEBUG MODE ***\n");
        disp_key_bindings("Key Left :  ", opt->keys.left);
        disp_key_bindings("Key Right :  ", opt->keys.right);
        disp_key_bindings("Key Turn :  ", opt->keys.turn);
        disp_key_bindings("Key Drop :  ", opt->keys.drop);
        disp_key_bindings("Key Quit :  ", opt->keys.quit);
        disp_key_bindings("Key Pause :  ", opt->keys.pause);
        disp_key_bindings("Next :  ", (opt->hide == false) ? "Yes" : "No");
        mprintf("Level :  %u", opt->level);
        mprintf("\nSize :  %u*%u\n", opt->size.row, opt->size.col);
        if (debug_tetriminos(opt, 1) == 84)
            return (EXIT_ERROR);
        my_putstr("Press any key to start Tetris\n");
        if (wait_input() == 84)
            return (EXIT_ERROR);
    } else if (debug_tetriminos(opt, 0) == 84)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}

bool check_right_extension(char const *name)
{
    int size = my_strlen(name);

    if (size <= 10 || name == NULL) {
        return (false);
    }
    if (my_strcmp(&name[size - 10], ".tetrimino") != 0) {
        return (false);
    }
    return (true);
}

int debug_tetriminos(options_t *opt, int cas)
{
    DIR *folder = opendir("./tetriminos/");
    DIR *size = opendir("./tetriminos/");

    opt->nbr_tetrimino = 0;
    if (!folder || !size)
        return (my_putstr("Tetriminos : Error\n"));
    for (struct dirent *tmp = readdir(size); tmp; tmp = readdir(size))
        opt->nbr_tetrimino += check_right_extension(tmp->d_name);
    if (opt->nbr_tetrimino == 0)
        return (EXIT_SUCCESS);
    closedir(size);
    if (read_file_info(opt, folder) == 84)
        return (EXIT_ERROR);
    if (cas == 1) {
        mprintf("Tetriminos :  %d\n", size_list(opt));
        sort_alphabetically(opt);
        display_debug_mode_file_part(opt);
    }
    closedir(folder);
    return (EXIT_SUCCESS);
}
