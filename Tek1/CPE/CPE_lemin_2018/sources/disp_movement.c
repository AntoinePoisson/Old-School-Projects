/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** display_movement.c
*/

#include "lem_in.h"

void disp(int ant, char *movement)
{
    write(1, "P", 1);
    my_putnbr(ant);
    write(1, "-", 1);
    my_putstr(movement);
}
