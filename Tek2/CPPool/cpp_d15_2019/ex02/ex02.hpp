/*
** EPITECH PROJECT, 2020
** ex02
** File description:
** ex02
*/

#ifndef ex02_hpp
#define ex02_hpp

#include <iostream>
#include <ostream>

template<typename T>
T min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a == b)
        return (a);
    return (a < b ? a : b);
}


int min(const int &a, const int &b)
{
    std::cout << "non-template min" << std::endl;
    if (a == b)
        return (a);
    return (a < b ? a : b);
}


template<typename U>
U templateMin(U *a, const int b)
{
    int index = 0;
    U minimum;

    if (b == 1)
        return (a[0]);
    for (int i = 1; i < b && b > 0; i++) {
        if (i == 1)
            minimum = min<U>(a[i], a[i - 1]);
        else
            minimum = min<U>(a[i], a[index]);
        if (minimum == a[i])
            index = i;
    }
    return (a[index]);
}


int nonTemplateMin(int *a, const int b)
{
    int minimum = 0;
    int index = 0;

    if (b == 1)
        return (a[0]);
    for (int i = 1; i < b && b > 0; i++) {
        if (i == 1)
            minimum = min(a[i], a[i - 1]);
        else
            minimum = min(a[i], a[index]);
        if (minimum == a[i])
            index = i;
    }
    return (a[index]);
}

#endif /* !ex02_hpp */
