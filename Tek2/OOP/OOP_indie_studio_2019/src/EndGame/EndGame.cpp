/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** EndGame.cpp
*/

#include "EndGame.hpp"
#include "MainMenu.hpp"

void indie::EndGame::run()
{
    ;
}

void indie::EndGame::displayThird()
{
    int clock_blue = this->_allPlayers[0]->getTimeSurvive().getElapsedTime();
    int clock_green = this->_allPlayers[1]->getTimeSurvive().getElapsedTime();
    int clock_red = this->_allPlayers[2]->getTimeSurvive().getElapsedTime();
    int clock_yellow = this->_allPlayers[3]->getTimeSurvive().getElapsedTime();

    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[0]) { // Blue
        if (clock_red < clock_green && clock_red < clock_yellow)
            this->image(1040, 660, "ressources/images/icons/RedBombermanIcon.png");
        else if (clock_green < clock_red && clock_green < clock_yellow)
            this->image(1040, 660, "ressources/images/icons/GreenBombermanIcon.png");
        else if (clock_yellow < clock_red && clock_yellow < clock_green)
            this->image(1040, 660, "ressources/images/icons/YellowBombermanIcon.png");
    }
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[1]) { // Green
        if (clock_red < clock_blue && clock_red < clock_yellow)
            this->image(1040, 660, "ressources/images/icons/RedBombermanIcon.png");
        else if (clock_blue < clock_red && clock_blue < clock_yellow)
            this->image(1040, 660, "ressources/images/icons/BlueBombermanIcon.png");
        else if (clock_yellow < clock_red && clock_yellow < clock_blue)
            this->image(1040, 660, "ressources/images/icons/YellowBombermanIcon.png");
    }
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[2]) { // Red
        if (clock_green < clock_blue && clock_green < clock_yellow)
            this->image(1040, 660, "ressources/images/icons/GreenBombermanIcon.png");
        else if (clock_blue < clock_green && clock_blue < clock_yellow)
            this->image(1040, 660, "ressources/images/icons/BlueBombermanIcon.png");
        else if (clock_yellow < clock_green && clock_yellow < clock_blue)
            this->image(1040, 660, "ressources/images/icons/YellowBombermanIcon.png");
    }
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[3]) { // Yellow
        if (clock_red < clock_blue && clock_red < clock_green)
            this->image(1040, 660, "ressources/images/icons/RedBombermanIcon.png");
        else if (clock_blue < clock_red && clock_blue < clock_green)
            this->image(1040, 660, "ressources/images/icons/BlueBombermanIcon.png");
        else if (clock_green < clock_red && clock_green < clock_blue)
            this->image(1040, 660, "ressources/images/icons/GreenBombermanIcon.png");
    }
}

void indie::EndGame::displaySecond()
{
    int clock_blue = this->_allPlayers[0]->getTimeSurvive().getElapsedTime();
    int clock_green = this->_allPlayers[1]->getTimeSurvive().getElapsedTime();
    int clock_red = this->_allPlayers[2]->getTimeSurvive().getElapsedTime();
    int clock_yellow = this->_allPlayers[3]->getTimeSurvive().getElapsedTime();

    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[0]) { // Blue
        if (clock_red > clock_green || clock_red > clock_yellow)
            this->image(710, 620, "ressources/images/icons/RedBombermanIcon.png");
        else if (clock_green > clock_red || clock_green > clock_yellow)
            this->image(710, 620, "ressources/images/icons/GreenBombermanIcon.png");
        else if (clock_yellow > clock_red || clock_yellow > clock_green)
            this->image(710, 620, "ressources/images/icons/YellowBombermanIcon.png");
    }
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[1]) { // Green
        if (clock_red > clock_blue || clock_red > clock_yellow)
            this->image(710, 620, "ressources/images/icons/RedBombermanIcon.png");
        else if (clock_blue > clock_red || clock_blue > clock_yellow)
            this->image(710, 620, "ressources/images/icons/BlueBombermanIcon.png");
        else if (clock_yellow > clock_red || clock_yellow > clock_blue)
            this->image(710, 620, "ressources/images/icons/YellowBombermanIcon.png");
    }
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[2]) { // Red
        if (clock_green > clock_blue || clock_green > clock_yellow)
            this->image(710, 620, "ressources/images/icons/GreenBombermanIcon.png");
        else if (clock_blue > clock_green || clock_blue > clock_yellow)
            this->image(710, 620, "ressources/images/icons/BlueBombermanIcon.png");
        else if (clock_yellow > clock_green || clock_yellow > clock_blue)
            this->image(710, 620, "ressources/images/icons/YellowBombermanIcon.png");
    }
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[3]) { // Yellow
        if (clock_red > clock_blue || clock_red > clock_green)
            this->image(710, 620, "ressources/images/icons/RedBombermanIcon.png");
        else if (clock_blue > clock_red || clock_blue > clock_green)
            this->image(710, 620, "ressources/images/icons/BlueBombermanIcon.png");
        else if (clock_green > clock_red || clock_green > clock_blue)
            this->image(710, 620, "ressources/images/icons/GreenBombermanIcon.png");
    }
}

