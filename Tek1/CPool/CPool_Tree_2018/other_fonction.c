/*                                                                                            
** EPITECH PROJECT, 2018                                                                      
** tree                                                                                       
** File description:                                                                          
** Write a function that displays a fir tree, based on its given size.                        
*/

void print_star_line(int nbr)
{
    int i = 0;

    for (i = 0; i < nbr + 2; i++)
        my_putchar('*');
}

int first_line(int size)
{
    int i = 0;
    int top_position = 0;

    if (size % 2 == 0 || size == 1) {
        top_position = 4 * size + (size - 2);
        for (i = 0; i < top_position; i++)
            my_putchar(' ');
        my_putchar('*');
    }
    else {
        top_position = 4 * size + (size - 2);
        for (i = 0; i < top_position; i++)
            my_putchar(' ');
        my_putchar('*');
    }
    return(top_position);
}

int espace_line(int size, int num_line, int mid)
{
    int i = 1;
    int change_espace = mid - num_line;

    for (i = 1; i < change_espace; i++)
        my_putchar(' ');
    return (change_espace);
}

void change_line(int size, int num_branche, int mid)
{
    my_putchar('\n');
    espace_line(size, num_branche, mid);
}
