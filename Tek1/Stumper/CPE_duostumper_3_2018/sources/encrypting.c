/*
** EPITECH PROJECT, 2019
** encrypting.c
** File description:
** encrypting
*/

#include <stddef.h>
#include "my_lib.h"

int write_file(char *result);
char **create_tab_alpha(void);
char *take_data_of_file(char const *file);
char *cesar_decrypt(char *file, char **alphabert, int nb);

int encrypting(char *av[], int cas)
{
    char **alpha = NULL;
    char *result = NULL;

    if ((alpha = create_tab_alpha()) == NULL)
        return (my_puterror("Failure Malloc.\n"));
    if (cas == 1 && (result = take_data_of_file(av[2])) == NULL)
        return (my_puterror("Cannot read in file.\n"));
    if (cas == 2 && (result = my_strdup(av[2])) == NULL)
        return (my_puterror("Failure Malloc.\n"));
    if ((result = cesar_decrypt(result, alpha, my_getnbr(av[3]))) == NULL)
        return (84);
    if (write_file(result) == 84)
        return (84);
    return (0);
}
