/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Plazza
*/

#ifndef PLAZZA_HPP
#define PLAZZA_HPP

#include <string>
#include <vector>
#include <iostream>
#include <sys/types.h>
#include <signal.h>
#include <fstream>

namespace Plazza {

    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize{
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    struct pizza_s {
        std::string name;
        int value;
    };

    const std::vector<pizza_s> PizzaType = {
        {"regina", Regina},
        {"margarita", Margarita},
        {"americana", Americana},
        {"fantasia", Fantasia},
        {"", 0},
    };

    const std::vector<pizza_s> PizzaSize = {
        {"s", S},
        {"m", M},
        {"l", L},
        {"xl", XL},
        {"xxl", XXL},
        {"", 0},
    };

    const std::vector<pizza_s> PizzaTime = {
        {"regina", 2},
        {"margarita", 1},
        {"americana", 2},
        {"fantasia", 4},
        {"", 0},
    };

    class Stockage {
        public:
            virtual ~Stockage() = default;
            std::ofstream &getLogFile() { return (logFile); };
            uint32_t getMultiplTimeCook() const { return (multiplTimeCook); };
            uint32_t getNbrCookPerKitchen() const { return (nbrCookPerKitchen); };
            uint32_t getTimeReplaceIngredients() const { return (timeReplaceIngredients); };

            void setMultiplTimeCook(uint32_t value) { if (!isLock) multiplTimeCook = value; };
            void setNbrCookPerKitchen(uint32_t value) { if (!isLock) nbrCookPerKitchen = value; };
            void setTimeReplaceIngredients(uint32_t value) { if (!isLock) timeReplaceIngredients = value; };

            void lockClass() { isLock = true; }
        private:
            std::ofstream logFile;
            uint32_t multiplTimeCook = 0;
            uint32_t nbrCookPerKitchen = 0;
            uint32_t timeReplaceIngredients = 0;
            bool isLock = false;
    };

    extern Plazza::Stockage stockage;

};

#endif /* !PLAZZA_HPP_ */
