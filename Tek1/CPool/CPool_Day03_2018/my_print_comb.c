/*
** EPITECH PROJECT, 2018
** my_print_comb
** File description:
** Displays, in ascending order, all the numbers composed by three different digits numbers (012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789.
*/

int my_print_comb(void)
{
    char nbr1 = 48;
    char nbr2 = 48;
    char nbr3 = 48;

    for (nbr1 = 48 ; nbr1 != 58 ; nbr1 = nbr1 + 1) {
        for (nbr2 = 48 ; nbr2 != 58 ; nbr2 = nbr2 + 1) {
            for (nbr3 = 48 ; nbr3 != 58 ; nbr3 = nbr3 + 1) {
                if (nbr1 < nbr2 && nbr2 < nbr3) {
                    my_putchar(nbr1);
                    my_putchar(nbr2);
                    my_putchar(nbr3);
                    if (!(nbr1 == 55 && nbr2 == 56 && nbr3 == 57)) {
                            my_putchar(44);
                            my_putchar(32);
                }    
                }
            }
        }
    }
    return (0);
}
