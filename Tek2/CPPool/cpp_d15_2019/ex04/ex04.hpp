/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex04
*/

#ifndef ex04_hpp
#define ex04_hpp

#include <iostream>

// template<typename T>

template<typename U>
bool equal(const U &a, const U &b);

template<typename T> class Tester {
    public:
        bool equal(const T &a, const T &b);

    private:
        T value;
};


#endif /* !ex04_hpp */
