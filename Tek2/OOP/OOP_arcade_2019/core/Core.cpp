/*
** EPITECH PROJECT, 2020
** Core
** File description:
** Core
*/

#include "Core.hpp"

    // Constructor
Arcade::Core::Core(const char *paramLib)
    : libParam(paramLib), input(-1), currentLibHandle(nullptr)
{
    if (!std::regex_search(this->libParam, std::regex("lib_arcade_\\S+.so"))) {
        if (this->libParam == "--help" || this->libParam == "-h") {
            std::cout << "USAGE" << std::endl << "\t./arcade lib_arcade_$libraryname.so" << std::endl;
            std::cout << "DESCRIPTION" << std::endl << "\tPlay arcade game on differente game and graphical library." << std::endl;
            std::cout << "\tThe goal of Arcade Projet is change library in runtime." << std::endl;
            throw Error("", "", RETURN_SUCCESS);
        }
        throw Error("Core constructor", "library name is invalide.");
    }
    Arcade::LoadHandling<std::string> loader;
    if (!loader.checkFunctLib(false, libParam))
        throw Error("", "");
    currentLibHandle = dlopen(paramLib, RTLD_NOW);
    if (!currentLibHandle)
        throw Error("", dlerror());
    indexCurrentLibHandle = 0;
    indexCurrentGameHandle = 0;
    currentGameHandle = nullptr;
    graphics = nullptr;
    games = nullptr;
    changeScoreName = false;
    scoreName = "no_name";
    scoreValue = 0;
    windowHeight = 0;
    windowWidth = 0;
    saveInputGame = INPUT_NOTHING;
    loader.load("./lib/", "./games/", "./core/.score", libParam);
    handleGames = loader.getGames();
    handleLibs = loader.getLibs();
    handleLibs.push_back(libParam);
    highScoreName = loader.getHighScoreName();
    highScoreValue = loader.getHighScoreValue();
}
    // Destructor
Arcade::Core::~Core()
{
    dlclose(currentLibHandle);
}


    // Class Methode
void Arcade::Core::changeLib(bool isNextLib)
{
    void *tmp = nullptr;

    if (isNextLib) {
        indexCurrentLibHandle++;
        if (indexCurrentLibHandle > int(handleLibs.size() - 1))
            indexCurrentLibHandle = 0;
    } else {
        indexCurrentLibHandle--;
        if (indexCurrentLibHandle < 0)
            indexCurrentLibHandle = handleLibs.size() - 1;
    }
    graphics->destructor();
    delete graphics;
    dlclose(currentLibHandle);
    currentLibHandle = dlopen(handleLibs[indexCurrentLibHandle].c_str(), RTLD_NOW);
    if (!currentLibHandle)
        throw Error("", dlerror());
    tmp = dlsym(currentLibHandle, "create");
    if (!tmp)
        throw Error("changeLib", "Fatal Error methode create fails.");
    createLib_t *initialize_graphics = reinterpret_cast<createLib_t *> (tmp);
    graphics = initialize_graphics();
    windowHeight = graphics->getWindowHeight();
    windowWidth = graphics->getWindowWidth();
}

void Arcade::Core::managementInputGame()
{
    switch (input) {
        case INPUT_A: return (changeLib(false));
        case INPUT_E: return (changeLib(true));
        case INPUT_O: return (changeGame("", false, false));
        case INPUT_P: return (changeGame("", false, true));
        case INPUT_R: return (games->restart());
        case INPUT_Z: saveInputGame = input;
            return;
        case INPUT_S: saveInputGame = input;
            return;
        case INPUT_Q: saveInputGame = input;
            return;
        case INPUT_D: saveInputGame = input;
            return;
        default: return;
    }
}

