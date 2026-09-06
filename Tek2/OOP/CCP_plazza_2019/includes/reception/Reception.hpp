/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Reception
*/

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <memory>
#include <unistd.h>
#include <regex>

#include "Plazza.hpp"
#include "kitchen/Kitchen.hpp"
#include "ipc/QueueMessage.hpp"
#include "graphics/NCurses.hpp"

#define RECEP 1

namespace Plazza {

    typedef struct kitchen_s {
        int index;
        pid_t pid;
        Plazza::IIPC *IPC;
    } kitchen_t;

    typedef struct kitchenInfo_s {
        int index;
        int freeCook;
        int nbrPizza;
        int nbrPreparationPizza;
    } kitchenInfo_t;

    namespace Reception {

        class Reception {
            public:
                Reception(std::shared_ptr<Plazza::IGraphics> graph);
                virtual ~Reception() = default;

                void handleNewCommand(enum Plazza::PizzaType type, enum Plazza::PizzaSize size, uint32_t nbr);
                void handleStatusCommand();
                void clearReception();
                void checker();

            private:
                void destroyAllKitchen();
                bool addNewKitchen();
                void destroyKitchen(int index);
                bool sendOrderToKitchen(enum Plazza::PizzaType type, enum Plazza::PizzaSize size, uint32_t nbr, int indexKitchen);
                void getStatusKitchen(std::vector<std::string> element);                
                void managementMessageKitchen(std::string message, int index);
                void getInfosKitchen();
                void repartitionPizza(int nbrPizza);
                void addOrderFinish(std::vector<std::string> parse);

                std::vector<kitchen_t> listKitchen;
                std::vector<kitchenInfo_t> listKitchenInfo;
                std::vector<kitchenInfo_t> listKitchenStatus;
                std::vector<std::string> listDoneOrder;
                std::shared_ptr<Plazza::IGraphics> ncurse;
                bool getStatus;
                int indexKitchen;
        };

    }

}

#endif /* !RECEPTION_HPP_ */
