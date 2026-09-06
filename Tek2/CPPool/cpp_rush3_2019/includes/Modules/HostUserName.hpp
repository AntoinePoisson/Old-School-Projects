/*
** EPITECH PROJECT, 2020
** IMonitorModule
** File description:
** IMonitorModule
*/

#ifndef HostUserName_HPP
#define HostUserName_HPP

#include <iostream>
#include <vector>
#include "Modules/Module.hpp"

class HostUserName : public Module {
	public:
        HostUserName(std::string const &name);
        ~HostUserName() = default;

        void refreshData();
};

#endif /* !IMonitorModule_HPP */
