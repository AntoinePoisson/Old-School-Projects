/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <stddef.h>
#include "my_lib.h"

int check_if_encrypt(int ac, char *av[]);
int check_error(int ac, char *av[]);
char **create_tab_alpha(void);
char *take_data_of_file(char const *file);
char *cesar_decrypt(char *file, char **alphabert, int nb);
int encrypting(char *av[], int cas);
int check_if_encrypt(int ac, char *av[]);

int main(int ac, char *av[])
{
    char **alpha = NULL;
    char *result = NULL;
    int cas = 0;

    if ((cas = check_if_encrypt(ac, av)) != 0 && cas != 84)
        return (encrypting(av, cas));
    if (cas == 84)
        return (84);
    if (check_error(ac, av) != 0)
        return (84);
    if ((alpha = create_tab_alpha()) == NULL)
        return (my_puterror("Failure Malloc.\n"));
    if ((result = take_data_of_file(av[1])) == NULL)
        return (my_puterror("Cannot read in file.\n"));
    if ((result = cesar_decrypt(result, alpha, my_getnbr(av[2]))) == NULL)
        return (84);
    my_putstr(result);
    return (0);
}
