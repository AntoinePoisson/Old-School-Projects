/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** SelectMenu.cpp
*/

#include "SelectMenu.hpp"

void indie::SelectMenu::printBackground()
{
	static int i = 0, j = 0;
	static float transfer_bg = 0;

	transfer_bg += 0.25;
	if (transfer_bg >= 60)
		transfer_bg = 0;
	for (j = -60; j <= 1080 - 60; j += 60) {
		for (i = -60; i <= 1920 - 60; i += 60)
			this->image(i + transfer_bg, j + transfer_bg, "ressources/images/background_yellowish.png");
	}
	for (i = 0; i <= 1920; i += 90)
		this->image(i, 90, "ressources/images/grey_grid.png");
}

void indie::SelectMenu::play()
{
	indie::Audio::stop("ressources/musics/valid.ogg");
	indie::Audio::play("ressources/musics/valid.ogg");
	std::unique_ptr<indie::Game> game = std::make_unique<indie::Game>();
	std::vector<std::vector<int>> coordinates = {{1 * 30, 1 * 30}, {1 * 30, 9 * 30}, {9 * 30, 9 * 30}, {9 * 30, 1 * 30}};

	for (int i = 0; i < static_cast<int>(this->_players.size()); i++) {
		if (this->_players[i].isAi) {
			this->wrapping.addPlayerAi(static_cast<indie::PlayerAi<int> *>(this->_players[i].player));
			this->wrapping._aiPlayers.back()->setPosition(coordinates[i][0], 0, coordinates[i][1]);
		} else {
			this->wrapping.addPlayer(static_cast<indie::Player<int> *>(this->_players[i].player));
			this->wrapping._players.back()->setPosition(coordinates[i][0], 0, coordinates[i][1]);
		}
	}
	game->setWrap(this->wrapping);
	game->run();
	indie::irrlicht->smgr->clear();
}

void indie::SelectMenu::assign()
{
	indie::Audio::stop("ressources/musics/hover.ogg");
	indie::Audio::play("ressources/musics/hover.ogg");
	buttonSelect = select;
	buttonDirection = direction;
}

void indie::SelectMenu::run()
{
	std::vector<std::string> players = {"ressources/images/bomberman_blue.png", "ressources/images/bomberman_green.png", "ressources/images/bomberman_red.png", "ressources/images/bomberman_yellow.png"};
	std::vector<std::vector<int>> buttons = {{335, 776}, {411, 700}, {487, 776}, {411, 776}, {487, 700}};
	bool mousePressed = false;
	int in = 0;
	bool playStatus = true;

	for (int i = 0; i < 4; i++)
		_players.push_back({new indie::PlayerAi<int>(0, 0, 0, i), true});
	auto cursor = indie::irrlicht->device->getCursorControl()->getPosition();
	while (indie::irrlicht->device->run()) {
		if (indie::irrlicht->event->getEscape())
			break;
		indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
		if (indie::irrlicht->device->isWindowActive()) {
			this->printBackground();
			if (buttonSelect >= 0 && buttonDirection >= 0) {
				if ((in = indie::irrlicht->event->getKeyboardPress()) >= 0) {
					if (_players[buttonSelect].isAi == false) {
						for (int i = 0; i < _players.size(); i++) {
							if (_players[i].isAi == false) {
								for (int j = 0; j < 5; j++)
									if (static_cast<indie::Player<int> *>(_players[i].player)->getBinding(j) == in)
										static_cast<indie::Player<int> *>(_players[i].player)->setSingleBinding(j, -1);
							}
						}
						(static_cast<indie::Player<int> *>(_players[buttonSelect].player))->setSingleBinding(buttonDirection, in);
					}
					buttonSelect = -1;
					buttonDirection = -1;
				}
			}
			this->image(50, 90, "ressources/images/player_selection.png");

			for (int i = 0; i < static_cast<int>(players.size()); i++) {
				select = i;
				this->image(282 + 344 * i, 200, "ressources/images/bomberman_shadow.png");
				this->image(282 + 344 * i, 200, players[i]);
				if (_players[i].isAi == false) {
					this->image(282 + 344 * i, 200, "ressources/images/bomberman_button_crossed.png");
					for (int j = 0; j < static_cast<int>(buttons.size()); j++) {
						direction = j;
						if (buttonSelect == select && buttonDirection == direction)
							this->image(buttons[j][0] + 344 * i, buttons[j][1], "ressources/images/key_yellow.png");
						else if ((static_cast<indie::Player<int> *>(_players[i].player))->getBinding(direction) >= 0)
							this->button(buttons[j][0] + 344 * i, buttons[j][1], this, &indie::SelectMenu::assign, "ressources/images/key_green.png", "ressources/images/key_green.png");
						else
							this->button(buttons[j][0] + 344 * i, buttons[j][1], this, &indie::SelectMenu::assign, "ressources/images/key_white.png", "ressources/images/key_white.png");
						if (j == 4)
							this->image(buttons[j][0] + 344 * i, buttons[j][1], "ressources/images/key_bomb.png");
					}
				}
				else
					this->image(282 + 344 * i, 200, "ressources/images/bomberman_button.png");
				cursor = indie::irrlicht->device->getCursorControl()->getPosition();
				if (cursor.X >= (282 + 344 * i) * indie::irrlicht->R_RATIO && cursor.X <= (282 + 344 * i + 96) * indie::irrlicht->R_RATIO &&
					cursor.Y >= 200 * indie::irrlicht->R_RATIO && cursor.Y <= (200 + 96) * indie::irrlicht->R_RATIO && indie::irrlicht->event->getMouseState() && !mousePressed) {
					indie::Audio::stop("ressources/musics/hover.ogg");
					indie::Audio::play("ressources/musics/hover.ogg");
					mousePressed = true;
					buttonSelect = -1;
					buttonDirection = -1;
					if (this->_players[i].isAi) {
						static_cast<indie::PlayerAi<int> *>(this->_players[i].player)->getNode()->remove();
						this->_players[i] = {new indie::Player<int>(0, 0, 0, i), false};
					}
					else {
						static_cast<indie::Player<int> *>(this->_players[i].player)->getNode()->remove();
						this->_players[i] = {new indie::PlayerAi<int>(0, 0, 0, i), true};
					}
				}
				if (!indie::irrlicht->event->getMouseState())
					mousePressed = false;
			}
			playStatus = true;
			for (int i = 0; playStatus && i < static_cast<int>(_players.size()); i++)
				if (_players[i].isAi == false) {
					for (int j = 0; j < 5 && playStatus; j++)
						if (static_cast<indie::Player<int> *>(_players[i].player)->getBinding(j) == -1)
							playStatus = false;
				}
			if (playStatus)
				this->button(1480, 930, this, &indie::SelectMenu::play, "ressources/images/hard_code.png", "ressources/images/hard_code.png");
			indie::irrlicht->guienv->drawAll();
		} else
			indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
	}
}