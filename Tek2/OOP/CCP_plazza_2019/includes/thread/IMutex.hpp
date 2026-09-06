/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP
#define IMUTEX_HPP

class IMutex {
    public:
        virtual ~IMutex() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual bool trylock() = 0;

    protected:
    private:
};

#endif /* !IMUTEX_HPP */
