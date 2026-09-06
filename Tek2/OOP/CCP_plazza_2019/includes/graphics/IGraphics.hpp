/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include <string>
#include <vector>

namespace Plazza {

    class IGraphics {
        public:
            virtual ~IGraphics() = default;

            virtual void displayLine(std::string line, bool cmd = true) = 0;
            virtual std::string getInputCommand() = 0;
            virtual void refreshWin() = 0;
            virtual void destroy() = 0;
    };

}

#endif /* !IGRAPHICS_HPP_ */