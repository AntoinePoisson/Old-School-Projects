/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** gameLoop.cpp
*/

#include "LoadingSave.hpp"
#include "GameLoop.hpp"
#include "SettingsMenu.hpp"
#include "MainMenu.hpp"
#include "EndGame.hpp"

indie::Game::Game()
{
    this->_map = indie::Map(time(nullptr), 0, 0);
}

indie::Game::Game(indie::Map &map, indie::WrapPlayers<int> &wrapping)
{
    this->_map = map;
    _wrapping = wrapping;
}

void indie::Game::setWrap(indie::WrapPlayers<int> &wrapping)
{
    this->_wrapping = wrapping;
    _wrapping.getAllPlayers()[0]->setPosition(30, 0, 30);
    _wrapping.getAllPlayers()[1]->setPosition((_map.getWidthMap() * 30) - 60, 0, 30);
    _wrapping.getAllPlayers()[2]->setPosition((_map.getWidthMap() * 30) - 60, 0, (_map.getHeightMap() * 30) - 60);
    _wrapping.getAllPlayers()[3]->setPosition(30, 0, (_map.getHeightMap() * 30) - 60);
}

indie::ObjectType indie::Game::checkAndMove(const direction_t &direction, int x, int z, float speed, bool thoughtBox, int rangeBomb, int nbrBomb)
{
    if (direction == Bomber && nbrBomb > 0) {
        int _x = _map.getIndexPositionX(std::round(x)) * 3 * MULTIPLICATOR;
        int _z = _map.getIndexPositionY(std::round(z)) * 3 * MULTIPLICATOR;
        _wrapping.addBomb(std::round(_x), 0, std::round(_z), rangeBomb);
        return indie::ObjectType::WALL;
    }
    switch (_map.checkCanMove(std::round(x), std::round(z), direction, speed, thoughtBox)) {
        case 0: return (indie::ObjectType::NONE);
        case 1: return (indie::ObjectType::WALL);
        case indie::ObjectType::POWER_SPEED : return (indie::ObjectType::POWER_SPEED);
        case indie::ObjectType::POWER_MOREBOMB : return (indie::ObjectType::POWER_MOREBOMB);
        case indie::ObjectType::POWER_PASSBOX : return (indie::ObjectType::POWER_PASSBOX);
        case indie::ObjectType::POWER_UPRANGEBOMB : return (indie::ObjectType::POWER_UPRANGEBOMB);
        default: return (indie::ObjectType::NONE);
   };
}

void indie::Game::setUpPause()
{
    indie::Audio::stop("ressources/musics/hover.ogg");
	indie::Audio::play("ressources/musics/hover.ogg");
	this->isPause = true;
}

void indie::Game::setUnpause()
{
	this->isPause = false;
}

void indie::Game::launchSettings()
{
    std::unique_ptr<indie::SettingsMenu> menu = std::make_unique<indie::SettingsMenu>();

    menu->run();
}

void indie::Game::launchSave()
{
    indie::LoadingSave save(_map, _wrapping);

    save.save();
}

void indie::Game::launchMainMenu()
{
    std::unique_ptr<indie::MainMenu> menu = std::make_unique<indie::MainMenu>();

    indie::irrlicht->smgr->clear();
    menu->run();
}

void indie::Game::launchEndGame()
{
    indie::Audio::stop("ressources/musics/main_music.wav");
    indie::Audio::stop("ressources/musics/Victoire.ogg");
    indie::Audio::play("ressources/musics/Victoire.ogg");
    indie::Audio::setSpecificVolume("ressources/musics/Victoire.ogg", indie::irrlicht->volume * 5);
    std::unique_ptr<indie::EndGame> menu = std::make_unique<indie::EndGame>();

    menu->run_EndGame(_wrapping.getIndexLastPlayerAlive(), _wrapping.getAllPlayers());
}

void indie::Game::quit()
{
    indie::irrlicht->device->closeDevice();
}

