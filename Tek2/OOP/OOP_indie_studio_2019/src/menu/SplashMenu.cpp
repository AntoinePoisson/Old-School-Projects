/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** SplashMenu.cpp
*/

#include "SplashMenu.hpp"

void indie::SplashMenu::afterAnim(float width, float height)
{
	if (width >= 1920 && height >= 1080) {
		width = 1920;
		height = 1080;
		if (this->font)
			this->font->draw(L"Press SPACE to continue", core::rect<s32>(810 * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO), 810 * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO), 1200 * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO), 1000 * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO)), video::SColor(255, time % 255, time % 255, time % 255));
		if (indie::irrlicht->event->KeyPressed(KEY_SPACE)) {
			this->isOpen = false;
			indie::Audio::play("./ressources/musics/splash_menu.ogg");
		}
	}
}

void indie::SplashMenu::run()
{
	int coeff = 5;
	float width = 166;
	float height = 466;
	this->logo = get_img("ressources/images/splash_menu.png");
	this->font = indie::irrlicht->device->getGUIEnvironment()->getFont("ressources/assets/fontcourier.bmp");
	this->font->setKerningWidth(5 * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO));

	while (this->isOpen && indie::irrlicht->device->run()) {
		if (indie::irrlicht->event->getEscape())
            this->isOpen = false;
		this->time = indie::irrlicht->device->getTimer()->getTime();
		if (indie::irrlicht->event->KeyPressed(KEY_ESCAPE))
			indie::irrlicht->device->closeDevice();
		indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
		if (indie::irrlicht->device->isWindowActive()) {
			width += coeff + 9;
			height += coeff;
			indie::irrlicht->driver->draw2DImage(this->logo, irr::core::vector2di(0, -80 * indie::irrlicht->R_RATIO), rect<s32>(0, 0, width * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO), height * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO)), 0, SColor(255, 255, 255, 255), true);
			this->afterAnim(width, height);
			indie::irrlicht->guienv->drawAll();
		} else
			indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
	}
}