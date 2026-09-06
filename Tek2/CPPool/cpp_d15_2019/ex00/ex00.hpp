/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** ex00
*/

#ifndef ex00_hpp
#define ex00_hpp

template<typename T>
void swap(T &a, T &b)
{
    T save = a;
    a = b;
    b = save;
}

template<typename T>
const T &min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template<typename T>
const T &max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

template<typename T>
T add(const T &a, const T &b)
{
    return (a + b);
}


#endif /* !ex00 */
