/*
** EPITECH PROJECT, 2020
** Pacman
** File description:
** Pacman
*/

#include "Pacman.hpp"

    //Constructor
ArcadeGame::Pacman::Pacman()
{
    int iObj = 0;
    int iPlayer = 0;
    cellSize = 0.050000f;
    std::srand(std::time(nullptr));
    genStrMap();
    genLayerMap(0, true);
    genLayerMap('.', false);
    genLayerMap('*', false);
    genLayerMap('G', false);
    genLayerMap('P', false);
    map = initState;
    score = 0;
    powerUp = false;
    dying = false;
    gameFinish = Arcade::statusGame::INGAME;
    timeStart = std::chrono::system_clock::now();
    tStartGhosts = std::chrono::system_clock::now();
    (void)iObj;
    (void)iPlayer;
}

void ArcadeGame::Pacman::genStrMap()
{
    if (sMap.size() == 0) {
        sMap.push_back(".W..W...W..W..W...W.");
        sMap.push_back("...WW.WWW....WW.WWW.");
        sMap.push_back(".W..W....W*W..W....W");
        sMap.push_back("WWW....W.WWWW....W.W");
        sMap.push_back(".W..WW.W.W.W..WW.W.W");
        sMap.push_back(".W.....W...W.....W..");
        sMap.push_back(".W.WWWWW.....WWWWW.W");
        sMap.push_back(".W.................W");
        sMap.push_back("WWWWW.W.WWWWWWW.W.WW");
        sMap.push_back("..W...W.WGGGW...W*W.");
        sMap.push_back(".W..W.W.WGGGW.W...W.");
        sMap.push_back("...WW.W.WWWWW.W.WWW.");
        sMap.push_back(".W..W.....P...W....W");
        sMap.push_back("WWW....W.WWWW....W.W");
        sMap.push_back("*W..WW.W.W.W..WW.W.W");
        sMap.push_back(".W.....W...W.....W..");
        sMap.push_back(".W.WWWWW.W.W.WWWWW.W");
        sMap.push_back(".W.......W*W.......W");
        sMap.push_back("WWWWW.W.WWWWWWW.W.WW");
        sMap.push_back("..W...W.W...W...W.W.");
        MapXSize = 19;
        MapYSize = 19;
    }
}

void ArcadeGame::Pacman::genDisplay(char c, int x, int y, bool map)
{
    if (map && (c == 'W' || c == 'G')) {
        if (c == 'G') {
            sGhosts.push_back(initState.size());
            initState.push_back({" ", "", "", "./resources/textures/pacman/background.png", (cellSize * x), (cellSize * y), true});
        } else
            initState.push_back({"W", "", "", "./resources/textures/pacman/background_wall.png", (cellSize * x), (cellSize * y), true});
    } else if (map)
        initState.push_back({" ", "", "", "./resources/textures/pacman/background.png", (cellSize * x), (cellSize * y), true});
    else if (!map && (c == 'P' || c == '.' || c == '*' || c == 'G')) {
        if (iObj == 0)
            iObj = initState.size();
        if (c == 'P') {
            iPlayer = initState.size();
            initState.push_back({"P", "", "", "./resources/textures/pacman/pacman_right.png", (cellSize * x), (cellSize * y), true});
        } else if (c == '.') {
            initState.push_back({".", "", "", "./resources/textures/pacman/pacgums.png", (cellSize * x), (cellSize * y), true});
        } else if (c == '*') {
            initState.push_back({"*", "", "", "./resources/textures/pacman/big_pacgums.png", (cellSize * x), (cellSize * y), true});
        } else if (c == 'G') {
            iGhosts.push_back(initState.size());
            initState.push_back({"G", "", "", "./resources/textures/pacman/ghost1_right.png", (cellSize * x), (cellSize * y), true});
        }
    }
}

void ArcadeGame::Pacman::genLayerMap(char l, bool map)
{
    for (int y = 0;y <= MapYSize;y++) {
        for (int x = 0; x <= MapXSize;x++) {
            if (l == sMap[y][x] || map)
                genDisplay(sMap[y][x], x, y, map);
        }
    }
}

    //Class Methode
extern "C" Arcade::IGames *create()
{
    return (new ArcadeGame::Pacman());
}

extern "C" std::vector<display_t> &ArcadeGame::Pacman::getInitState()
{
    return (initState);
}

void ArcadeGame::Pacman::animate(unsigned int index, char input, std::string const &sPath)
{
    std::string format = ".png";

    if (index < map.size()) {
        if (input == 'z')
            map[index].image = sPath + "up" + format;
        else if (input == 's')
            map[index].image = sPath + "down" + format;
        else if (input == 'q')
            map[index].image = sPath + "left" + format;
        else if (input == 'd')
            map[index].image = sPath + "right" + format;
    }
}

