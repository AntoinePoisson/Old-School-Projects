/*
** EPITECH PROJECT, 2018
** check_error
** File description:
** check_error
*/

#include <unistd.h>
#include <my_lib.h>

char *bubble_sort_array(char **array, int ac, char *size_max, int *sort);
char *compare_size(char *size_max, char *element);

int check_error_two(int ac)
{
    if (ac == 1) {
        write(2, "Invalid argument.\n", 19);
        return (84);
    }
    return (0);
}

int check_error_three(int ac)
{
    if (ac == 2) {
        write(1, "\n", 1);
        return (1);
    }
    return (0);
}

char *check_error(char *av[], int ac, char *size_max)
{
    int sort = 1;

    size_max = bubble_sort_array(av, ac, size_max, &sort);
    if (sort == 1) {
        write(1, "\n", 1);
        return ("-");
    }
    return (size_max);
}
