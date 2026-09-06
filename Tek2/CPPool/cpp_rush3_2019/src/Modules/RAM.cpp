/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RAM
*/

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <fstream>
#include "Modules/RAM.hpp"

RAM::RAM(std::string const &name)
{
    _name = name;
    refreshData();
}

void RAM::refreshData()
{
    this->_data.clear();
    struct sysinfo info;
    sysinfo(&info);
    float total = info.totalram;
    float free = info.freeram;
    float used = (total - free) / total * 100;
    std::string result = "";
    std::system("free | grep 'Mem:' > /tmp/.123456789");

    std::ifstream data ("/tmp/.123456789", std::ifstream::in);
    if (data) {
        char c = data.get();
        while (data.good()) {
            result += c;
            c = data.get();
        }
        data.close();
        used = stoi(result.substr(24, 7)) * 1.0 / stoi(result.substr(12, 7)) * 1.0 * 100.0;
    }

    this->_data.push_back(std::to_string(total));
    this->_data.push_back(std::to_string(used));

}