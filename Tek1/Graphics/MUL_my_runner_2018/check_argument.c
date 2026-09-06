/*
** EPITECH PROJECT, 2018
** check_argument
** File description:
** check_argument
*/

#include "my_lib.h"
#include "struct.h"

int is_option_h(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n\t./my_runner map.txt OPTIONS\n\n");
    my_putstr("OPTIONS\n\t-i\t\tlaunch the game in infinity mode.\n");
    my_putstr("\t-g\t\tgod mode.\n\t-hi\t\tdisplay hitbox.\n");
    my_putstr("\t-bi\t\tbird mode, random spawn.\n");
    my_putstr("\t-h\t\tprint the usage and quit.\n\nUSER INTER");
    my_putstr("ACTIONS\n  SPACE_KEY\t\tjump.\n");
    my_putstr("  A_KEY\t\t\tacceleration power.\n");
    my_putstr("  Z_KEY\t\t\tjump.\n");
    my_putstr("  Q_KEY\t\t\tmove right.\n");
    my_putstr("  S_KEY\t\t\tget down or cancel jump.\n");
    my_putstr("  D_KEY\t\t\tmove left.\n");
    return (0);
}

void check_argument(char *av[], int ac, variable_t *sf)
{
    sf->var_norm.infinity_mode = 0;
    sf->var_norm.bird_mode = 0;
    sf->var_norm.bonus_mode = 0;
    sf->var_norm.hitbox_mode = 0;
    sf->var_norm.god_mode = 0;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'i' && av[i][2] == '\0')
            sf->var_norm.infinity_mode = 1;
        if (av[i][0] == '-' && av[i][1] == 'h' && av[i][2] == 'i'
            && av[i][3] == '\0')
            sf->var_norm.hitbox_mode = 1;
        if (av[i][0] == '-' && av[i][1] == 'g' && av[i][2] == '\0')
            sf->var_norm.god_mode = 1;
        if (av[i][0] == '-' && av[i][1] == 'b' && av[i][2] == 'i' &&
            av[i][3] == '\0')
            sf->var_norm.bird_mode = 1;
        if (av[i][0] == '-' && av[i][1] == 'b' && av[i][2] == 'o' &&
            av[i][3] == '\0')
            sf->var_norm.bonus_mode = 1;
    }
}
