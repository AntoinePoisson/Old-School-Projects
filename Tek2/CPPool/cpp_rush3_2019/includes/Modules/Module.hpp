/*
** EPITECH PROJECT, 2020
** IMonitorModule
** File description:
** IMonitorModule
*/

#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class Module : public IMonitorModule {
    public:
        Module() = default;
        ~Module() = default;

        virtual void refreshData() = 0;
        std::vector<std::string> const &getData();
        virtual std::vector<std::string> const &getRefreshData();
        void setName(std::string const &name);
        std::string const &getName();

    protected:
        std::vector<std::string> _data;
        std::string _name;
    private:
};

#endif /* !IMonitorModule_HPP */
