/*
** EPITECH PROJECT, 2020
** Parsing
** File description:
** Parsing
*/

#ifndef PARSING_HPP
#define PARSING_HPP

#include <regex>
#include <string>
#include <list>
#include <map>
#include <csignal>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include "../Components/IComponent.hpp"
#include "../Tools/Errors.hpp"
#include "../Factory/Factory.hpp"
#include "../Components/Output.hpp"


class Parsing {
    public:
        Parsing(int ac, char **av);
        virtual ~Parsing() = default;

        void createLink();

        void launch();

    private:
        std::vector<std::string> list_chipset{"4001", "4008", "4011", "4013", "4030", "4069", "4071", "4081", "clock", "input", "output"};
        std::vector<std::string> arg;
        std::string file_name;
        std::vector<std::unique_ptr<nts::IComponent>> file_instruction;
        std::vector<std::vector<std::string>> file_data;
        std::vector<std::vector<std::string>> list_arg;
    private:
        std::vector<std::vector<std::string>> transform_file(std::string file_name);
        std::vector<std::string> management_commentaire(std::string line, int keyword);
        bool isInclude(std::string element);
        std::string delete_commentaire(std::string line);
        std::vector<std::string> convert_arg(int ac, char **av);
        int check_arg(int ac, std::vector<std::string> arg);
        std::unique_ptr<nts::IComponent> section_chipset(std::vector<std::string> element);
        void check_error_chipset(std::vector<std::string> element);
        void link_component(std::vector<std::string> element);
        void display();
        void simulate();
        // void empty(int signum);
        void loop();
        void dump();
        void changeValue(std::string input);
};

#endif /* !PARSING_HPP */
