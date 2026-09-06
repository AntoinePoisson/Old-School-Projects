/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** IConditionVariable
*/

#ifndef ICONDITIONVARIABLE_HPP
#define ICONDITIONVARIABLE_HPP

#include <mutex>

class IConditionVariable {
    public:
        virtual ~IConditionVariable() = default;
        virtual void notify_one() = 0;
        virtual void notify_all() = 0;
        virtual void wait(std::unique_lock<std::mutex> &lock) = 0;
    protected:
    private:
};

#endif /* !ICONDITIONVARIABLE_HPP */
