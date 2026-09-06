/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** HTPMenu.cpp
*/

#include "HTPMenu.hpp"

void indie::HTPMenu::printBackground()
{
	static int i = 0, j = 0;
	static float transfer_bg = 0;

	transfer_bg += 0.25;
	if (transfer_bg >= 60)
		transfer_bg = 0;
	for (j = -60; j <= 1080 - 60; j += 60) {
		for (i = -60; i <= 1920 - 60; i += 60) {
			this->image(i + transfer_bg, j + transfer_bg, "ressources/images/background_yellowish.png");
		}
	}
	for (i = 0; i <= 1920; i += 90) {
		this->image(i, 90, "ressources/images/grey_grid.png");
	}
}

void indie::HTPMenu::run()
{
    while (this->isOpen && indie::irrlicht->device->run()) {
        if (indie::irrlicht->event->getEscape())
            this->isOpen = false;
		indie::irrlicht->driver->beginScene(true, true, SColor(0,255,255,255));
        if (indie::irrlicht->device->isWindowActive()) {
            this->printBackground();
            this->image(0, 0, "ressources/images/htp_text.png");
            indie::irrlicht->smgr->drawAll();
	    	indie::irrlicht->guienv->drawAll();
        } else
            indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
    }
}