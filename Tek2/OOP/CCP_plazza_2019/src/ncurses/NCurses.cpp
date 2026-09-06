/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** NCurses
*/

#include "graphics/NCurses.hpp"

Plazza::NCurses::NCurses(std::string prompt)
    : prompt(prompt)
{
    initscr();   
    noecho();
    cbreak();
    curs_set(0);
    timeout(0);
    keypad(stdscr, 1);
    getmaxyx(stdscr,maxY,maxX);
    halfX = maxX >> 1;
    halfY = maxY >> 1;
    timeStart = std::chrono::system_clock::now();
    isDestroy = false;
    if ((top = newwin(halfY,maxX,0,0)) == nullptr)
        throw Plazza::Throw::Error("Ncurses", "Can't create Windows.\n");
    if ((left = newwin(halfY,halfX,halfY,0)) == nullptr)
        throw Plazza::Throw::Error("Ncurses", "Can't create Windows.\n");
    if ((right = newwin(halfY,halfX,halfY,halfX)) == nullptr)
        throw Plazza::Throw::Error("Ncurses", "Can't create Windows.\n");
    wborder(right, '|', ' ', ' ', ' ', '|', ' ', ' ', ' ');
    indexCmd = -1;
    cas = 0;
    command.clear();
}

void Plazza::NCurses::displayLine(std::string line, bool cmd)
{
    if (isDestroy)
        return;
    if (cmd) {
        listCmd.push_back(line);
        indexCmd = -1;
    } else {
        listOrder.push_back(line);
    }
}

std::string Plazza::NCurses::getInputCommand()
{
    struct timeval timeout = {0, 100};
    fd_set readfds;

    if (isDestroy)
        return (std::string(""));
    if (indexCmd == -1) {
        if (command.size() == 0)
            command = prompt;
        listCmd.push_back(command);
        indexCmd = listCmd.size() - 1;
    }
    for (;;) {
        int key = getch();
        if (key == ERR) {
            listCmd[indexCmd] = command;
            return (std::string("N"));
        }
        if ((key == '\n') || (key == KEY_ENTER) || (key == 4 && command.size() != prompt.size())) {
            if (command == (prompt + "clear")) {
                indexCmd = -1;
                listCmd.clear();
                listOrder.clear();
                command.clear();
                return (std::string("N"));
            }
            if (command.size() == prompt.size()) {
                listCmd[indexCmd] = command;
                indexCmd = -1;
                command.clear();
                return (std::string("N"));
            }
            std::string tmp = command;
            listCmd[indexCmd] = command;
            command.clear();
            indexCmd = -1;
            return (&tmp[prompt.size()]);
        }
        if (key == KEY_BACKSPACE) {
            if (command.size() > prompt.size()) {
                command.pop_back();
                listCmd[indexCmd] = command;
            }
            continue;
        }
        if (key == 4) {
            command.clear();
            listCmd[indexCmd] = command;
            return (std::string(""));
        }
        command += key;
        listCmd[indexCmd] = command;
    }
}

void Plazza::NCurses::refreshWin()
{
    if (isDestroy)
        return;
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - timeStart).count();
    
    if (elapsed_seconds >= 1) {
        cas++;
        timeStart = std::chrono::system_clock::now();
    }
    displayMessage();
    wclear(left);
    wclear(right);
    displayListCmd(listCmd, left);
    displayListOrder(listOrder, right);
    mvwprintw(left, 0, ((halfX / 2) - 6), "--- List of Command: ---");
    mvwprintw(right, 1, ((halfX / 2) - 15), " --- List of Done Order: --- ");
    wborder(right, '|', '|', '*', '*', '/', '\\', '\\', '/');
    wrefresh(right);
    wrefresh(top);
    wrefresh(left);
    napms(250);
}

void Plazza::NCurses::destroy()
{
    if (isDestroy)
        return;
    curs_set(1);
    maxX = 0;
    maxY = 0;
    halfX = 0;
    halfY = 0;
    listCmd.clear();
    listOrder.clear();
    command.clear();
    isDestroy = true;
	delwin(top);
	delwin(left);
	delwin(right);
    endwin();
}

