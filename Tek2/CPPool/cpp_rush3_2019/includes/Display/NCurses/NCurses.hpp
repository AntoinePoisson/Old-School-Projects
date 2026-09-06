/*
** EPITECH PROJECT, 2020
** NCurses
** File description:
** NCurses
*/

#ifndef NCURSES_HPP
#define NCURSES_HPP
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <iostream>
#include <iomanip>
#include "MonitorCore.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Modules/DateTime.hpp"
#include "Modules/HostUserName.hpp"
#include "Modules/OperatingSysKer.hpp"
#include "Modules/RAM.hpp"
#include "Modules/CPU.hpp"
#include "Modules/Module.hpp"

class NCurses : public IMonitorDisplay {
    public:
        NCurses(std::vector<MonitorCore> core);
        ~NCurses() = default;

        void display();
        int launch();
        int getLength() const;
        int getWidth() const;
        bool checkSize();
        int getNbCore() const;
        void addCore(MonitorCore newCore);
        void DeleteCore(MonitorCore newCore);
        void doDateTime(DateTime *it2);
        void doHostUserName(HostUserName *it2);
        void doOperatingSysKer(OperatingSysKer *it2);
        void doRAM(RAM *it2);
        void doCPU(CPU *it2);
        void ChooseModule();
    protected:
        std::vector<MonitorCore> _core;
        int _lengthWin;
        int _widthWin;
        const int _lengthCore;
        const int _widthCore;
        int x;
        int y;
        std::vector<bool> _check;
        int xChoose;
        int yChoose;
};

#endif /* !NCurses */
