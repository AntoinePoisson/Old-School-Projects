/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OperatingSysKer
*/

#include <sys/utsname.h>
#include "Modules/OperatingSysKer.hpp"

OperatingSysKer::OperatingSysKer(std::string const &name)
{
    _name = name;
    refreshData();
}

void OperatingSysKer::refreshData()
{
    struct utsname sysinfo;
    std::string str;
    std::string str2;
    uname(&sysinfo);
    _data.clear();
    str = (sysinfo.release);
    _data.push_back(str);
    str2 = sysinfo.sysname;
    _data.push_back(str2);
}