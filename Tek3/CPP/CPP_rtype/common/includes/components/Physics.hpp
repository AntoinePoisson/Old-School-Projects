/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Physics
*/

#ifndef COMMONCOMPONENTPHYSICS_HPP_
#define COMMONCOMPONENTPHYSICS_HPP_

#include <ctime>
#include <cstdlib>
#include <math.h>
#include <chrono>

#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        struct Position : public AComponent
        {
            Position(double x, double y) : AComponent(), _x(x), _y(y) {};

            Position(const struct Position &pos) {
                _x = pos._x;
                _y = pos._y;
            };

            double _x;
            double _y;
        };

        struct Destination : public AComponent
        {
            // std::pair<double, double> cur_pos;
            Destination(double x, double y) : AComponent(), _x(x), _y(y) {};
            Destination(const struct Destination &des) {
                _x = des._x;
                _y = des._y;
            }

            double _x;
            double _y;
        };

        struct NextPosition : public AComponent
        {
            NextPosition(double x, double y) : AComponent(), _x(x), _y(y) {};

            double _x;
            double _y;
        };

        //usually applied on player because you use left/right arrow to move
        struct Direction : public AComponent
        {
            Direction(double x, double y) : AComponent(), _x(x), _y(y) {};

            double _x; //-1, 0, 1
            double _y; //-1, 0, 1
        };

        struct StartingTime : public AComponent
        {
            //used for sprite sheed and
            StartingTime(const std::chrono::time_point<std::chrono::system_clock> &startAt) : AComponent(), _startAt(startAt) {};
            StartingTime(const struct StartingTime &stt) {
                _startAt = stt._startAt;
            }

            // std::time_t _startAt;
            // std::time_t _startAt;
            std::chrono::time_point<std::chrono::system_clock> _startAt;
        };

        struct StartCriteria: public AComponent
        {
            /*criteria used for the start of the move*/
            StartCriteria(struct Position init_pos, struct Destination dest_pos)
                : AComponent(), _pos(init_pos)
            {
                _h = sqrt(pow(init_pos._x - dest_pos._x, 2) + pow(init_pos._y - dest_pos._y, 2));
                // _a = abs(dest_pos._x - init_pos._x);
                _a = dest_pos._x - init_pos._x;
                _o = dest_pos._y - init_pos._y;

                _sin = _o / _h;
                _cos = _a / _h;
       
            };

            StartCriteria(const struct StartCriteria &stc): _pos(stc._pos) {
                
                _h = stc._h;
                _o = stc._o;
                _a = stc._a;
                _sin = stc._sin;
                _cos = stc._cos;
            };

            struct Position _pos;
            double _h; //distance between the two points (hypothenuses)
            double _o; //opposite side
            double _a; //adjencent side
            double _sin;
            double _cos;
        };

        struct Speed : public AComponent
        {
            Speed(double speed) : AComponent(), _speed(speed) {};
            Speed(const struct Speed &speed) {
                _speed = speed._speed;
            }

            double _speed;
        };

        //usually used to check collision so each game entity is intended to have this component
        struct Surface : public AComponent
        {
            Surface(int a, int b) : AComponent(), _width(a), _height(b) {};
            Surface(const Surface &surf) {
                _width = surf._width;
                _height = surf._height;
            }

            int _width;
            int _height;
        };

    }
}

#endif /* !COMMONCOMPONENTPHYSICS_HPP_ */
