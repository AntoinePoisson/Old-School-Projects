/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPU
*/

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include "Modules/CPU.hpp"

CPU::CPU(std::string const &name)
{
    _name = name;
    _data.push_back("0");
    _data.push_back("0");
    _data.push_back("0");
}

void CPU::getPercent(std::stringstream &ss)
{
    std::string word;
    std::vector<int> dataProc;

    while (ss >> word) {
        dataProc.push_back(std::stoi(word));
    }
    
    int size = dataProc.size();
    int total = 0;
    int work = 0;
    for (int i = 0; i < size ;i++) {
        if (i < 3)
            work += dataProc[i];
        total += dataProc[i];
    }
    if (std::stoi(_data[0]) != 0) {
        int workF = work - std::stoi(_data[0]);
        int totalF = total - std::stoi(_data[1]);
        int res = ((double)workF / (double)totalF) * 100;
        _data[2] = std::to_string(res);
    }
    _data[0] = std::to_string(work);
    _data[1] = std::to_string(total);
}

void CPU::refreshData()
{
    std::ifstream file("/proc/stat");
    std::stringstream ss;
    std::string line;
    std::string word;

    if (file.is_open()) {
        while(std::getline(file, line)) {
            ss << line;
            ss >> word;
            if (word == _name) {
                getPercent(ss);
                return ;
            }
        }
    }
}
