/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <string>
#include <cctype>
#include <unistd.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Display/SFML/SFML.hpp"
#include "Display/NCurses/NCurses.hpp"
#include "MonitorCore.hpp"
#include "Modules/DateTime.hpp"
#include "Modules/HostUserName.hpp"
#include "Modules/OperatingSysKer.hpp"

int main(int ac, char **av)
{
    IMonitorDisplay *display;
    std::vector<MonitorCore> cores;
    std::string dParam = "";
    int opt = 0;
    int size_height = 1;
    
    while((opt = getopt(ac, av, "d:")) != -1) {
        if (opt == 'd')
            dParam = optarg;
    }

    cores = MonitorCore::setCores();
    for (int i = 0; i < dParam.size(); i++)
        dParam[i] = std::tolower(dParam[i]);
    if (dParam == "sfml") {
        for (int i = 0; i < cores.size(); i++) {
            if (size_height < cores[i].getModules().size())
                size_height = cores[i].getModules().size();
        }
        display = new SFML(cores, cores.size() * 261, size_height * 170 + 20 * size_height, "Kreeeeeeeeeeeeeeorg!!!!!");
    } else if (dParam == "ncurses" || dParam == "ncurse")
         display = new NCurses(cores);
    else 
        display = new NCurses(cores);
    display->launch();
}