/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** task02 Day10
*/

int addition(int a, int b);
int multiplication(int a, int b);
int substraction(int a, int b);
int division(int a, int b);
int modulo(int a, int b);
int my_getnbr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int check_errors (int ac, char *av[]);
int chosee_divisor(int nbr);
int my_put_nbr(int nbr);
int my_getnbr(char const *str);
int nbrimpair(char const *chaine);
int chartoint(char str);
int my_compute_power_it(int nb, int p);

int do_op(int ac, char *av[])
{
    if (av[2][0] == '+') {
	if (addition(my_getnbr(av[1]), my_getnbr(av[3])) == 84)
	    return (84);
	my_put_nbr(addition(my_getnbr(av[1]), my_getnbr(av[3])));
	return (0);
    }
    if (av[2][0] == '-') {
	if (substraction(my_getnbr(av[1]), my_getnbr(av[3])) == 84)
            return (84);
        my_put_nbr(substraction(my_getnbr(av[1]), my_getnbr(av[3])));
        return (0);
    }
    if (av[2][0] == '*') {
	if (multiplication(my_getnbr(av[1]), my_getnbr(av[3])) == 84)
            return (84);
        my_put_nbr(multiplication(my_getnbr(av[1]), my_getnbr(av[3])));
        return (0);
    }	
    if (av[2][0] == '/') {
	if (division(my_getnbr(av[1]), my_getnbr(av[3])) == 84)
            return (84);
	if (my_getnbr(av[3]) == 0) {
	    my_putstr("Stop: division by zero");
	    return (84);
	}
	my_put_nbr(division(my_getnbr(av[1]), my_getnbr(av[3])));
        return (0);
    }
    if (av[2][0] == '%') {
	if (modulo(my_getnbr(av[1]), my_getnbr(av[3])) == 84)
            return (84);
	if (my_getnbr(av[3]) == 0) {
            my_putstr("Stop: modulo by zero");
            return (84);
	}
        my_put_nbr(modulo(my_getnbr(av[1]), my_getnbr(av[3])));
        return (0);
    } else {
	if (av[2][0] != '+' && av[2][0] != '-' && av[2][0] != '*' &&
	    av[2][0] != '/' && av[2][0] != '%') {
	    my_putchar (0);
	    return (84);
	}
	return (84);
	
    }
}
int main(int ac, char *av[])
{
    if (check_errors(ac, av) == 84)
	return (84);
    if (do_op(ac, av) == 84)
	return (84);
    return (0);
}
