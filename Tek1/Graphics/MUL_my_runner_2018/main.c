/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stddef.h>

int is_option_h(void);
int menu(char *av[], int ac);
int open_file(char *av[], int ac);
int my_putstr(char const *str);

int main(int ac, char *av[], char **env)
{
    int fd = 0;

    if (env[0] == NULL)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' &&
        av[1][2] == '\0')
        return (is_option_h());
    fd = open_file(av, ac);
    if (ac < 2) {
        my_putstr("Invalid Argument.\n");
        return (84);
    }
    if (fd == -1 && ac > 2) {
        my_putstr("Invalid file.\n");
        return (84);
    }
    return (menu(av, ac));
}
