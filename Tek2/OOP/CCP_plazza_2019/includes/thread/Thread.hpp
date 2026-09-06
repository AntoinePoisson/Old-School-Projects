/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Thread
*/

#ifndef THREAD_HPP
#define THREAD_HPP

#include "thread/IThread.hpp"

namespace Plazza {

    class Thread : public IThread {
        public:
            Thread();
            ~Thread();
            bool joinable() const;
            std::thread::id get_id() const;
            void join();
            void detach();
            void swap(Plazza::Thread t2);

        protected:
            std::thread _stdThread;
        private:
    };

};

#endif /* !THREAD_HPP */
