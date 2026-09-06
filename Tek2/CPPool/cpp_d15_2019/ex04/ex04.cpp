/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "ex04.hpp"

template<typename T>
bool Tester<T>::equal(const T &a, const T &b)
{
    if (a == b)
        return (true);
    return (false);
}

template<typename U>
bool equal(const U &a, const U &b)
{
    if (a == b)
        return (true);
    return (false);
}

template bool equal<int>(int const &a, int const &b);
template bool equal<float>(float const &a, float const &b);
template bool equal<double>(double const &a, double const &b);
template bool equal<std::string>(std::string const &a, std::string const &b);

template bool Tester<int>::equal(int const &a, int const &b);
template bool Tester<float>::equal(float const &a, float const &b);
template bool Tester<double>::equal(double const &a, double const &b);
template bool Tester<std::string>::equal(std::string const &a, std::string const &b);
