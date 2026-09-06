/*
** EPITECH PROJECT, 2020
** ah
** File description:
** laide
*/

#include <iostream>
#include <fstream>

int my_putstr(std::string str)
{
    std::cout << str;
    return (0);
}

int my_puterror(std::string str)
{
    std::cerr << str;
    return (0);
}

int my_cat(std::string file)
{
    std::ifstream data (file, std::ifstream::in);

    if (!data)
        return (my_puterror("my_cat: " + file + ": No such file or directory\n"));
    char c = data.get();
    while (data.good()) {
        std::cout << c;
        c = data.get();
    }
    data.close();
    return (0);
}

int main(int ac, char *av[])
{
    if (ac == 1) {
        return (my_puterror("my_cat: Usage: ./my_cat file [...]\n"));
    }
    for (int i = 1; i != ac; i++)
        my_cat(av[i]);
    return (0);
}