bool ArcadeGame::Pacman::compareFloat(float one, float two)
{
    double res_abs = fabs(one - two);

    if (res_abs < 0.005f)
        return (true);
    else
        return (false);
}

void ArcadeGame::Pacman::moveObject(unsigned int iObj, char input)
{
    if (map.size() > iObj && input != -1) {
        if (input == 'z') {
            map[iObj].y -= cellSize;
            map[iObj].y = (map[iObj].y < -0.0000009f) ? 0.950000f : map[iObj].y;
        } else if (input == 's') {
            map[iObj].y += cellSize;
            map[iObj].y = (map[iObj].y > 0.9500009f) ? 0.000000f : map[iObj].y;
        } else if (input == 'q') {
            map[iObj].x -= cellSize;
            map[iObj].x = (map[iObj].x < -0.0000009f) ? 0.950000f : map[iObj].x;
        } else if (input == 'd') {
            map[iObj].x += cellSize;
            map[iObj].x = (map[iObj].x > 0.9500009f) ? 0.000000f : map[iObj].x;
        }
    }
}

unsigned int ArcadeGame::Pacman::collision(float x, float y, std::string const &obj)
{
    int size = map.size();

    x = (x < -0.0000009f) ? 0.950000f : x;
    x = (x > 0.9500009f) ? 0.000000f : x;
    y = (y < -0.0000009f) ? 0.950000f : y;
    y = (y > 0.9500009f) ? 0.000000f : y;
    for (int i = 0;i < size;i++) {
        if (map[i].ascii.compare(obj) == 0 && compareFloat(map[i].x, x) && compareFloat(map[i].y, y))
            return (i);
    }
    return (0);
}

unsigned int ArcadeGame::Pacman::pacgumsLeft()
{
    unsigned int size = map.size();
    unsigned int pLeft = 0;

    for (unsigned int i = 0;i < size;i++) {
        if ((map[i].ascii.compare(".") == 0 || map[i].ascii.compare("*") == 0) && map[i].isPrint)
            pLeft++;
    }
    return (pLeft);
}

unsigned int ArcadeGame::Pacman::isInStartGhost(unsigned int iGhost)
{
    unsigned int size = sGhosts.size();

    for (unsigned int i = 0;i < size;i++) {
        if (sGhosts[i] < map.size() && compareFloat(map[iGhost].x, map[sGhosts[i]].x) && compareFloat(map[iGhost].y, map[sGhosts[i]].y))
            return (sGhosts[i]);
    }
    return (0);
}

void ArcadeGame::Pacman::possibleMoveGhost(unsigned int iGhost, std::string &mv)
{
    mv.clear();
    if (!collision(map[iGhost].x, map[iGhost].y - cellSize, "W"))
        mv += "z";
    if (!collision(map[iGhost].x, map[iGhost].y + cellSize, "W"))
        mv += "s";
    if (!collision(map[iGhost].x - cellSize, map[iGhost].y, "W"))
        mv += "q";
    if (!collision(map[iGhost].x + cellSize, map[iGhost].y, "W"))
        mv += "d";
}

void ArcadeGame::Pacman::moveGhosts()
{
    std::string mv = "zqsd";
    std::chrono::time_point<std::chrono::system_clock> pTime;
    std::chrono::time_point<std::chrono::system_clock> pTDeath;
    int elapsedSeconds = 0;
    int elapsedDeath = 0;
    char choseMv = -1;
    unsigned int size = iGhosts.size();
    int randS = 0;

    pTime = std::chrono::system_clock::now();
    elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(pTime - tStartGhosts).count();
    for (unsigned int i = 0;i < size;i++) {
        choseMv = -1;
        if (elapsedSeconds <= 10) {
            choseMv = mv[std::rand() % mv.size()];
        } else if (iGhosts[i] < map.size() && !map[iGhosts[i]].isPrint) {
            randS = std::rand() % sGhosts.size();
            map[iGhosts[i]].x = map[sGhosts[randS]].x;
            map[iGhosts[i]].y = map[sGhosts[randS]].y;
            map[iGhosts[i]].image = "./resources/textures/pacman/ghost1_dead.png";
            map[iGhosts[i]].isPrint = true;
            tDeathGhost = std::chrono::system_clock::now();
        } else if (isInStartGhost(iGhosts[i]) && iGhosts[i] < map.size()) {
            if (map[iGhosts[i]].image == "./resources/textures/pacman/ghost1_dead.png") {
                pTDeath = std::chrono::system_clock::now();
                elapsedDeath = std::chrono::duration_cast<std::chrono::seconds>(pTDeath - tDeathGhost).count();
                if (elapsedDeath > 3)
                    choseMv = mv[0];
            } else {
                map[iGhosts[i]].y -= (cellSize * 3);
                choseMv = mv[0];
            }
        } else if (!isInStartGhost(iGhosts[i]) && iGhosts[i] < map.size()) {
            possibleMoveGhost(iGhosts[i], mv);
            choseMv = mv[std::rand() % mv.size()];
            moveObject(iGhosts[i], choseMv);
        }
        if (powerUp) {
            animate(iGhosts[i], choseMv, "./resources/textures/pacman/ghost1_");
        } else 
            animate(iGhosts[i], choseMv, "./resources/textures/pacman/ghost2_");
    }
}

