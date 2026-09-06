/*
** EPITECH PROJECT, 2018
** check_error
** File description:
** check_error
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int display_help(void)
{
    printf("USAGE\n\t./103cipher message key flag\n");
    printf("DESCRIPTION\n\tmessage    a message, made");
    printf("ASCII characters\n\tkey        the encryption");
    printf(" key, made of ASCII characters\n\tflag       ");
    printf("0 for the message to be encrypted, 1 to be decrypted\n");
    return (EXIT_SUCCESS);
}

int check_error(int ac, char *av[])
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_help();
        exit(EXIT_SUCCESS);
    }
    if (ac != 4 || av[1] == NULL || av[2] == NULL) {
        my_puterror("Invalid Input\n");
        exit(EXIT_ERROR);
    }
    if (!(av[3][0] >= '0' && av[3][0] <= '1' && av[3][1] == '\0')) {
        my_puterror("Invalid Input\n");
        exit(EXIT_ERROR);
    }
    return (0);
}
