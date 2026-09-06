/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Main
*/

#include <regex>

#include "Plazza.hpp"
#include "shell/Shell.hpp"
#include "throw/Error.hpp"
#include "graphics/NCurses.hpp"
#include "Main.hpp"

int main(int ac, char *av[], char *env[])
{
    if (!env) {
        std::cerr << "Error: No environnement." << std::endl;
        return (84);
    }
    if (ac == 4 && std::regex_match(std::string(av[1]), std::regex("\\d+")) &&
        std::regex_match(std::string(av[2]), std::regex("\\d+")) &&
        std::regex_match(std::string(av[3]), std::regex("\\d+")) &&
        atoi(av[2]) != 0) {
        try {
            const std::string pompt = "You -> ";
            Plazza::stockage.setMultiplTimeCook(atoi(av[1]));
            Plazza::stockage.setNbrCookPerKitchen(atoi(av[2]));
            Plazza::stockage.setTimeReplaceIngredients(atoi(av[3]));
            Plazza::stockage.getLogFile().open(".log");
            Plazza::stockage.lockClass();
            if (Plazza::stockage.getLogFile().is_open() == false) {
                std::cerr << "Can't open log File" << std::endl;
                return (84);
            }
            std::shared_ptr<Plazza::IGraphics> grah = std::make_shared<Plazza::NCurses>(pompt);
            Plazza::Shell::Shell plazza(pompt, grah);
            auto uniqPtr = std::make_unique<Plazza::Reception::Reception>(grah);
            plazza.startShell(uniqPtr);
        } catch(Plazza::Throw::Error const & error) {
            if (error.getComponent() != "")
                std::cerr << "In " << error.getComponent() << ": " << error.what() << std::endl;
            else if (error.what() && error.what() != nullptr)
                std::cerr << error.what() << std::endl;
            return (error.getValue());
        } catch(...) {
            std::cerr << "Error Plazza" << std::endl;
            return (84);
        }
    } else {
        std::cerr << "How to use: './plazza cooking_time nbr_cook time_replace_food'" << std::endl;
        return (84);
    }
    return (0);
}