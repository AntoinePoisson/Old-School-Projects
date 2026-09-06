/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Indie
*/

#ifndef INDIE_HPP_
#define INDIE_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <sys/types.h>
#include <signal.h>
#include <fstream>
#include <memory>
#include <irrlicht.h>
#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "IBase.hpp"
#include "Error.hpp"
#include "ImageError.hpp"
#include "MeshError.hpp"
#include "AudioError.hpp"
#include "Event.hpp"
#include "Audio.hpp"

# define DEFAULT_NBR_BOMB 10
# define DEFAULT_SPEED_PLAYER 2.8f
# define DEFAULT_MAX_BOMB 10
# define MOVE_PER_SECONDS 36

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace indie {

    class Event;

    class Irrlicht {
        public:
            IrrlichtDevice *device;
            IVideoDriver *driver;
	        ISceneManager *smgr;
	        IGUIEnvironment *guienv;
            indie::Event *event;
            float R_RATIO;
            int volume;
            int quality;
            int fps;
    };

    typedef enum direction_e {
        Up,
        Down,
        Right,
        Left,
        Bomber,
        None
    } direction_t;

    extern indie::Irrlicht *irrlicht;
}

#endif /* !INDIE_HPP_ */
