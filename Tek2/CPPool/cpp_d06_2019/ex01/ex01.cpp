/*
** EPITECH PROJECT, 2020
** a
** File description:
** laide
*/

#include <iostream>
#include <iomanip>
#include <string.h>

int main(void)
{
    char buff[50];
    float value = 0.0;
    float result = 0.0;

    std::cin >> value >> buff;
    if (strcmp(buff, "Celsius") == 0) {
        result = ((9.0/5.0) * (value)) + 32;
        std::cout.precision(3);
        std::cout << std::setw(16) << std::fixed << result << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (strcmp(buff, "Fahrenheit")== 0) {
        result = 5.0/9.0 * (value - 32);
        std::cout.precision(3);
        std::cout << std::setw(16) << std::fixed << result << std::setw(16) << "Celsius" << std::endl;
    }
    return (0);
}