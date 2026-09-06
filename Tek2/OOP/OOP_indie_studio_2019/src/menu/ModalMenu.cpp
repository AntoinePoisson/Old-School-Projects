/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** MainMenu.cpp
*/

#include "LoadingSave.hpp"
#include "ModalMenu.hpp"
#include "SelectMenu.hpp"

void indie::ModalMenu::openPlayMenu(void)
{
	indie::Audio::stop("ressources/musics/valid.ogg");
	indie::Audio::play("ressources/musics/valid.ogg");
	std::unique_ptr<indie::SelectMenu> menu = std::make_unique<indie::SelectMenu>();

	menu->run();
}

void indie::ModalMenu::run()
{
	int bomb = 0;
	int previousBomb = 0;
	indie::LoadingMenu *load = new indie::LoadingMenu();

	while (indie::irrlicht->device->run()) {
		if (indie::irrlicht->event->getEscape())
			break;
		indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
		if (indie::irrlicht->device->isWindowActive()) {
			this->image(0, 0, "ressources/images/play_modal.png");
			this->image(1920 / 2 - 609 / 2, 270, "ressources/images/play_modal_button.png");
			this->button(1920 / 2 - 609 / 2 + 17, 270 + 17, this, &indie::ModalMenu::openPlayMenu, "ressources/images/play_modal_button_play.png", "ressources/images/play_modal_button_play_hover.png");
			this->button(1920 / 2 - 609 / 2 + 17, 270 + 213, load, &indie::LoadingMenu::run, "ressources/images/play_modal_button_load.png", "ressources/images/play_modal_button_load_hover.png");
			indie::irrlicht->guienv->drawAll();
		} else
			indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
	}
}