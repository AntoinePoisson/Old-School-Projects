/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** ex01
*/

#ifndef ex_hpp
#define ex_hpp

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return (0);
    return (a > b ? 1 : -1);
}

#endif /* !ex_hpp */
