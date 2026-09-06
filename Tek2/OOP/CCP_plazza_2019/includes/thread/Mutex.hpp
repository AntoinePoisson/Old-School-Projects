/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Mutex
*/

#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <mutex>
#include "thread/IMutex.hpp"

namespace Plazza {

    class Mutex : public IMutex {
        public:
            Mutex();
            ~Mutex();
            void lock();
            void unlock();
            bool trylock();
        protected:
        private:
            std::mutex _stdMutex;
    };

};
#endif /* !MUTEX_HPP */
