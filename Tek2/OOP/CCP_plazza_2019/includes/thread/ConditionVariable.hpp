/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** ConditionVariable
*/

#ifndef CONDITIONVARIABLE_HPP
#define CONDITIONVARIABLE_HPP

#include <condition_variable>
#include "thread/IConditionVariable.hpp"

namespace Plazza {

    class ConditionVariable : public IConditionVariable {
        public:
            ConditionVariable();
            ~ConditionVariable();
            void notify_one();
            void notify_all();
            void wait(std::unique_lock<std::mutex> &lock);
        protected:
        private:
            std::condition_variable _condVar;
    };

};

#endif /* !CONDITIONVARIABLE_HPP */
