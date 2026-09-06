/*
** EPITECH PROJECT, 2020
** Parsing
** File description:
** Parsing
*/

#include <csignal>
#include "Parsing.hpp"

int Parsing::check_arg(int ac, std::vector<std::string> arg)
{
    int index_file = -1;

    if (ac == 0)
        throw Errors("No Argument.", "Parse");
    for (int i = 0; i < ac; i++) {
        if (!std::regex_search(arg[i], std::regex("\\S+\\=(0|1)"))) {
            if (index_file != -1)
                throw Errors("No Files in Argument.", "Parse");
            index_file = i;
        }
    }    
    return (index_file);
}

std::vector<std::string> Parsing::convert_arg(int ac, char **av)
{
    std::vector<std::string> result;

    for (int i = 1; i < ac; i++)
        result.push_back(av[i]);
    return (result);
}

std::string Parsing::delete_commentaire(std::string line)
{
    std::string result = "";

    for (int i = 0; line[i]; i++) {
        if (line[i] == '#')
            return (result);
        result += line[i];
    }
    return (result);
}

bool Parsing::isInclude(std::string element)
{
    for (int i = 0; i < list_chipset.size(); i++)
        if (list_chipset[i] == element)
            return (true);
    return (false);
}

std::vector<std::string> Parsing::management_commentaire(std::string line, int keyword)
{
    std::vector<std::string> result;
    std::stringstream ssin(line);
    std::string tmp;
    static int num_line = 0;
    int count = 0;
  
    while (ssin >> tmp) {
        if (tmp == ".chipsets:") {
            if (keyword != 0)
            throw Errors("Problem with .chipsets in File.", "Parse");
        } else if (tmp == ".links:") {
            if (keyword != 1)
            throw Errors("Problem with .link in File.", "Parse");
        } else if (num_line == 0) {
            throw Errors("First Line is not .chipsets .link in File.", "Parse");
        }
        if (keyword == 1 && tmp != ".links:" && count == 0 && isInclude(tmp) == false)
            throw Errors("Problem with .link in File.", "Parse");
        result.push_back(tmp); 
        count++;
    } 
    if (count > 2)
        throw Errors("Invalid Instruction Parameter", "Parse");        
    num_line += 1;
    return (result);
}

std::vector<std::vector<std::string>> Parsing::transform_file(std::string file_name)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> tmp;
    std::ifstream data (file_name, std::ifstream::in);
    std::string file = "";
    char element = 0;
    int keyword = 0;

    if (!data)
        throw Errors("Error with File.", "Parse");        
    while (data.good()) {
        element = data.get();
        if (element == '\n' || element == '\0' || element == EOF ) {
            file = delete_commentaire(file);
            if (!std::regex_match (file, std::regex("\\s+")) && file != "") {
                tmp = management_commentaire(file, keyword);
                if (tmp[0] == ".chipsets:")
                    keyword++;
                if (tmp[0] == ".links:")
                    keyword++;
                result.push_back(tmp);
            }
            file = "";
        } else {
            file += element;
        }
    }
    data.close();
    if (keyword != 2)
        throw Errors("Problem with .link && .chipsets in File.", "Parse");        
    return (result);
}

Parsing::Parsing(int ac, char **av)
: arg(convert_arg(ac, av))
{
    int index = check_arg(--ac, arg);
    
    file_data = transform_file(arg[index]);
    file_name = arg[index];
    for (int i = 0; i < ac; i++) {
        std::string element = "";
        std::vector<std::string> result;
        if (i != index) {
            for (int s_string = 0; s_string < arg[i].length(); s_string++) {
                if (arg[i][s_string] == '=') {
                    result.push_back(element);
                    element = "";
                } else
                    element += arg[i].at(s_string);
            }
            result.push_back(element);
            list_arg.push_back(result);
        }
    }
}

void Parsing::check_error_chipset(std::vector<std::string> element)
{
    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++)
        if (it[0]->getName() == element[1])
            throw Errors("Same Name In File.", "Parse");
}

