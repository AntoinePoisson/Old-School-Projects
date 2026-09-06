/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include "SelectMenu.hpp"
#include "ModalMenu.hpp"

void indie::MainMenu::openSettings(void)
{
	indie::Audio::stop("ressources/musics/valid.ogg");
	indie::Audio::play("ressources/musics/valid.ogg");
	std::unique_ptr<indie::SettingsMenu> menuSettings = std::make_unique<indie::SettingsMenu>();

	menuSettings->run();
}

void indie::MainMenu::openPlayMenu(void)
{
	indie::Audio::stop("ressources/musics/valid.ogg");
	indie::Audio::play("ressources/musics/valid.ogg");
	std::unique_ptr<indie::ModalMenu> menu = std::make_unique<indie::ModalMenu>();

	menu->run();
}

void indie::MainMenu::openHTP(void)
{
	indie::Audio::stop("ressources/musics/valid.ogg");
	indie::Audio::play("ressources/musics/valid.ogg");
	std::unique_ptr<indie::HTPMenu> menu = std::make_unique<indie::HTPMenu>();

	menu->run();
}

void indie::MainMenu::exitGame(void)
{
	indie::irrlicht->device->closeDevice();
}

void indie::MainMenu::printBackground()
{
	static int i = 0, j = 0;
	static float transfer_bg = 0;

	transfer_bg += 0.25;
	if (transfer_bg >= 60)
		transfer_bg = 0;
	for (j = -60; j <= 1080 - 60; j += 60) {
		for (i = -60; i <= 1920 - 60; i += 60)
			this->image(i + transfer_bg, j + transfer_bg, "ressources/images/background_blueish.png");
	}
	for (i = 0; i <= 1920; i += 90)
		this->image(i, 90, "ressources/images/grey_grid.png");
}

void indie::MainMenu::run()
{
	irr::core::dimension2du size = get_img("ressources/images/main_menu_play.png")->getSize();
	irr::core::vector2di cursor;
	int bomb = 0;
	int previousBomb = 0;
	indie::Audio::play("ressources/musics/main_music.wav");
	indie::Audio::setloop("ressources/musics/main_music.wav", true);

	while (indie::irrlicht->device->run()) {
		if (indie::irrlicht->event->getEscape())
			indie::irrlicht->device->closeDevice();
		indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
		if (indie::irrlicht->device->isWindowActive()) {
			this->printBackground();
			this->image(50, 90, "ressources/images/main_menu.png");

			cursor = indie::irrlicht->device->getCursorControl()->getPosition();
			this->button(1920 - 865, 270, this, &indie::MainMenu::openPlayMenu, "ressources/images/main_menu_play.png", "ressources/images/main_menu_play_hover.png");
			if ((cursor.X > (1920 - 865) * indie::irrlicht->R_RATIO && cursor.X < (1920 - 865) * indie::irrlicht->R_RATIO + size.Width * indie::irrlicht->R_RATIO) && (cursor.Y > 270 * indie::irrlicht->R_RATIO && cursor.Y < 270 * indie::irrlicht->R_RATIO + size.Height * indie::irrlicht->R_RATIO))
				bomb = 0;
			this->button(1920 - 865, 430, this, &indie::MainMenu::openSettings, "ressources/images/main_menu_settings.png", "ressources/images/main_menu_settings_hover.png");
			if ((cursor.X > (1920 - 865) * indie::irrlicht->R_RATIO && cursor.X < (1920 - 865) * indie::irrlicht->R_RATIO + size.Width * indie::irrlicht->R_RATIO) && (cursor.Y > 430 * indie::irrlicht->R_RATIO && cursor.Y < 430 * indie::irrlicht->R_RATIO + size.Height * indie::irrlicht->R_RATIO))
				bomb = 1;
			this->button(1920 - 865, 590, this, &indie::MainMenu::openHTP, "ressources/images/main_menu_htp.png", "ressources/images/main_menu_htp_hover.png");
			if ((cursor.X > (1920 - 865) * indie::irrlicht->R_RATIO && cursor.X < (1920 - 865) * indie::irrlicht->R_RATIO + size.Width * indie::irrlicht->R_RATIO) && (cursor.Y > 590 * indie::irrlicht->R_RATIO && cursor.Y < 590 * indie::irrlicht->R_RATIO + size.Height * indie::irrlicht->R_RATIO))
				bomb = 2;
			this->button(1920 - 865, 750, this, &indie::MainMenu::exitGame, "ressources/images/main_menu_leave.png", "ressources/images/main_menu_leave_hover.png");
			if ((cursor.X > (1920 - 865) * indie::irrlicht->R_RATIO && cursor.X < (1920 - 865) * indie::irrlicht->R_RATIO + size.Width * indie::irrlicht->R_RATIO) && (cursor.Y > 750 * indie::irrlicht->R_RATIO && cursor.Y < 750 * indie::irrlicht->R_RATIO + size.Height * indie::irrlicht->R_RATIO))
				bomb = 3;
			if (previousBomb != bomb) {
				previousBomb = bomb;
				indie::Audio::stop("./ressources/musics/hover.ogg");
				indie::Audio::play("./ressources/musics/hover.ogg");
			}
			if (bomb == 0)
				this->image(0, 380, "ressources/images/main_menu_bomb_1.png");
			else if (bomb == 1)
				this->image(0, 380, "ressources/images/main_menu_bomb_2.png");
			else if (bomb == 2)
				this->image(0, 380, "ressources/images/main_menu_bomb_3.png");
			else
				this->image(0, 380, "ressources/images/main_menu_bomb_4.png");
			indie::irrlicht->guienv->drawAll();
		}
		indie::irrlicht->driver->endScene();
	}
}