void Arcade::Core::changeGame(std::string nameGame, bool callInMenu = true, bool isNextGame = false)
{
    if (!callInMenu) {
        if (isNextGame) {
            indexCurrentGameHandle++;
            if (indexCurrentGameHandle > int(handleGames.size() - 1))
                indexCurrentGameHandle = 0;
        } else {
            indexCurrentGameHandle--;
            if (indexCurrentGameHandle < 0)
                indexCurrentGameHandle = handleGames.size() - 1;
        }
        nameGame = handleGames[indexCurrentGameHandle];
    }
    if (!games) {
        currentGameHandle = dlopen(nameGame.c_str(), RTLD_NOW);
        if (!currentGameHandle)
            throw Error("changeGame", dlerror());
        void *tmp = dlsym(currentGameHandle, "create");
        if (!tmp)
            throw Error("changeGame", "Fatal Error methode create fails.");
        createGame_t *initialize_games = reinterpret_cast<createGame_t *> (tmp);
        games = initialize_games();
        listDisplay = games->getInitState();
    } else if (nameGame != "" && callInMenu) {
        delete games;
        games = nullptr;
        dlclose(currentGameHandle);
        listDisplay.clear();
    } else {
        delete games;
        games = nullptr;
        dlclose(currentGameHandle);
        currentGameHandle = dlopen(nameGame.c_str(), RTLD_NOW);
        if (!currentGameHandle)
            throw Error("changeGame", dlerror());
        void *tmp = dlsym(currentGameHandle, "create");
        if (!tmp)
            throw Error("changeGame", "Fatal Error methode create fails.");
        createGame_t *initialize_games = reinterpret_cast<createGame_t *> (tmp);
        games = initialize_games();
        listDisplay = games->getInitState();
    }
}

void Arcade::Core::managementInputLib()
{
    if (input >= '1' && input <= '9' && size_t(input - '0') <= handleGames.size()) {
        indexCurrentGameHandle = input - 1 - '0';
        changeGame(handleGames[indexCurrentGameHandle]);
        return;
    }
    if (changeScoreName) {
        if (input == INPUT_VALIDE || scoreName.size() >= 10) {
            changeScoreName = false;
        } else if (input >= 'a' && input <= 'z') {
            scoreName += input;
        }
        return;
    }
    switch (input) {
        case INPUT_A: return (changeLib(false));
        case INPUT_E: return (changeLib(true));
        case 'n': changeScoreName = true;
            scoreName = "";
            return;
        default: return;
    }
}

std::string Arcade::Core::reworkNameLib(std::string s)
{
    std::string ret = &s[s.rfind("lib_arcade_") + 10];
    for (int j = 0; j < 3; j++)
        ret.pop_back();
    return (ret);
}

int Arcade::Core::positionToDisplay(float pos, int sizeMax)
{
    int ret = pos * (sizeMax * 1.0);
    return (ret);
}

void Arcade::Core::displayMenu()
{
    display_t backGround = {"", "", "", "./resources/textures/menuBackGround.jpg", 0, 0, true};
    size_t libNum = handleLibs.size();
    size_t gamNum = handleGames.size();
    float x = positionToDisplay(0.15, windowWidth);
    float y = positionToDisplay(0.1, windowHeight);

    if (libNum == 0 || gamNum == 0)
        throw Error("displayMenu", "not enought game or lib ! sorry :|");
    graphics->print(backGround);
    display_t titleLib = {"LIST OF LIB :", "", "", "", x, y, true};
    graphics->print(titleLib);
    y += positionToDisplay(0.7, windowHeight) / libNum;
    for (size_t i = 0; i < libNum; i++) {
        display_t lib = {(reworkNameLib(handleLibs.at(i))), "", "", "", x, y, true};
        y += positionToDisplay(0.7, windowHeight) / libNum;
        graphics->print(lib);
    }
    x = positionToDisplay(0.55, windowWidth);
    y = positionToDisplay(0.1, windowHeight);
    display_t titleGam = {"CHOOSE YOUR GAME :", "", "", "", x, y, true};
    graphics->print(titleGam);
    y += positionToDisplay(0.7, windowHeight) / gamNum;
    for (size_t i = 0; i < gamNum; i++) {
        display_t gam = {(std::to_string(i + 1) += reworkNameLib(handleGames.at(i))), "", "", "", x, y, true};
        y += positionToDisplay(0.7, windowHeight) / gamNum;
        graphics->print(gam);
    }
    x = positionToDisplay(0.35, windowWidth);
    y = positionToDisplay(0.87, windowHeight);
    std::string score = "Score = " + scoreName + " : " + std::to_string(scoreValue);
    display_t name = {score, "", "", "", x, y, true};
    graphics->print(name);
    x = positionToDisplay(0.296, windowWidth);
    y = positionToDisplay(0.93, windowHeight);
    std::string highScore = "HighScore = " + highScoreName + " : " + std::to_string(highScoreValue);
    display_t high = {highScore, "", "", "", x, y, true};
    graphics->print(high);
    graphics->refresh();
}

