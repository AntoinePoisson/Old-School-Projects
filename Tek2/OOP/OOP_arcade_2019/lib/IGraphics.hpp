/*
** EPITECH PROJECT, 2020
** IGraphics
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_H
#define IGRAPHICS_H

#include <iostream>

#ifndef DISPLAY_T
#define DISPLAY_T

typedef struct display_s {
    std::string ascii;
    std::string foreground;
    std::string background;
    std::string image;
    float x;
    float y;
    bool isPrint;
} display_t;

#endif

namespace Arcade
{
    class IGraphics {
        public:
            virtual ~IGraphics() = default;

            virtual char getEvent(void) = 0;
            virtual void print(display_t &display) = 0;
            virtual void destructor() = 0;
            virtual void refresh() = 0;

            virtual int getWindowHeight() = 0;
            virtual int getWindowWidth() = 0;
            virtual bool clockDisplay() = 0;
    };
}

typedef Arcade::IGraphics *createLib_t(void);

#endif /* !IGRAPHICS_H */
