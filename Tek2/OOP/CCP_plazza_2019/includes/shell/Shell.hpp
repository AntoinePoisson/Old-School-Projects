/* 
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Shell
*/

#ifndef SHELL_HPP
#define SHELL_HPP

#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h> 

#include "Plazza.hpp"
#include "reception/Reception.hpp"
#include "graphics/NCurses.hpp"


namespace Plazza {

    namespace Shell {

        enum CMD_PARAM {
            CMD_TYPE = 0,
            CMD_SIZE = 1,
            CMD_NBR = 2,
        };

        class Shell {
            public:
                Shell(std::string const &prompt, std::shared_ptr<Plazza::IGraphics> graph);
                virtual ~Shell() = default;

                void startShell(std::unique_ptr<Plazza::Reception::Reception> &recep);

            private:
                bool getCommand();
                bool correctSyntaxCommand();
                bool leaveCommand();
                void executeCommand();

                bool checkCommandType(std::string const &param, int i, int *type);
                bool checkCommandSize(std::string const &param);
                bool checkCommandNbr(std::string const &param);

                int getCommandType(std::string const &param);
                int getCommandSize(std::string const &param);
                int getCommandNbr(std::string const &param);

                void leaveReception();

                std::unique_ptr<Plazza::Reception::Reception> reception;
                std::vector<std::string> commandCurrent;
                std::shared_ptr<Plazza::IGraphics> ncurse;
                std::string promptShell;
                bool stopShell;
                u_int16_t counter;
        };
    }

}

#endif /* !SHELL_H */
