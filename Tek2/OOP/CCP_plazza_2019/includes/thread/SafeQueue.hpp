/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE
#define SAFEQUEUE

#include <deque>
#include "thread/Mutex.hpp"

namespace Plazza {

    template <class T>
    class SafeQueue {
        public:
            ~SafeQueue() = default;
            bool tryPop(T &var);
            void push(T var);
            int size();
        protected:
        private:
            std::deque<T> _queue;
            Plazza::Mutex _mtx;
    };

};

#endif /* !SAFEQUEUE */
