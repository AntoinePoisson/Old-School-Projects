/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** task2 Day 10
*/

int addition(int a, int b)
{
    if (a + b < 276447232 && a + b > -276447232)
        return (a + b);
    return (84);
}

int substraction(int a, int b)
{
    if (a - b < 276447232 && a - b > -276447232)
        return (a - b);
    return (84);
}

int multiplication(int a, int b)
{
    if (a * b < 276447232 && a * b > -276447232)
        return (a * b);
    return (84);
}

int division(int a, int b)
{
    if (a / b < 276447232 && a / b > -276447232)
	return (a / b);
    return (84);
}

int modulo(int a, int b)
{
    if (a % b < 276447232 && a % b > -276447232)
	return (a % b);
    return (84);
}
