/*
** EPITECH PROJECT, 2020
** cpp_rush_2
** File description:
** santa.hpp
*/

#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <iostream>
#include "Display/NCurses/NCurses.hpp"
#include <typeinfo>
#include <vector>
#include <cmath>

NCurses::NCurses(std::vector<MonitorCore> core) : _lengthCore(5), _widthCore(32), x(0), y(0)
{
    this->_core = core;
    _lengthWin = core.size() * this->_lengthCore;
    _widthWin = core.size() * this->_widthCore;
    this->_check.push_back(true);
    this->_check.push_back(true);
    this->_check.push_back(true);
    this->_check.push_back(true);
    this->_check.push_back(true);
    this->_check.push_back(true);
}

int NCurses::getLength() const
{
    return (this->_lengthWin);
}

int NCurses::getWidth() const
{
    return (this->_widthWin);
}

bool NCurses::checkSize()
{
    std::string str = "the terminal is too small";
    std::string str2 = "KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG";

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    if (COLS < this->getWidth() || LINES < this->getLength()) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - str.size() / 2, str.c_str());
        mvprintw(LINES / 2 + 1, (COLS / 2) - str2.size() / 2, str2.c_str());
        use_default_colors();
        return (false);
    }
    use_default_colors();
    return (true);
}

int NCurses::getNbCore() const
{
    return (this->_core.size());
}

void NCurses::addCore(MonitorCore newCore)
{
    this->_core.push_back(newCore);
    this->_lengthWin += _lengthCore;
    this->_widthWin += _widthCore;
}

void NCurses::DeleteCore(MonitorCore core)
{
    (void)core;
}

void NCurses::doDateTime(DateTime *it2)
{
    std::vector<std::string> vect = (*it2).getRefreshData();
    std::string str = vect.front();
    std::string str1 = vect.back();
    int len = strlen(str.c_str());
    int len2 = strlen(str1.c_str());
    WINDOW *win = newwin(6, 32, x, y);
    box(win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 1, (32 - strlen("Date and Time : ")) / 2, "Date and Time : ");
    mvwprintw(win, 3, (32 - len) / 2, str.c_str());
    mvwprintw(win, 4, (32 - len2) / 2, str1.c_str());
    x += 6;
    touchwin(win);
    wrefresh(win);
    delwin(win);
}

void NCurses::doHostUserName(HostUserName *it2)
{
    std::vector<std::string> vect = (*it2).getRefreshData();
    std::string str = vect.front();
    std::string str1 = vect.back();
    int len = strlen(str.c_str());
    int len2 = strlen(str1.c_str());
    WINDOW *win = newwin(6, 32, x, y);

    box(win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 1, (32 - strlen("Hostname and Username : ")) / 2, "Hostname and Username : ");
    use_default_colors();
    mvwprintw(win, 3, (32 - len) / 2, str.c_str());
    mvwprintw(win, 4, (32 - len2) / 2, str1.c_str());
    x += 6;
    touchwin(win);
    wrefresh(win);
    delwin(win);
}

void NCurses::doOperatingSysKer(OperatingSysKer *it2)
{
    std::vector<std::string> vect = (*it2).getRefreshData();
    std::string str = vect[0];
    std::string str1 = vect[1];
    int len = strlen(str.c_str());
    int len2 = strlen(str1.c_str());
    WINDOW *win = newwin(6, 32, x, y);

    box(win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 1, (32 - strlen("Operating system and kernel : ")) / 2, "Operating system and kernel : ");
    mvwprintw(win, 3, (32 - len2) / 2, str1.c_str());
    mvwprintw(win, 4, (32 - len) / 2, str.c_str());
    x += 6;
    touchwin(win);
    wrefresh(win);
    delwin(win);
}

void NCurses::doRAM(RAM *it2)
{
    std::vector<std::string> vect = (*it2).getRefreshData();
    std::string str = vect[0];
    std::string str1 = vect[1];
    std::string mem = "[                            ]";
    int len = strlen(str.c_str());
    int len2 = strlen(str1.c_str());
    WINDOW *win = newwin(7, 32, x, y);

    box(win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 1, (32 - strlen("RAM : ")) / 2, "RAM : ");
    int nbPipe = 28 * atof(str1.c_str()) / 100;
    for (int i = 1; i < nbPipe; i++)
        mem[i] = '|';
    mvwprintw(win, 3, 1, mem.c_str());
    mvwprintw(win, 4, (32 - len2 - 12) / 2, ("used RAM : " + str1 + "%%").c_str());
    mvwprintw(win, 5, (32 - 21) / 2, "size RAM : %.0fG", std::trunc(atof(str.c_str()) / 1000000000.0));
    x += 7;
    touchwin(win);
    wrefresh(win);
    delwin(win);
}

void NCurses::doCPU(CPU *it2)
{
    std::vector<std::string> vect = (*it2).getRefreshData();
    std::string str = vect[0];
    std::string mem = "[                            ]";
    std::string mem2 = "[";
    std::string str1 = vect[2];
    int len = strlen(str.c_str());
    int len1 = strlen(str1.c_str());
    WINDOW *win = newwin(6, 32, x, y);

    mvwprintw(win, 1, (32 - strlen("CPU : ")) / 2, "CPU : ");
    int nbPipe = 28 * atof(str1.c_str()) / 100;
    for (int i = 1; i < nbPipe; i++)
        mem[i] = '|';
    box(win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 3, 2, mem.c_str() + 1);
    mvwprintw(win, 4, (32 - len1) / 2, (atof(str1.c_str()) < 0 ? "0%%" : (str1 + "%%").c_str()));
    x += 6;
    touchwin(win);
    wrefresh(win);
    delwin(win);
}

void NCurses::display()
{
    std::vector<IMonitorModule *> tmp;

    for (std::vector<MonitorCore>::iterator it = this->_core.begin(); it != this->_core.end(); ++it) {
        tmp = (*it).getModules();
        for (std::vector<IMonitorModule *>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2) {
            if (dynamic_cast<DateTime *>(*it2) && this->_check[0])
                this->doDateTime(dynamic_cast<DateTime *>(*it2));
            if (dynamic_cast<HostUserName *>(*it2) && this->_check[1])
                this->doHostUserName(dynamic_cast<HostUserName *>(*it2));
            if (dynamic_cast<OperatingSysKer *>(*it2) && this->_check[2])
                this->doOperatingSysKer(dynamic_cast<OperatingSysKer *>(*it2));
            if (dynamic_cast<RAM *>(*it2) && this->_check[3])
                this->doRAM(dynamic_cast<RAM *>(*it2));
            if (dynamic_cast<CPU *>(*it2) && this->_check[4])
                this->doCPU(dynamic_cast<CPU *>(*it2));
        }
        y += 32;
        x = 0;
    }
}

int NCurses::launch()
{
    int ch;

    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_WHITE, COLOR_BLACK);
    attron(A_BOLD);
    initscr();
    curs_set(false);
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    while (ch != 27) {
        clear();
        if (this->checkSize())
            this->display();
        usleep(100000);
        refresh();
        ch = getch();
        x = 0;
        y = 0;
    }
    endwin();
    return (0);
}
