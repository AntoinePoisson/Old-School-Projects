/*
** EPITECH PROJECT, 2018
** load_map
** File description:
** load map of sokoban
*/

#include "load_map.h"

int stat_size(char const *filepath)
{
    struct stat sb;

    stat(filepath, &sb);
    return (sb.st_size);
}

void check_map_right(char *memory_area)
{
    for (int i = 0; memory_area[i] != '\0'; i++)
        if (!(memory_area[i] == ' ' || memory_area[i] == '\n' || memory_area[i]
            == '#' || memory_area[i] == 'X' || memory_area[i] == 'O'
            || memory_area[i] == 'P')) {
            my_putstr("Invalide file\n");
            exit(84);
        }
}

char **load_2d_arr_from_file(char *memory, int *nb_rows, int *nb_cols)
{
    char **tab = malloc(sizeof(char *) * (*nb_rows + 1));
    int i = 0;
    int position_memory = 0;

    tab[0] = malloc(sizeof(char) * *nb_cols);
    if (tab[0] == NULL) {
        my_putstr("error for allocation of memory\n");
        exit(84);
    }
    for (i = 0; memory[i] != '\n'; i++, position_memory++)
        tab[0][i] = memory[i];
    position_memory++;
    for (i = 1; i <= *nb_rows; i++) {
        tab[i] = malloc(sizeof(char) * *nb_cols);
        for (int i_two = 0; i_two <= *nb_cols; i_two++, position_memory++) {
            if (memory[position_memory] == '\n') {
                position_memory++;
                break;
            }
            tab[i][i_two] = memory[position_memory];
        }
    }
    return (tab);
}

char **load_map(char const *filepath, int *nb_rows, int *nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    int size_read = stat_size(filepath);
    char *memory_area = malloc(sizeof(char) * size_read);

    if (fd == -1 || memory_area == NULL) {
        my_putstr("Error for allocation of memory or file open\n");
        exit(84);
    }
    size_read = read(fd, memory_area, size_read);
    if (size_read == -1) {
        my_putstr("Error for file read\n");
        exit(84);
    }
    *nb_rows = count_rows(memory_area);
    *nb_cols = count_cols_check(memory_area);
    close(fd);
    check_map_right(memory_area);
    return (load_2d_arr_from_file(memory_area, nb_rows, nb_cols));
}
