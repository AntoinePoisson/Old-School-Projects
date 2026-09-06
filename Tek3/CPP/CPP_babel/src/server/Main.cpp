/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** main
*/

#include "Babel.hpp"
#include "Server.hpp"
#include "AException.hpp"

static int correct_argument(int ac, char **av, char **env);
static void babel_server(std::string ip, int port);

int main(int ac, char *av[], char *env[])
{
    if (correct_argument(ac, av, env) == Err)
        return (Err);
    try {
        babel_server(strcmp(av[1], "localhost") ? av[1] : "127.0.0.1", atoi(av[2]));
    } catch(babel::AException &exception) {
        exception.print();
        return (exception.getValue());
    } catch(...) {
        std::cerr << "[Exception]: An error has occurred in Server. Please contact the develop team." << std::endl;
        return (Err);
    }
    return (Ok);
}

static int correct_argument(int ac, char **av, char **env)
{
    if (env == NULL) {
        std::cerr << "[Error]: No environnement." << std::endl;
        return (Err);
    }
    if (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "-help") || !strcmp(av[1], "--help"))) {
        std::cout << "It's Babel Server, how to execute:" << std::endl << "$ ./babel_server ip port" << std::endl;
        return (Err);
    }
    if (ac != 3) {
        std::cerr << "Invalid Parameter or nbr paramter. Take look at --help." << std::endl;
        return (Err);
    }
    for (int i = 0; av[2] && av[2][i]; i++)
        if (!(av[2][i] >= '0' && av[2][i] <= '9') || atoi(av[2]) == 0) {
            std::cerr << "[Argument]: Invalid Port." << std::endl;
            return (Err);
        }
    try {
        if (av[1] && strcmp(av[1], "localhost") != 0)
            boost::asio::ip::address::from_string(av[1]);
    } catch(...) {
        std::cerr << "[Argument]:Invalid Ip." << std::endl;
        return (Err);
    }
    return (Ok);
}

static void babel_server(std::string ip, int port)
{
    std::unique_ptr<babel::Server> server = std::make_unique<babel::Server>(ip, port);

    server->run();
}