Arcade::statusGame Arcade::Core::displayGame()
{
    if (games->speedGame()) {
        games->move(saveInputGame);
        listDisplay = games->getState();
        for (size_t i = 0; i < listDisplay.size(); i++) {
            listDisplay[i].x = positionToDisplay(listDisplay[i].x, windowWidth) * 1.0;
            listDisplay[i].y = positionToDisplay(listDisplay[i].y, windowHeight) * 1.0;
            graphics->print(listDisplay[i]);
        }
        graphics->refresh();
        saveInputGame = INPUT_NOTHING;
    }
    return (games->getStatus());
}

void Arcade::Core::changeHighScore()
{
    highScoreName = scoreName;
    highScoreValue = scoreValue;
    std::ofstream file;
    if (!file)
        throw Error("changeHighScore", "error with score file");
    file.open("core/.score", std::ios::trunc);
    file << scoreName << "=" << std::to_string(scoreValue) << std::endl;
    file.close();
}

bool Arcade::Core::finalCondition()
{
    Arcade::statusGame status;
    display_t finalMessage;

    if ((status = displayGame()) != Arcade::INGAME) {
        float x = positionToDisplay(0.35, windowWidth);
        float y = positionToDisplay(0.45, windowHeight);
        if (status == Arcade::WIN)
            finalMessage = {"WTF U WIN !!!", "", "", "", x, y, true};
        else
            finalMessage = {"OHHHH !!! try again", "", "", "", x, y, true};
        graphics->print(finalMessage);
        scoreValue = games->getScore();
        std::string score = "Score = " + scoreName + " : " + std::to_string(games->getScore());
        x = positionToDisplay(0.1, windowWidth);
        y = positionToDisplay(0.87, windowHeight);
        display_t name = {score, "", "", "", x, y, true};
        graphics->print(name);
        x = positionToDisplay(0.1, windowWidth);
        y = positionToDisplay(0.93, windowHeight);
        std::string highScore = "HighScore = " + highScoreName + " : " + std::to_string(highScoreValue);
        display_t high = {highScore, "", "", "", x, y, true};
        graphics->print(high);
        graphics->refresh();
        if (highScoreValue < scoreValue)
            changeHighScore();
        for (int count = 0; input == INPUT_NOTHING && count < 4;) {
            input = graphics->getEvent();
            if (games->speedGame())
                count++;
            if (input == 'r') {
                games->restart();
                input = INPUT_NOTHING;
                return false;
            }
        }
        return true;
    }
    return false;
}

Arcade::Value Arcade::Core::launchCore()
{
    void *tmp = dlsym(currentLibHandle, "create");

    if (!tmp)
        throw Error("launchCore", "Fatal Error methode create fails.");
    createLib_t *initialize_graphics = reinterpret_cast<createLib_t *> (tmp);
    graphics = initialize_graphics();
    windowHeight = graphics->getWindowHeight();
    windowWidth = graphics->getWindowWidth();
    while (input != Arcade::INPUT_CLOSE && input != Arcade::INPUT_ESCAPE) {
        if (input != INPUT_NOTHING) {
            managementInputLib();
            input = INPUT_NOTHING;
        }
        displayMenu();
        input = graphics->getEvent();
        if (!games)
            continue;
        while (input != Arcade::INPUT_CLOSE && input != Arcade::INPUT_M && input != Arcade::INPUT_ESCAPE) {
            if (input != INPUT_NOTHING) {
                managementInputGame();
                input = INPUT_NOTHING;
            }
            if (finalCondition())
                break;
            input = graphics->getEvent();
        }
        changeGame("clear");
    }
    graphics->destructor();
    delete graphics;
    return (Arcade::RETURN_SUCCESS);
}