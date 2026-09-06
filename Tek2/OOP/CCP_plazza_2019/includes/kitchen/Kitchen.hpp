/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <memory>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include <regex>
#include <deque>

#include "Plazza.hpp"
#include "ipc/QueueMessage.hpp"
#include "thread/SafeQueue.hpp"
#include "kitchen/Cooker.hpp"
#include "kitchen/Order.hpp"
#include "kitchen/Pizza.hpp"

#define TIMEOUT 5

namespace Plazza {

    class Kitchen {
        public:
            Kitchen(std::unique_ptr<Plazza::IIPC> &newIPC);
            virtual ~Kitchen() = default;

            static void destroyKitchen(int useless);
            void loop();
        private:
            bool checkTimeOutActivity();
            void handleReceiveNewMessage(std::string message);
            void addOrder(std::string type, std::string size);
            void addCook();
            void sendPizza();

            std::unique_ptr<Plazza::IIPC> &IPC;
            std::chrono::time_point<std::chrono::system_clock> timeStart;
            uint32_t freeCook;
            uint32_t busyCook;
            uint32_t nbrPizza;
            uint16_t timeOut;
            SafeQueue<Plazza::Order> _orderQueue;
            std::deque<Plazza::Order> _pizzaCooked;
            std::vector<Plazza::Cooker *> _cooks;
    };

};

#endif /* !KITCHEN_HPP */
