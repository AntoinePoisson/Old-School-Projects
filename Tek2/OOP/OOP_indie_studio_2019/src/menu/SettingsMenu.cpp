/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SettingsMenu
*/

#include "SettingsMenu.hpp"

indie::SettingsMenu::SettingsMenu()
    : isOpen(true), volume(100)
{}

void indie::SettingsMenu::printBackground()
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

void indie::SettingsMenu::volumeBtn()
{
    ITexture *butt1 = get_img("ressources/images/volume_btn.png");

    auto size = butt1->getSize();
    auto cursor = indie::irrlicht->device->getCursorControl()->getPosition();
    if (!_grab && (cursor.X > (x - 10) * indie::irrlicht->R_RATIO && cursor.X < (x - 10) * indie::irrlicht->R_RATIO + (size.Width + 20) * indie::irrlicht->R_RATIO) && (cursor.Y > 250 * indie::irrlicht->R_RATIO && cursor.Y < 250 * indie::irrlicht->R_RATIO + (size.Height + 20) * indie::irrlicht->R_RATIO)) {
        if (indie::irrlicht->event->getMouseState()) {
            indie::irrlicht->event->resetMouse();
            _grab = true;
        }
    }
    if (_grab) {
        if (indie::irrlicht->event->getReleaseState()) {
            indie::irrlicht->event->resetMouse();
            _grab = false;
        } else {
            x = cursor.X * (1 / indie::irrlicht->R_RATIO);
            if (x < 1066 + size.Width / 2)
                x = 1066 + size.Width / 2;
            else if (x > 1296 + size.Width / 2)
                x = 1296 + size.Width / 2;
        }
        int xx = (x - size.Width / 2 - 1066) / 2.3;
        if (xx != indie::irrlicht->volume) {
            indie::Audio::setVolume(xx);
            std::fstream file(".settingsAudio", std::ios::in | std::ios::out | std::ios::trunc);

            file.seekg(0, std::ios::beg);
            file.write(reinterpret_cast<char *>(&xx), sizeof(int));
            file.close();
        }
    }
    this->image(x - get_img("ressources/images/volume_btn.png")->getSize().Width / 2 - 6, 261, "ressources/images/volume_btn.png");
}

void indie::SettingsMenu::restart()
{
    while (indie::irrlicht->device->run()) {
        if (indie::irrlicht->event->getEscape())
            indie::irrlicht->device->closeDevice();
        indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
        if (indie::irrlicht->device->isWindowActive()) {
            this->printBackground();
            this->image(0, 0, "ressources/images/settings.png");
            this->image(0, 0, "ressources/images/restart.png");
		    indie::irrlicht->guienv->drawAll();
        } else
            indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
    }
}

void indie::SettingsMenu::set1920x1080()
{
    std::fstream file(".settings", std::ios::in | std::ios::out | std::ios::trunc);

    float tmp = 1.0;
    file.seekg(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&tmp), sizeof(float));
    file.close();
    if (indie::irrlicht->R_RATIO != 1.0)
        this->restart();
}

void indie::SettingsMenu::set1366x768()
{
    std::fstream file(".settings", std::ios::in | std::ios::out | std::ios::trunc);

    float tmp = 0.7111;
    file.seekg(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&tmp), sizeof(float));
    file.close();
    if (indie::irrlicht->R_RATIO != 0.7111)
        this->restart();
}

void indie::SettingsMenu::set1280x720()
{
    std::fstream file(".settings", std::ios::in | std::ios::out | std::ios::trunc);

    float tmp = 0.6666;
    file.seekg(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&tmp), sizeof(float));
    file.close();
    if (indie::irrlicht->R_RATIO != 0.6666)
        this->restart();
}

void indie::SettingsMenu::setLow()
{
    std::fstream file(".settingsQuality", std::ios::in | std::ios::out | std::ios::trunc);

    int tmp = 2;
    file.seekg(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
    file.close();
    indie::irrlicht->quality = 2;
}

void indie::SettingsMenu::setMedium()
{
    std::fstream file(".settingsQuality", std::ios::in | std::ios::out | std::ios::trunc);

    int tmp = 1;
    file.seekg(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
    file.close();
    indie::irrlicht->quality = 1;
}

void indie::SettingsMenu::setHigh()
{
    std::fstream file(".settingsQuality", std::ios::in | std::ios::out | std::ios::trunc);

    int tmp = 0;
    file.seekg(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
    file.close();
    indie::irrlicht->quality = 0;
}

void indie::SettingsMenu::run()
{
    ITexture *butt1 = get_img("ressources/images/volume_btn.png");
    auto size = butt1->getSize();

    x = (indie::irrlicht->volume * 2.3) + (1066 + size.Width / 2);
    while (isOpen && indie::irrlicht->device->run()) {
        if (indie::irrlicht->event->getEscape())
            this->isOpen = false;
        indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
        if (indie::irrlicht->device->isWindowActive()) {
            this->printBackground();
            this->image(0, 0, "ressources/images/settings.png");
            this->button(540, 460, this, &indie::SettingsMenu::set1920x1080, "ressources/images/1920x1080.png", "ressources/images/1920x1080_pressed.png");
            this->button(540, 540, this, &indie::SettingsMenu::set1366x768, "ressources/images/1366x768.png", "ressources/images/1366x768_pressed.png");
            this->button(540, 620, this, &indie::SettingsMenu::set1280x720, "ressources/images/1280x720.png", "ressources/images/1280x720_pressed.png");
            this->button(540, 765, this, &indie::SettingsMenu::setLow, "ressources/images/settings_low.png", "ressources/images/settings_low_hover.png");
            this->button(825, 765, this, &indie::SettingsMenu::setMedium, "ressources/images/settings_medium.png", "ressources/images/settings_medium_hover.png");
            this->button(1110, 765, this, &indie::SettingsMenu::setHigh, "ressources/images/settings_high.png", "ressources/images/settings_high_hover.png");
		    this->volumeBtn();
            indie::irrlicht->guienv->drawAll();
        } else
            indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
    }
}