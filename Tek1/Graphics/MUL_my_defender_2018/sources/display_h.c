/*
** EPITECH PROJECT, 2019
** display_h
** File description:
** diplay -h
*/

#include <unistd.h>

int display_h(void)
{
    write(1, "DESCRIPTION :\n", 14);
    write(1, "\t./my_defender\t\t\t:  Launch game.\n", 33);
    write(1, "\t./my_defender --hitbox\t\t:  Launch game with hitbox.\n", 53);
    write(1, "\t./my_defender -h\t\t:  Show help.\n", 33);
    write(1, "USER INPUTS :\n", 14);
    write(1, "\tMouse\t: Play.\n\tEchap\t: Pause the game.\n", 40);
    write(1, "\tQ\t: To quit the pause game.\n", 29);
    return (0);
}
