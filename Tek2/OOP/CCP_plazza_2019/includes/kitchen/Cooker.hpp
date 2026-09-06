/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Plazza
*/

#ifndef COOKER_HPP
#define COOKER_HPP

#include <vector>
#include "Plazza.hpp"
#include "thread/SafeQueue.hpp"
#include "thread/IThread.hpp"
#include "kitchen/Order.hpp"
#include "kitchen/pizza/Americana.hpp"
#include "kitchen/pizza/Fantasia.hpp"
#include "kitchen/pizza/Margarita.hpp"
#include "kitchen/pizza/Regina.hpp"

namespace Plazza {

    class Cooker : public IThread {
        private:
            std::thread _stdThread;
            SafeQueue<Plazza::Order> &_order;
            std::deque<Plazza::Order> &_pizzaCooked;
            Plazza::Mutex _mtx;
            bool _stop;

            void cooking();
            void makePizza(Plazza::pizza_s type, Plazza::pizza_s size);

        public:
            Cooker(SafeQueue<Plazza::Order> &order, std::deque<Plazza::Order> &pizzaCooked);
            ~Cooker();
            bool joinable() const;
            void join();
            void detach();
    };
};

#endif /* !COOKER_HPP */