void ArcadeGame::Pacman::updateEffect()
{
    unsigned int size = map.size();
    unsigned int col = 0;
    int elapsedT = 0;
    std::chrono::time_point<std::chrono::system_clock> pUpTime;


    if (iPlayer < size) {
        if (powerUp) {
            pUpTime = std::chrono::system_clock::now();
            elapsedT = std::chrono::duration_cast<std::chrono::seconds>(pUpTime - tStartPUp).count();
            if (elapsedT > 10)
                powerUp = false;
        }
        if ((col = collision(map[iPlayer].x, map[iPlayer].y, "G")) > 0 && col < size && map[col].isPrint) {
            if (powerUp)
                map[col].isPrint = false;
            else  {
                tDeathPacman = std::chrono::system_clock::now();
                dying = true;
            }
        }
        moveGhosts();
        if ((col = collision(map[iPlayer].x, map[iPlayer].y, "G")) > 0 && col < size && map[col].isPrint) {
            if (powerUp)
                map[col].isPrint = false;
            else  {
                tDeathPacman = std::chrono::system_clock::now();
                dying = true;
            }
        }
        if ((col = collision(map[iPlayer].x, map[iPlayer].y, ".")) > 0 && col < size && map[col].isPrint) {
            map[col].isPrint = false;
            score += 2;
        } else if ((col = collision(map[iPlayer].x, map[iPlayer].y, "*")) > 0 && col < size && map[col].isPrint) {
            map[col].isPrint = false;
            tStartPUp = std::chrono::system_clock::now();
            powerUp = true;
            score += 6;
        }
        if (gameFinish == Arcade::statusGame::INGAME && !pacgumsLeft())
            gameFinish = Arcade::statusGame::WIN;
    }
}

extern "C" void ArcadeGame::Pacman::move(char input)
{
    std::chrono::time_point<std::chrono::system_clock> deathTime;
    int elapsedDeath = 0;

    if(gameFinish != Arcade::statusGame::INGAME)
        return;
    if (dying) {
        deathTime = std::chrono::system_clock::now();
        elapsedDeath = std::chrono::duration_cast<std::chrono::seconds>(deathTime- tDeathPacman).count();
        if (elapsedDeath > 2)
            gameFinish = Arcade::statusGame::LOSE;
        return;
    }
    if ((map.size() - 1) >= iPlayer && input != -1) {
        if (input == 'z' && !collision(map[iPlayer].x, map[iPlayer].y - cellSize, "W")) {
            moveObject(iPlayer, input);
        } else if (input == 's' && !collision(map[iPlayer].x, map[iPlayer].y + cellSize, "W")) {
            moveObject(iPlayer, input);
        } else if (input == 'q' && !collision(map[iPlayer].x - cellSize, map[iPlayer].y, "W")) {
            moveObject(iPlayer, input);
        } else if (input == 'd' && !collision(map[iPlayer].x + cellSize, map[iPlayer].y, "W")) {
            moveObject(iPlayer, input);
        }
        animate(iPlayer, input, "./resources/textures/pacman/pacman_");
    }
    updateEffect();
}

extern "C" std::vector<display_t> &ArcadeGame::Pacman::getState()
{
    return ((map));
}

extern "C" uint64_t ArcadeGame::Pacman::getScore()
{
    return (score);
}

extern "C" Arcade::statusGame &ArcadeGame::Pacman::getStatus()
{
    return (gameFinish);
}

extern "C" void ArcadeGame::Pacman::restart()
{
    std::srand(std::time(nullptr));
    map = initState;
    gameFinish = Arcade::statusGame::INGAME;
    score = 0;
}

bool ArcadeGame::Pacman::speedGame()
{
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - timeStart).count();
    if (elapsed_seconds >= (450 - (score * 0.1))) {
        timeStart = std::chrono::system_clock::now();
        return true;
    }
    return false;
}