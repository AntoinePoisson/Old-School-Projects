/*
** EPITECH PROJECT, 2020
** ex03
** File description:
** ex03
*/

#ifndef ex03_hpp
#define ex03_hpp

#include <iostream>

template<typename T>
void foreach(const T *tab, void func(const T & elem), int size)
{
    for (int i = 0; tab && i < size && size >= 0; i++) {
        func(tab[i]);
    }
}

template<typename T>
void print(const T &a)
{
    std::cout << a << "\n";
}

#endif /* !ex03_hpp */
