/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mput.c
*/

#include <unistd.h>

void mp_mput(char c)
{
    write(1, &c, 1);
}
