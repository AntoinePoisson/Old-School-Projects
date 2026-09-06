/*
** EPITECH PROJECT, 2020
** find
** File description:
** find
*/

#ifndef FIND_HPP
#define FIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator do_find(T& container, int element)
{
    return (std::find(container.begin(), container.end(), element));
}

#endif /* !FIND_HP */