void indie::Game::printDeadPlayers()
{
    if (this->_wrapping.getAllPlayers()[0]->getState() == false)
        this->image(60, 650, "ressources/images/icons/DeadBombermanIcon.png");
    if (this->_wrapping.getAllPlayers()[1]->getState() == false)
        this->image(1675, 650, "ressources/images/icons/DeadBombermanIcon.png");
    if (this->_wrapping.getAllPlayers()[2]->getState() == false)
        this->image(1675, 100, "ressources/images/icons/DeadBombermanIcon.png");
    if (this->_wrapping.getAllPlayers()[3]->getState() == false)
        this->image(60, 100, "ressources/images/icons/DeadBombermanIcon.png");
}

void indie::Game::printBombUI(void)
{
    int index = 0;
    int x = 0;
    int y = 0;

    for (auto player : this->_wrapping.getAllPlayers()) {
        if (index == 0) {
            x = 60;
            y = 650; // y
        } else if (index == 1) {
            x = 1675; // x
            y = 650; // y
        } else if (index == 2) {
            x = 1675; // x
            y = 100;
        } else if (index == 3) {
            x = 60;
            y = 100;
        } else {
            x = -300;
            y = -650;
        }
        switch (player->getColor()) {
            case 3:
                this->image(x, y, "ressources/images/icons/YellowBombermanIcon.png");
                this->printNbBombs(index, 50, 250);
                break;
            case 0:
                this->image(x, y, "ressources/images/icons/BlueBombermanIcon.png");
                this->printNbBombs(index, 50, 800);
                break;
            case 2:
                this->image(x, y, "ressources/images/icons/RedBombermanIcon.png");
                this->printNbBombs(index, 1635, 250);
                break;
            case 1:
                this->image(x, y, "ressources/images/icons/GreenBombermanIcon.png");
                this->printNbBombs(index, 1635, 800);
                break;
        }
        index++;
    }
}

void indie::Game::printNbBombs(int i, int pos_x, int pos_y)
{
    switch (i) {
        case 0:
            pos_x = 45;
            pos_y = 800; // y
            break;
        case 1:
            pos_x = 1650; // x
            pos_y = 800; // y
            break;
        case 2:
            pos_x = 1650; // x
            pos_y = 250;
            break;
        case 3:
            pos_x = 45;
            pos_y = 250;
            break;
        default:
            pos_x = -300;
            pos_y = -300;
            break;
    }
    if (this->_wrapping.getAllPlayers()[i]->getNbBomb() >= 10)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/10_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 9)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/9_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 8)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/8_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 7)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/7_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 6)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/6_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 5)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/5_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 4)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/4_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 3)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/3_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 2)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/2_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() == 1)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/1_bombs.png");
    else if (this->_wrapping.getAllPlayers()[i]->getNbBomb() <= 0)
        this->image(pos_x, pos_y, "ressources/images/nb_bombs/0_bombs.png");
}