std::unique_ptr<nts::IComponent> Parsing::section_chipset(std::vector<std::string> element)
{
    bool find = false;
    std::string value = "0";

    check_error_chipset(element);
    if (element[0] == "input" || element[0] == "clock") {
        for (auto it = list_arg.begin(); it != list_arg.end() && list_arg.size(); it++) {
            if (it[0][0] == element[1]) {
                value = it[0][1];
                it[0][0] = "";
                find = true;
            }
        }
        if (!find)
            throw Errors("No initilization.", "Parse");
    }
    std::unique_ptr<nts::IComponent> tmp = Factory::createComponent(element[0], element[1]);
    tmp->setValue(value == "1" ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    return (tmp);
}

std::vector<std::string> rework_element(std::string param)
{
    std::string element = "";
    std::vector<std::string> result;

    if (!std::regex_search(param, std::regex("\\S+\\:\\d+")))
        throw Errors("Wrong Format in section .link", "Parse");
    for (int s_string = 0; s_string < param.length(); s_string++) {
        if (param[s_string] == ':') {
            result.push_back(element);
            element = "";
        } else
            element += param[s_string];
    }
    result.push_back(element);
    return (result);
}

void Parsing::link_component(std::vector<std::string> element)
{
    std::vector<std::string> first_part = rework_element(element[0]);
    std::vector<std::string> second_part = rework_element(element[1]);
    int index_first = -1;
    int index_second = -1;
    int count = 0;
    int output = 0;

    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++, count++) {
        if (it[0]->getName() == first_part[0]) {
            if (dynamic_cast<Output*> (it[0].get()) != nullptr) {
                if (output)
                    throw Errors("Try link two ouput", "Parse");
                output = 1;
            }
            index_first = count;
        }
        if (it[0]->getName() == second_part[0]) {
            if (dynamic_cast<Output*> (it[0].get()) != nullptr) {
                if (output)
                    throw Errors("Try link two ouput", "Parse");
                output = 1;
            }
            index_second = count;
        }
    }
    if (index_first == -1 || index_second == -1)
        throw Errors("Unknown link element", "Parse");
    file_instruction[index_first]->setLink(std::stoi(first_part[1]), (*file_instruction[index_second].get()), std::stoi(second_part[1]));
    file_instruction[index_second]->setLink(std::stoi(second_part[1]), (*file_instruction[index_first].get()), std::stoi(first_part[1]));
}

bool check_size(std::vector<std::vector<std::string>> list_arg)
{

    for (auto it = list_arg.begin(); it != list_arg.end() && list_arg.size(); it++) {
        if (it[0][0] != "")
            return (true);
    }
    return (false);
}

void Parsing::createLink()
{
    int output = 0;
    int input = 0;
    bool link_section = false;

    if (file_data.size() == 0)
        return;
    for (auto it = file_data.begin() + 1; it != file_data.end(); it++) {
        if (it[0][0] == ".links:") {
            link_section = true;
            if (check_size(list_arg))
                throw Errors("Too many Argument.", "Parse");
        } else if (!link_section) {
            file_instruction.push_back(section_chipset(it[0]));
        } else {
            link_component(it[0]);
        }
    }
    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++) {
        if (dynamic_cast<Output*> (it[0].get()) != nullptr) {
            if (!it[0]->isLink())
                throw Errors("Output not link", "Parse");
            output++;
        }
        if (dynamic_cast<Input*> (it[0].get()) != nullptr)
            input++;
    }
    if (input == 0 || output == 0)
        throw Errors("No Input or Output", "Parse");
}


void Parsing::display()
{
    std::map<std::string, nts::Tristate> sort;

    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++)
        if (dynamic_cast<Output*> (it[0].get()) != nullptr)
            sort.insert(std::pair<std::string, nts::Tristate>(it[0]->getName(), it[0]->getValue()));
    for (std::map<std::string, nts::Tristate>::iterator it = sort.begin(); it != sort.end(); it++) {
        std::cout << it->first << "=";
        if (it->second == nts::Tristate::TRUE)
            std::cout << "1" << '\n';
        if (it->second == nts::Tristate::FALSE)
            std::cout << "0" << '\n';
        if (it->second == nts::Tristate::UNDEFINED)
            std::cout << "U" << '\n';
    }
}

void Parsing::dump()
{
    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++) {
        it[0]->dump();
    }
}

static bool whilee = false;

void empty(int signum)
{
	(void)signum;
    whilee = false;
}

void Parsing::loop()
{
    std::string get = "";

    whilee = true;
    signal(SIGINT, empty);
    while (whilee)
        simulate();
}

void Parsing::simulate()
{
    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++)
        if (dynamic_cast<Output*> (it[0].get()) != nullptr)
            it[0]->compute(1);
}

void Parsing::changeValue(std::string input) // check bien chge value avant
{
    std::string name = "";
    std::string value = "";
    int left = 1;
    int count = 1;

    for (int i = 0; input[i]; i++) {
        if (input[i] == '=') {
            left = -1;
        } else if (left == 1) {
            name += input[i];
        } else {
            value += input[i];
        }
    }
    for (auto it = file_instruction.begin(); it != file_instruction.end(); it++, count++) {
        if (it[0]->getName() == name) {
            left = count;
            it[0]->setValue(value == "1" ? nts::Tristate::TRUE : nts::Tristate::FALSE);
            /////////////////////////
        }
    }
    if (left == -1)
        printf("Unkwon Commande.\n");
}

// parse les espaces

std::string padding_string_rework(std::string element)
{
    std::string result("");
    std::stringstream ssin(element);
    int count = 0;

    while (ssin >> result)
        count++;
    if (count != 1)
        return ("");
    return (result);
}

void Parsing::launch()
{
    std::string get = "";
    if (file_instruction.size() == 0)
        return;
    simulate();
    display();
    printf("> ");    
    while (std::getline(std::cin, get)) {
        get = padding_string_rework(get);
        if (get == "display") {
            display();
        } else if (get == "simulate") {
            simulate();
        } else if (get == "loop") {
            loop();
        } else if (get == "dump") {
            dump();
        } else if (std::regex_search(get, std::regex("\\S+\\=(0|1)"))) {
            changeValue(get);
        } else if (get == "exit") {
            return;
        } else {
            printf("Unkwon Commande.\n");
        }
        printf("> ");
    }
}