void indie::EndGame::displayWinner()
{
    if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[0])
        this->image(880, 570, "ressources/images/icons/BlueBombermanIcon.png");
    else if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[1])
        this->image(880, 570, "ressources/images/icons/GreenBombermanIcon.png");
    else if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[2])
        this->image(880, 570, "ressources/images/icons/RedBombermanIcon.png");
    else if (this->_allPlayers[this->_indexPlayer] == this->_allPlayers[3])
        this->image(880, 570, "ressources/images/icons/YellowBombermanIcon.png");
        
}

void indie::EndGame::launchMainMenu()
{
    indie::Audio::stop("ressources/musics/hover.ogg");
	indie::Audio::play("ressources/musics/hover.ogg");
    indie::MainMenu menu;

    menu.run();
}

void indie::EndGame::quit()
{
    indie::irrlicht->device->closeDevice();
}

void indie::EndGame::run_EndGame(int indexPlayer, std::vector<indie::APlayer *> allPlayers)
{
	// IGUIStaticText *static_blue = indie::irrlicht->guienv->addStaticText(L"", rect<s32>(900, 500, 1000, 600), true, false, 0);
    // this->font = indie::irrlicht->device->getGUIEnvironment()->getFont("ressources/assets/fontcourier.bmp");
	// this->font->setKerningWidth(5 * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO));
    this->_indexPlayer = indexPlayer;
    this->_allPlayers = allPlayers;
    core::stringw str = L"Score: ";
    str += (rand() % 24000);
    IGUIStaticText *fpsTextElement = indie::irrlicht->guienv->addStaticText(L"Score: ", rect<s32>(880 * indie::irrlicht->R_RATIO, 500 * indie::irrlicht->R_RATIO, 1300 * indie::irrlicht->R_RATIO, 700 * indie::irrlicht->R_RATIO), false, false, 0);
    fpsTextElement->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
    fpsTextElement->setText(str.c_str());
    // indie::APlayer *player = this->_allPlayers[0];
    // static_blue->setOverrideFont(this->font);
    // core::stringw score_blue = L"Score: ";
    // score_blue += player->getTimeSurvive().getElapsedTime() / 1000;
    while (indie::irrlicht->device->run()) {
        if (indie::irrlicht->device->isWindowActive()) {
            if (indie::irrlicht->event->getEscape())
                indie::irrlicht->device->closeDevice();
    		indie::irrlicht->driver->beginScene(true, true, SColor(0,255,255,255));
            this->image(0, 0, "ressources/images/podium.png");
            this->displayWinner();
            this->displaySecond();
            this->displayThird();
            this->button(1600, 660, this, &indie::EndGame::launchMainMenu, "ressources/images/main_menu_end1.png", "ressources/images/main_menu_end2.png");
            this->button(1600, 810, this, &indie::EndGame::quit, "ressources/images/quit_end1.png", "ressources/images/quit_end2.png");
            // this->static_blue->setText(score_blue.c_str());
            indie::irrlicht->guienv->drawAll();
            indie::irrlicht->smgr->drawAll();
        } else
            indie::irrlicht->device->yield();
	    indie::irrlicht->driver->endScene();
    }
}