void Plazza::NCurses::displayMessage()
{
    if (isDestroy)
        return;
    if (cas == 0) {
        wclear(top);
        mvwprintw(top, 0, (halfX - 32), "|\\     /|(  ____ \\( \\      (  ____ \\(  ___  )(       )(  ____ \\");
        mvwprintw(top, 1, (halfX - 32), "| )   ( || (    \\/| (      | (    \\/| (   ) || () () || (    \\/");
        mvwprintw(top, 2, (halfX - 32), "| | _ | || (__    | |      | |      | |   | || || || || (__    ");
        mvwprintw(top, 3, (halfX - 32), "| |( )| ||  __)   | |      | |      | |   | || |(_)| ||  __)   ");
        mvwprintw(top, 4, (halfX - 32), "| || || || (      | |      | |      | |   | || |   | || (      ");
        mvwprintw(top, 5, (halfX - 32), "| () () || (____/\\| (____/\\| (____/\\| (___) || )   ( || (____/\\");
        mvwprintw(top, 6, (halfX - 32), "(_______)(_______/(_______/(_______/(_______)|/     \\|(_______/");
    } else if (cas == 1) {
        wclear(top);
        mvwprintw(top, 0, (halfX - 9), "\\__   __/(  ___  )");
        mvwprintw(top, 1, (halfX - 9), "   ) (   | (   ) |");
        mvwprintw(top, 2, (halfX - 9), "   | |   | |   | |");
        mvwprintw(top, 3, (halfX - 9), "   | |   | |   | |");
        mvwprintw(top, 4, (halfX - 9), "   | |   | |   | |");
        mvwprintw(top, 5, (halfX - 9), "   | |   | (___) |");
        mvwprintw(top, 6, (halfX - 9), "   )_(   (_______)");
    } else if (cas == 2) {
        wclear(top);
        mvwprintw(top, 0, (halfX - 13), "\\__   __/|\\     /|(  ____ \\");
        mvwprintw(top, 1, (halfX - 13), "   ) (   | )   ( || (    \\/");
        mvwprintw(top, 2, (halfX - 13), "   | |   | (___) || (__    ");
        mvwprintw(top, 3, (halfX - 13), "   | |   |  ___  ||  __)   ");
        mvwprintw(top, 4, (halfX - 13), "   | |   | (   ) || (      ");
        mvwprintw(top, 5, (halfX - 13), "   | |   | )   ( || (____/\\");
        mvwprintw(top, 6, (halfX - 13), "   )_(   |/     \\|(_______/");
    } else if (cas == 3) {
        wclear(top);
        mvwprintw(top, 0, (halfX - 27), "(  ____ )( \\      (  ___  )/ ___   )/ ___   )(  ___  )");
        mvwprintw(top, 1, (halfX - 27), "| (    )|| (      | (   ) |\\/   )  |\\/   )  || (   ) |");
        mvwprintw(top, 2, (halfX - 27), "| (____)|| |      | (___) |    /   )    /   )| (___) |");
        mvwprintw(top, 3, (halfX - 27), "|  _____)| |      |  ___  |   /   /    /   / |  ___  |");
        mvwprintw(top, 4, (halfX - 27), "| (      | |      | (   ) |  /   /    /   /  | (   ) |");
        mvwprintw(top, 5, (halfX - 27), "| )      | (____/\\| )   ( | /   (_/\\ /   (_/\\| )   ( |");
        mvwprintw(top, 6, (halfX - 27), "|/       (_______/|/     \\|(_______/(_______/|/     \\|");
    } else {
        wclear(top);
        mvwprintw(top, 0, (halfX - 40), "(  ____ )(  ____ \\(  ____ \\\\__   __/(  ___  )|\\     /|(  ____ )(  ___  )( \\    /|\\__   __/");
        mvwprintw(top, 1, (halfX - 40), "| (    )|| (    \\/| (    \\/   ) (   | (   ) || )   ( || (    )|| (   ) ||  \\  ( |   ) (   ");
        mvwprintw(top, 2, (halfX - 40), "| (____)|| (__    | (_____    | |   | (___) || |   | || (____)|| (___) ||   \\ | |   | |   ");
        mvwprintw(top, 3, (halfX - 40), "|     __)|  __)   (_____  )   | |   |  ___  || |   | ||     __)|  ___  || (\\ \\) |   | |   ");
        mvwprintw(top, 4, (halfX - 40), "| (\\ (   | (            ) |   | |   | (   ) || |   | || (\\ (   | (   ) || | \\   |   | |   ");
        mvwprintw(top, 5, (halfX - 40), "| ) \\ \\__| (____/\\/\\____) |   | |   | )   ( || (___) || ) \\ \\__| )   ( || )  \\  |   | |   ");
        mvwprintw(top, 6, (halfX - 40), "|/   \\__/(_______/\\_______)   )_(   |/     \\|(_______)|/   \\__/|/     \\||/    )_)   )_(   "   );
        cas = -1;
    }
}

void Plazza::NCurses::displayListCmd(std::vector<std::string> list, WINDOW *win)
{
    int maxDisplay = halfY;
    int index = 0;

    for (int i = 0; i + 1 <= list.size() && i + maxDisplay - 1 < list.size(); i++) {
        ++index;
    }
    for (int i = 1; index + 1 <= list.size() && i - 1 < halfY; i++, index++) {
        mvwprintw(win, i, 1, list[index].c_str());
    }
}

void Plazza::NCurses::displayListOrder(std::vector<std::string> list, WINDOW *win)
{
    int maxDisplay = halfY - 3;
    int index = 0;

    if (maxDisplay <= 0)
        return;
    for (int i = 0; i + 1 <= list.size() && i + maxDisplay < list.size(); i++) {
        ++index;
    }
    for (int i = 2; index + 1 <= list.size() && i < halfY; i++, index++) {
        mvwprintw(win, i, 1, list[index].c_str());
    }
}