void indie::Game::run()
{
	IGUIStaticText *fpsTextElement = indie::irrlicht->guienv->addStaticText(L"", rect<s32>(10, 10, 140, 50), false, false, 0);
    indie::direction_t direction = indie::None;
    indie::ObjectType action = indie::ObjectType::BOX;
    ITexture *bg = get_img("./ressources/images/background.jpg");
    indie::Clock clockEvent;

    while (indie::irrlicht->device->run()) {
		indie::irrlicht->driver->beginScene(true, true, SColor(0,255,255,255));
        indie::irrlicht->driver->draw2DImage(bg, position2d<s32>(0, 0), rect<s32>(0,0,1920 * indie::irrlicht->R_RATIO,1080 * indie::irrlicht->R_RATIO), 0, SColor(255,255,255,255), false);
        if (indie::irrlicht->event->getEscape() && this->isPause == false)
            this->setUpPause();
        if (this->isPause == true) {
            this->image(0, 0, "ressources/images/pause_pannel.png");
            this->button(540, 460, this, &indie::Game::setUnpause, "ressources/images/resume.png", "ressources/images/resume_hover.png");
            this->button(540, 540, this, &indie::Game::launchSettings, "ressources/images/settings_pause.png", "ressources/images/settings_pause_hover.png");
            this->button(540, 620, this, &indie::Game::launchSave, "ressources/images/save.png", "ressources/images/save_hover.png");
            this->button(540, 700, this, &indie::Game::launchMainMenu, "ressources/images/main_menu_pause.png", "ressources/images/main_menu_pause_hover.png");
            this->button(540, 780, this, &indie::Game::quit, "ressources/images/quit.png", "ressources/images/quit_hover.png");
        } else {
            if (clockEvent.getElapsedTime() >= (1000 / MOVE_PER_SECONDS)) {
                clockEvent.restart();
                for (auto player : this->_wrapping.getPlayers()) {
                    for (int j = 0; j < 5; j++) {
                        if ((j == 4 && indie::irrlicht->event->getBuffer(player->getBinding()[j], true)) ||
                        (j < 4 && indie::irrlicht->event->getBuffer(player->getBinding()[j], false))) {
                            if (player->getState() == true) {
                                player->regeneBomb();
                                direction = player->checkCanMove(player->getBinding()[j]);
                                if ((action = checkAndMove(direction, player->getCenter().X, player->getCenter().Z, player->getSpeedPlayer(), player->getThoughtBox(), player->getRangeBomb(), player->getNbBomb())) != 0) {
                                    player->move(direction);
                                    player->setNbBomb(player->getNbBomb());
                                    if (action > 1)
                                        player->powerUp(action);
                                }
                            }
                        }
                    }
                    if (player->clockAnimation.getElapsedTime() >= 100 && player->getState())
                        player->getNode()->setAnimationSpeed(0);
                    else if (player->getState())
                        player->getNode()->setAnimationSpeed(50);
                }
                for (indie::PlayerAi<int> * player : _wrapping.getPlayersAi()) {
                    if (player->getState() == true) {
                        player->regeneBomb();
                        player->setMap(_map, _wrapping.getBomb());
                        direction = player->checkCanMove(player->checkPlayers(_map.getBox(), _wrapping.getAllPlayers()));
                        if ((action = checkAndMove(direction, player->getCenter().X, player->getCenter().Z, player->getSpeedPlayer(), player->getThoughtBox(), player->getRangeBomb(), player->getNbBomb())) != 0) {
                            player->move(direction);
                            player->setNbBomb(player->getNbBomb());
                            if (action > 1)
                                player->powerUp(action);
                        }
                    }
                }
            }
            for (std::shared_ptr<indie::Bomb> bomb : _wrapping.getBomb()) {
                if (bomb->getState() &&
                    bomb->isExplosion(_map.getMap(),
                    _map.getIndexPositionX(bomb->getX()),
                    _map.getIndexPositionY(bomb->getZ()),
                    this->_wrapping.getAllPlayers(),
                    _map.getBox())) {
                    if (indie::Audio::getStatus("ressources/musics/bomb.ogg") == 2)
                        indie::Audio::stop("ressources/musics/bomb.ogg");
                    indie::Audio::setSpecificVolume("ressources/musics/bomb.ogg", indie::irrlicht->volume * 1.5);
                    bomb->setState(false);
                    bomb->getNode()->remove();
                }
            }
            this->printBombUI();
            this->printDeadPlayers();
            this->button(1825, 10, this, &indie::Game::setUpPause, "ressources/images/pause.png", "ressources/images/pause_hover.png");
            int fps = indie::irrlicht->driver->getFPS();
            if (indie::irrlicht->fps != fps) {
                core::stringw str = L"FPS: ";
                str += fps;
                fpsTextElement->setText(str.c_str());
                indie::irrlicht->fps = fps;
            }
            indie::irrlicht->guienv->drawAll();
            indie::irrlicht->smgr->drawAll();
            if (_wrapping.getNbrAlivePlayer() == 0 || _wrapping.getNbrAlivePlayer() == 1) {
                indie::irrlicht->smgr->clear();
                this->launchEndGame();
                return;
            }
        }
	    indie::irrlicht->driver->endScene();
    }
}