/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av, char **env)
{
    if (!env) {
        std::cerr << "Error: No environnement." << std::endl;    
        return (84);
    }
    if (ac == 2) {
        try {
            Arcade::Core core(av[1]);
            return (core.launchCore());
        } catch(Error const & error) {
            if (error.getComponent() != "")
                std::cerr << "In " << error.getComponent() << ": " << error.what() << std::endl;
            else if (error.what() && error.what() != nullptr)
                std::cerr << error.what() << std::endl;
            return (error.getValue());
        } catch(...) {
            std::cerr << "Error Arcade" << std::endl;
            return (84);
        }
    } else {
        std::cerr << "Invalide Parameter: ./arcade lib_arcade_$libraryname.so" << std::endl;
        std::cerr << "Try './arcade -h' for more information." << std::endl;
        return (84);
    }
}