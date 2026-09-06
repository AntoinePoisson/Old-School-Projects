#include "Parsing/Parsing.hpp"

int main(int ac, char *av[], char *env[])
{
    if (env[0] == NULL)
        return (84);
    try {
        Parsing element(ac, av);
        element.createLink();
        element.launch();
    } catch (Errors const &error) {
        std::cerr << "In " << error.getComponent() << ": " << error.what() << std::endl;
        // printf("Error\n");
        return (84);
    }
    return (0);
}