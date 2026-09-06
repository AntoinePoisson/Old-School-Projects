/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LoadingSave
*/

#include "LoadingSave.hpp"

std::ostream& indie::operator<<(std::ostream& stm, const indie::Map &map)
{
    stm << map.getSeed() << '\n';
    stm << map.getBox().size() << '\n';
    for (indie::Box &a : map.getBox()) {
        stm << a.getType() << '\n';
    }
    return stm;
}

std::ostream& indie::operator<<(std::ostream& stm, const indie::WrapPlayers<int> &wrap)
{
    stm << wrap.getPlayers().size() << '\n';
    for (indie::Player<int> *s : wrap.getPlayers()) {
        stm << s->getX() << ' ';        // constructor
        stm << s->getY() << ' ';        // constructor
        stm << s->getZ() << ' ';        // constructor
        stm << s->getColor() << ' ';    // constructor
        stm << s->getState() << ' ';    // setState
        stm << s->getNbBomb() << ' ';   // setNbBomb
        stm << s->getSpeedPlayer() << ' ';
        stm << s->getThoughtBox() << ' ';
        stm << s->getRangeBomb() << ' ';
        for (int i : s->getBinding())
            stm << i << ' ';
        stm << '\n';
    }

    stm << wrap.getPlayersAi().size() << '\n';
    for (indie::PlayerAi<int>* ai : wrap.getPlayersAi()) {
        stm << ai->getX() << ' ';        // constructor
        stm << ai->getY() << ' ';        // constructor
        stm << ai->getZ() << ' ';        // constructor
        stm << ai->getColor() << ' ';    // constructor
        stm << ai->getState() << ' ';    // setState
        stm << ai->getNbBomb() << ' ';   // setNbBomb
        stm << ai->getSpeedPlayer() << ' ';
        stm << ai->getThoughtBox() << ' ';
        stm << ai->getRangeBomb() << '\n';
    }

    // stm << wrap.getBomb().size() << '\n';
    // for (std::shared_ptr<indie::Bomb> bomb : wrap.getBomb()) {
    //     indie::Bomb *b = bomb.get();
    //     stm << b->getX() << ' ';
    //     stm << b->getY() << ' ';
    //     stm << b->getZ() << ' ';
    //     stm << b->getState() << ' ';
    //     stm << b->getRangeBomb() << '\n';
    // }
    return stm;
}

std::istream& indie::operator>>(std::istream &stm, indie::Map &map)
{
    int type;
    int count = 0;
    std::size_t size;

    stm >> size;
    for (indie::Box &box : map.getBox()) {
        stm >> type;
        if (type == indie::ObjectType::NONE)
            box.deletBox();
        if (type != indie::ObjectType::NONE && type != indie::ObjectType::BOX)
            box.ExplosionBox();
//            box.setType(static_cast<indie::ObjectType>(type));
        count++;
    }
    if (!stm || count != size) {
        std::cout << "FAIL TO LOAD MAP" << std::endl;
        map = {};
    }
    return stm;
}

std::istream &indie::operator>>(std::istream &stm, indie::WrapPlayers<int> &wrap)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int8_t color = 0;
    bool state;
    int nbBomb = 0;
    int left = 0;
    int up = 0;
    int right = 0;
    int down = 0;
    int bob = 0;
    int range = 0;
    float speed;
    bool thought;

    std::size_t size;
    stm >> size;
    for (int i = 0; i < size; i++) {
        stm >> x >> y >> z >> color >> state >> nbBomb >> speed >> thought >> range;
        stm >> left >> up >> right >> down >> bob;
        wrap.addPlayer(x, y, z, color);
        wrap.getPlayers().back()->setBinding(left, up, right, down, bob);
        wrap.getPlayers().back()->setState(state);
        wrap.getPlayers().back()->setNbBomb(nbBomb);
        wrap.getPlayers().back()->setSpeedPlayer(speed);
        wrap.getPlayers().back()->setThoughtBox(thought);
        wrap.getPlayers().back()->setRangeBomb(range);
        if (state == false)
            wrap.getPlayers().back()->getNode()->remove();
    }

    stm >> size;
    for (int i = 0; i < size; i++) {
        stm >> x >> y >> z >> color >> state >> nbBomb >> speed >> thought >> range;
            wrap.addPlayerAi(x, y, z, color);
            wrap.getPlayersAi().back()->setState(state);
            wrap.getPlayersAi().back()->setNbBomb(nbBomb);
            wrap.getPlayersAi().back()->setSpeedPlayer(speed);
            wrap.getPlayersAi().back()->setThoughtBox(thought);
            wrap.getPlayersAi().back()->setRangeBomb(range);
        if (state == false)
            wrap.getPlayersAi().back()->getNode()->remove();
    }

    // stm >> size;
    // for (int i = 0; i < size; i++) {
    //     stm >> x >> y >> z >> state >> range;
    //     wrap.addBomb(x, y, z, range);
    //     wrap.getBomb().back()->setState(state);
    // }

    if (!stm) {
        std::cout << "FAIL TO LOAD WRAPPER" << std::endl;
        wrap = {};
    }
    return stm;
}

indie::LoadingMenu::LoadingMenu()
{
    
}

void indie::LoadingMenu::run()
{
    indie::LoadingSave<indie::Map, indie::WrapPlayers<int>> *loadi = new indie::LoadingSave<indie::Map, indie::WrapPlayers<int>>();

    if (loadi->getRecentSave().empty())
        return;
	while (indie::irrlicht->device->run()) {
		if (indie::irrlicht->event->getEscape())
			break;

		indie::irrlicht->driver->beginScene(true, true, SColor(0, 255, 255, 255));
		if (indie::irrlicht->device->isWindowActive()) {
			this->image(0, 0, "ressources/images/play_modal.png");
        if (loadi->getRecentSave().size() >= 1)
            button(1920 / 2 - 609 / 2 + 17, 100, loadi, &indie::LoadingSave<indie::Map, indie::WrapPlayers<int>>::setWhich0, "ressources/images/loadgame1.png", "ressources/images/loadgame1press3.png");
        if (loadi->getRecentSave().size() >= 2)
            button(1920 / 2 - 609 / 2 + 17, 400, loadi, &indie::LoadingSave<indie::Map, indie::WrapPlayers<int>>::setWhich1, "ressources/images/loadgame2.png", "ressources/images/loadgame2press3.png");
        if (loadi->getRecentSave().size() >= 3)
            button(1920 / 2 - 609 / 2 + 17, 700, loadi, &indie::LoadingSave<indie::Map, indie::WrapPlayers<int>>::setWhich2, "ressources/images/loadgame3.png", "ressources/images/loadgame3press3.png");
			indie::irrlicht->guienv->drawAll();
		} else
			indie::irrlicht->device->yield();
		indie::irrlicht->driver->endScene();
	}
}

// bool indie::LoadingSave::deleteFile(const std::string &fileName)
// {
//     std::string filePath = "./ressources/.saves/." + fileName;

//     if (remove(filePath.c_str()) == 0)
//         return true;
//     std::cout << fileName << " : not found to be deleted" << std::endl;
//     return false;
// }

// bool indie::LoadingSave::renameSave(const std::string &oldFileName, const std::string &newFileName)
// {
//     std::string oldFilePath = "./ressources/.saves/." + oldFileName;
//     std::string newFilePath = "./ressources/.saves/." + newFileName;

//     if (rename(oldFilePath.c_str(), newFilePath.c_str()) == 0)
//         return true;
//     std::cout << oldFileName << " : not found to be renamed" << std::endl;
//     return false;
// }

// OVERLOAD LES OPERATEURS