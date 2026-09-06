/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** IThread
*/

#ifndef ITHREAD_HPP
#define ITHREAD_HPP

#include <thread>

class IThread {
    public:
        virtual ~IThread() = default;
        virtual bool joinable() const = 0;
        virtual void join() = 0;
        virtual void detach() = 0;

    protected:
    private:
};

#endif /* !ITHREAD_HPP */
