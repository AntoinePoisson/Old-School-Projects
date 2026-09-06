/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Order
*/

#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include "Plazza.hpp"

namespace Plazza {

    class Order {
        public:
            Order(pizza_s type, pizza_s size);
            Order(std::string type, std::string size);
            Order(int type, int size);
            Order() = default;
            ~Order() = default;
            Plazza::pizza_s const &getType();
            Plazza::pizza_s const &getSize();
            int getTime();
        protected:
        private:
            Plazza::pizza_s _type;
            Plazza::pizza_s _size;
            int _time;
    };

};
#endif /* !ORDER_HPP */
