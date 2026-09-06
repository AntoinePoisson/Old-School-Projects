/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Main.cpp
*/

#include "Indie.hpp"
#include "Main.hpp"
#include "MainMenu.hpp"
#include "SelectMenu.hpp"
#include "SplashMenu.hpp"

static void bomberman();
static int check_args(int ac, const char *flag, const char **env);

int main(int ac, const char **av, const char **env)
{
    int value = check_args(ac, av[1], env);

    if (value)
        return value;
    try {
        bomberman();
    } catch (const indie::error::Error &error) {
        if (error.getComponent().empty() == false)
            std::cerr << "In " << error.getComponent() << ": " << error.what() << std::endl;
        else if (error.what() != nullptr)
            std::cerr << error.what() << std::endl;
        return error.getValue();
    } catch (const indie::error::IBase &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    } catch (...) {
        std::cerr << "Error Bomberman" << std::endl;
        return 84;
    }
    return 0;
}

static int check_args(int ac, const char *flag, const char **env)
{
    if (!env) {
        std::cerr << "Error: No environnement." << std::endl;
        return 84;
    }
    if (ac >= 2 && (!strcmp(flag, "-h") || !strcmp(flag, "-help") || !strcmp(flag, "--help"))) {
        std::cout << "It's a Bomberman Multi-Player, Cross Platform." << std::endl;
        return 1;
    }
    return 0;
}

static void bomberman()
{
    indie::irrlicht = new indie::Irrlicht();
    indie::irrlicht->event = new indie::Event();
    indie::irrlicht->R_RATIO = 0.6666;
    indie::irrlicht->quality = 0;
    std::ifstream file(".settings", std::ios::in);

    if (file.is_open()) {
        file.read(reinterpret_cast<char *>(&(indie::irrlicht->R_RATIO)), sizeof(float));
    }
    indie::Audio::setVolume(1);
    std::ifstream fileAudio(".settingsAudio", std::ios::in);

    if (fileAudio.is_open()) {
        fileAudio.read(reinterpret_cast<char *>(&(indie::irrlicht->volume)), sizeof(int));
        indie::Audio::setVolume(indie::irrlicht->volume);
    }
    std::ifstream fileQuality(".settingsQuality", std::ios::in);

    if (fileQuality.is_open()) {
        fileQuality.read(reinterpret_cast<char *>(&(indie::irrlicht->quality)), sizeof(int));
    }
    indie::irrlicht->device = createDevice(EDT_SOFTWARE, dimension2d<u32>(indie::irrlicht->R_RATIO * 1920, indie::irrlicht->R_RATIO * 1080), 32, false, true, true, indie::irrlicht->event);

    if (!indie::irrlicht->device)
		throw indie::error::Error("Window", "Error: bad device creation", 84);

    indie::irrlicht->device->setWindowCaption(L"Bomberman");
    indie::irrlicht->driver = indie::irrlicht->device->getVideoDriver();
    indie::irrlicht->smgr = indie::irrlicht->device->getSceneManager();
    indie::irrlicht->guienv = indie::irrlicht->device->getGUIEnvironment();
    indie::irrlicht->driver->setTextureCreationFlag(irr::video::ETCF_OPTIMIZED_FOR_SPEED);

    std::unique_ptr<indie::SplashMenu> splashMenu = std::make_unique<indie::SplashMenu>();

    splashMenu->run();
    std::unique_ptr<indie::MainMenu> mainMenu = std::make_unique<indie::MainMenu>();

    mainMenu->run();

	indie::irrlicht->device->drop();
    for (auto music : indie::listMusics)
        music.second->~Music();
    delete indie::irrlicht->event;
    delete indie::irrlicht;
}