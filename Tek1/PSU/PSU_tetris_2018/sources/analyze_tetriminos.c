/*
** EPITECH PROJECT, 2019
** analyze_tetriminos.c
** File description:
** analyzation of tetriminos directory
*/

#include "my_tetris.h"

int check_tetriminos(void)
{
    DIR *fd = NULL;

    if ((fd = opendir("./tetriminos/")) == NULL)
        return (my_puterror("No tetriminos directory.\n"));
    closedir(fd);
    return (EXIT_SUCCESS);
}

int is_extension_calcul_row(char **str, int *i, int *find_block)
{
    int col = 0;
    int i_two = 0;

    for (; str[*i][i_two]; i_two++) {
        col += 1;
        if (str[*i][i_two] == '*') {
            *find_block = 1;
        }
    }
    for (i_two -= 1; str[*i][i_two] != '*' && i_two >= 0; i_two--)
        col--;
    return (col);
}

void sort_alphabetically(options_t *opt)
{
    int limit = size_list(opt);
    tetrimino_t *one = opt->map;
    tetrimino_t *two = opt->map;

    for (int i = 0; i < limit && one; i++, one = one->next, two = opt->map) {
        for (int i_two = 0; i_two < limit && two; i_two++, two = two->next) {
            if (my_strcmp(one->name, two->name) < 0) {
                swap_node(&one, &two);
            }
        }
    }
}

int read_file_info(options_t *opt, DIR *folder)
{
    int i = 1;

    for (struct dirent *file = readdir(folder); file; file = readdir(folder)) {
        if (check_right_extension(file->d_name) && take_data(opt, file->d_name)
            == 84) {
            free_node(opt);
        }
    }
    for (tetrimino_t *tetris = opt->map; tetris; tetris = tetris->next){
        for (i = 1; tetris->tetrimino && tetris->tetrimino[i]; i++)
            tetris->tetrimino[i - 1] = tetris->tetrimino[i];
        if (tetris->tetrimino)
            tetris->tetrimino[i - 1] = NULL;
    }
    return (0);
}
