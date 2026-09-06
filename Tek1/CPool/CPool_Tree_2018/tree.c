/*
** EPITECH PROJECT, 2018
** tree
** File description:
** Write a function that displays a fir tree, based on its given size.
*/

void print_star_line(int nbr);

int first_line(int size);

int espace_line(int size, int num_line, int mid);

void change_line(int size, int num_branche, int mid);

void print_tree(int size, int mid_top, int mid)
{
    int nbr = 1;
    int num_line = 1;
    int num_branche = 1;
    int a = 4;
    int limitation_size = 1;
    int i = 1;

    while (num_line <= size * 2 + 1) {
        if (limitation_size != a) {
             print_star_line(nbr);
             my_putchar('\n');
             if (limitation_size != a - 1 || num_line == size * 2)
                 espace_line(size, num_branche, mid);
            nbr = nbr + 2;
            num_branche++;
            num_line++;
            limitation_size++;
        }
        else {
            num_branche = num_branche - 2;
            num_line = num_line - 4;
            nbr = nbr - 2;
            a = a + 1;
            limitation_size = 0;
            espace_line(size, num_line + i, mid_top);
            print_star_line(nbr- 2);
            i = i + 3;
            espace_line(size, num_line, mid_top);
            change_line(size, num_branche, mid_top);
            num_branche = num_branche + 1;
        }
    }
}

void tronc(int size, int top_position)
{
    int i = 0;
    int a = 0;

    while (a < size) {
        if (size % 2 != 0) {
            for (i = 0; i < top_position - (size/2); i++)
                my_putchar(' ');
            i = 0;
            for (i = 0; i < size; i++)
                my_putchar('|');
            my_putchar('\n');
            a = a + 1;
        }
        else {
            for (i = 0; i < top_position - (size/2); i++)
                my_putchar(' ');
            i = 0;
            for (i = -1; i < size; i++)
                my_putchar('|');
            my_putchar('\n');
            a = a + 1;
        }
    }
}

void tree(int size)
{
    int mid_line = 0;

    if (size > 0) {
        mid_line = first_line(size);
        change_line(size, 0, mid_line);
        print_tree(size, mid_line, mid_line);
        tronc(size, mid_line);
    }
}
