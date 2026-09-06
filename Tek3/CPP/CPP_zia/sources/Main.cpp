/*
** EPITECH PROJECT, 2020
** Zia
** File description:
** Main
*/

#include <cstring>
#include <ctime>
#include <iostream>
#include <stdlib.h>

#include "abstraction/access.hpp"
#include "Zia.hpp"
#include "exception/AException.hpp"
#include "core/Core.hpp"

static int display_flag_h(void);
static std::string check_config_path(int argc, char **argv);
static void zia_server(std::string configPath);

/**
 * @fn main
 * @param argc nbr arg
 * @param argv value arg
 * @param env env
 * @return int value return of program zia
 */
int main(int argc, char **argv, char **env)
{
	if (env == nullptr) {
		std::cerr << "[Error]: No Environement." << std::endl;
		return (Zia::Err);
	}
	if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help") || !strcmp(argv[1], "--help"))) {
		return (display_flag_h());
	}
    try {
        zia_server(check_config_path(argc, argv));
    } catch(Zia::IException &exception) {
        std::cerr << exception.what();
        return (exception.getValue());
    } catch (const std::exception &err) {
		std::cerr << "[Err]: " << err.what() << std::endl;
        return (Zia::Err);
    } catch(...) {
        std::cerr << "[Exception]: An error has occurred in Server. Please contact the developper team." << std::endl;
        return (Zia::Err);
	}
    return (Zia::Ok);
}

/**
 * @brief dislay help flag
 * @return int value return of program
 */
static int display_flag_h(void)
{
	std::cout << "USAGE: ./zia [pathToConfigFile]" << std::endl;
	std::cout << "\tpathToConfigFile: By default load \"config.json\" at the root of repository." << std::endl;
	std::cout << "PURPOSE:" << std::endl;
	std::cout << "\tThe goal of this program is to create an HTTP server in CPP." << std::endl;
	std::cout << "\tThis server is able to serve typical HTTP documents and page requests." << std::endl;
	return (Zia::Ok);
}

/**
 * @brief check if the config file path exist
 * @param argc nbr arg
 * @param argv  arg value
 * @return std::string config file path
 */
static std::string check_config_path(int argc, char **argv)
{
	if (argc > 2) {
		throw Zia::AException("Argument", "Too many argument, take a look at: ./zia -h");
	} else if (argc == 2) {
		if (access(argv[1], ACCESS_R_OK) == -1) {
			throw Zia::AException("Argument", "Can't open or read the config file: \"" + std::string(argv[1]) + "\"");
		} else if (!std::strstr(argv[1], ".json")) {
			throw Zia::AException("Argument", "Wrong format of config file (must be *.json)");
		}
		return (std::string(argv[1]));
	}
	if (access("./config.json", ACCESS_R_OK) == -1) {
		throw Zia::AException("Argument", "Can't open or read the default config file: \"./config.json\"");
	}
	return (std::string("./config.json"));
}

/**
 * @brief function purpose of launch core of zia
 * @param configPath config file path
 */
static void zia_server(std::string configPath)
{
	std::srand(std::time(nullptr));
	bool reboot = false;
	Zia::Core::isFirstTime() = 1;

	do {
		reboot = false;
		Zia::Core(configPath, &reboot).run();
		if (reboot) {
			Zia::Core::getStatus() = Zia::CoreState_e::Continue;
			Zia::Core::getNbrCurrentClient(0);
			Zia::Core::isFirstTime() = 0;
		}
	} while (reboot);
}
