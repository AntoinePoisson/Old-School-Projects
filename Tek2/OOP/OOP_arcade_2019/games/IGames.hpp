/*
** EPITECH PROJECT, 2020
** IGames
** File description:
** IGames
*/

#ifndef IGAMES_HPP
#define IGAMES_HPP

#include <iostream>
#include <vector>

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

namespace Arcade {

    enum statusGame {
        INGAME,
        WIN,
        LOSE,
    };

    class IGames {
        public:
            virtual ~IGames() = default;

            virtual std::vector<display_t> &getInitState() = 0;
            virtual std::vector<display_t> &getState() = 0;
            virtual void move(char input) = 0;
            virtual void restart() = 0;
            virtual uint64_t getScore() = 0;
            virtual Arcade::statusGame &getStatus() = 0;
            virtual bool speedGame() = 0;
        protected:
        private:
    };

}

typedef Arcade::IGames *createGame_t(void);

#endif /* !IGAME_HPP */
