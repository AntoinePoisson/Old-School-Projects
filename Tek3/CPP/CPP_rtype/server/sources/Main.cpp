/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-r-type-aurele.auboin
** File description:
** main
*/

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "components/Exception.hpp"
#include "RType.hpp"
#include "Server.hpp"

static int display_flag_h(void);
static std::string check_correct_ip(int argc, char **argv);
static int check_correct_port(int argc, char **argv);
static void r_type_server(std::string ip, int port);

int main(int argc, char **argv, char **env)
{
	if (env == nullptr) {
		std::cerr << "[Error]: No Environement." << std::endl;
		return (Err);
	}
	if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help") || !strcmp(argv[1], "--help"))) {
		return (display_flag_h());
	}
    try {
		for (int inter = 0; inter < 1; inter++) {
        	r_type_server(check_correct_ip(argc, argv), check_correct_port(argc, argv));
		}
    } catch(rtype::component::Exception &exception) {
        std::cerr << exception.what();
        return (exception.getValue());
    } catch(...) {
        std::cerr << "[Exception]: An error has occurred in Server. Please contact the developper team." << std::endl;
        return (Err);
    }
    return (Ok);
}

static int display_flag_h(void)
{
	std::cout << "USAGE: ./r-type_server [ip] [port]" << std::endl;
	std::cout << "This command will execute the server side of the R-Type project." << std::endl;
	std::cout << "The server is able to handle multiple games in a row. With it you could run several games." << std::endl;
	std::cout << "R-Type is an iconic side-scrolling shoot\'em up video game." << std::endl;
	return (0);
}

static std::string check_correct_ip(int argc, char **argv)
{
	std::string ip;

	if (argc >= 2) {
		ip = (std::strcmp(argv[1], "localhost") == 0 ? "127.0.0.1" : argv[1]);
		try {
            boost::asio::ip::address::from_string(ip);
			return (ip);
		} catch(...) {
			std::cerr << "[Warning]: Wrong Ip !" << std::endl;
			ip.clear();
			return (ip);
		}
	}
	return (ip);
}

static int check_correct_port(int argc, char **argv)
{
	if (argc == 3) {
		if (std::strcmp(argv[2], "default") == 0)
			return (4242);
		for (int i = 0; argv[2] && argv[2][i]; i++)
			if (!(argv[2][i] >= '0' && argv[2][i] <= '9'))
				return (-1);
		return (atoi(argv[2]));
	}
	return (-1);
}

static void r_type_server(std::string ip, int port)
{
	std::srand(std::time(nullptr));
	if (ip.size() && port == -1) {
		rtype::OOP::Server server(ip);
		server.run();
	} else if (ip.size() && port != -1) {
		rtype::OOP::Server server(ip, port);
		server.run();
	} else {
		rtype::OOP::Server server;
		server.run();
	}

}
