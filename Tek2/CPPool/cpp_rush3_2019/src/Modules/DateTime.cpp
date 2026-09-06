/*
** EPITECH PROJECT, 2020
** DateTime
** File description:
** DateTime
*/

#include <sys/utsname.h>
#include <chrono>
#include "Modules/DateTime.hpp"

DateTime::DateTime(std::string const &name)
{
    _name = name;
}

std::vector<std::string> DateTime::getTimeDate() const
{
    time_t now = time(0);

    std::string result = ctime(&now);
    std::vector<std::string> toto = {result.substr(0, 11) + result.substr(20, 4), result.substr(11, 8)};
    return (toto);
}

void DateTime::refreshData()
{
    std::vector<std::string> result = getTimeDate();

    _data.clear();
    _data.push_back(result[0]);
    _data.push_back(result[1]);
}