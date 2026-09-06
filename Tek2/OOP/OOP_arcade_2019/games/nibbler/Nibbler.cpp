/*
** EPITECH PROJECT, 2020
** Nibbler
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

    //Constructor
ArcadeGame::Nibbler::Nibbler()
{
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            initState.push_back({" ", "", "", "./resources/textures/nibbler/background.png", (x * 0.1f), (y * 0.1f), true});
        }
    }
    std::srand(std::time(nullptr));
    initState.push_back({"#", "", "", "./resources/textures/nibbler/fruit.png", ((std::rand() % 4) * 0.1f), ((std::rand() % 9) * 0.1f), true}); // [99] == nbrBoardElement
    initState.push_back({"o", "", "", "./resources/textures/nibbler/head_up.png", 0.5, 0.3, true});
    initState.push_back({"|", "", "", "./resources/textures/nibbler/body_up.png", 0.5, 0.4, true});
    initState.push_back({"|", "", "", "./resources/textures/nibbler/body_up.png", 0.5, 0.5, true});
    initState.push_back({"|", "", "", "./resources/textures/nibbler/body_up.png", 0.5, 0.6, true});
    map = initState;
    lastDirection = 'z';
    score = 0;
    gameFinish = Arcade::statusGame::INGAME;
    timeStart = std::chrono::system_clock::now();
}


    //Class Methode
extern "C" Arcade::IGames *create()
{
    return (new ArcadeGame::Nibbler());
}

extern "C" std::vector<display_t> &ArcadeGame::Nibbler::getInitState()
{
    return (managementSamePosition(initState));
}

void ArcadeGame::Nibbler::snakeNewPosition(float *x, float *y, char input)
{
    if ((input == 's' && lastDirection == 'z') || (input == 'd' && lastDirection == 'q') || (input == 'q' && lastDirection == 'd')
        || (input == 'z' && lastDirection == 's')) {
        snakeNewPosition(x, y, lastDirection);
        return;
    }
    if (input == 'z') {
        *y -= 0.1f;
        lastDirection = 'z';
    } else if (input == 's') {
        *y += 0.1f;
        lastDirection = 's';
    } else if (input == 'q') {
        *x -= 0.1f;
        lastDirection = 'q';
    } else if (input == 'd') {
        *x += 0.1f;
        lastDirection = 'd';
    } else if (input == -1) {
        snakeNewPosition(x, y, lastDirection);
    } else {
        *x = -10.0f;
        *y = -10.0f;
    }
}

bool ArcadeGame::Nibbler::checkVoidCell(float x, float y)
{
    if (x < 0 || y < 0 || x >= 1 || y >= 1)
        return (false);
    for (size_t index = indexFruit; index < (map.size()); index++) {
        if (compareFloat(map[index].x, x) &&
            compareFloat(map[index].y, y))
            return (false);
    }
    return (true);
}

void ArcadeGame::Nibbler::snakeGrowUp()
{
    float x = map[map.size()].x;
    float y = map[map.size()].y;

    if (checkVoidCell(x + 0.1f, y)) {
        map.push_back({"|", "", "", "", (x + 0.1f), y, true});
    } else if (checkVoidCell(x, y + 0.1f)) {
        map.push_back({"|", "", "", "", x, (y + 0.1f), true});
    } else if (checkVoidCell(x - 0.1f, y)) {
        map.push_back({"|", "", "", "", (x - 0.1f), y, true});
    } else if (checkVoidCell(x, y - 0.1f)) {
        map.push_back({"|", "", "", "", x, (y - 0.1f), true});
    } else {
        gameFinish = Arcade::statusGame::LOSE;
    }
}

void ArcadeGame::Nibbler::spawnNewFruit()
{
    float x = 0;
    float y = 0;

    for (int count = 0; count < 50; count++) {
        x = ((std::rand() % 9) * 0.1f);
        y = ((std::rand() % 9) * 0.1f);
        if (checkVoidCell(x, y)) {
            map[indexFruit].x = x;
            map[indexFruit].y = y;
            return;
        }
    }
    for (int index = 0; index < nbrBoardElement; index++) {
        if (checkVoidCell(map[index].x, map[index].y)) {
            map[indexFruit].x = map[index].x;
            map[indexFruit].y = map[index].y;
            return;
        }
    }
    gameFinish = Arcade::statusGame::LOSE;
}

ArcadeGame::entityOrientation ArcadeGame::Nibbler::findOrientation(float xOne, float yOne, float xTwo, float yTwo)
{
    if (compareFloat(xOne, xTwo)) {
        if (yTwo > yOne) {
            return (ArcadeGame::entityOrientation::UP);
        } else {
            return (ArcadeGame::entityOrientation::DOWN);
        }
    } else {
        if (xTwo > xOne) {
            return (ArcadeGame::entityOrientation::LEFT);
        } else {
            return (ArcadeGame::entityOrientation::RIGHT);
        }
    }
}

std::string ArcadeGame::Nibbler::asciiOrientation(ArcadeGame::entityOrientation orientation, bool headSnake)
{
    if (headSnake) {
        return ("o");
    }
    if (orientation == UP || orientation == DOWN)
        return ("|");
    return ("-");    
}


std::string ArcadeGame::Nibbler::spriteOrientation(ArcadeGame::entityOrientation orientation, int specialCase)
{
    static ArcadeGame::entityOrientation test = UP;

    if (specialCase == 1) {
        if (test == orientation) {
            test = orientation;
            switch (orientation) {
                case UP: return ("./resources/textures/nibbler/body_up.png");
                case DOWN: return ("./resources/textures/nibbler/body_down.png");
                case LEFT: return ("./resources/textures/nibbler/body_left.png");
                case RIGHT: return ("./resources/textures/nibbler/body_right.png");
                default: return ("");
            }
        } else {
            if ((orientation == UP && test == LEFT) || (orientation == RIGHT && test == DOWN)) {
                test = orientation;
                return ("./resources/textures/nibbler/left_down.png");
            }
            if ((orientation == DOWN && test == LEFT) || (orientation == RIGHT && test == UP)) {
                test = orientation;
                return ("./resources/textures/nibbler/left_up.png");
            }
            if ((orientation == UP && test == RIGHT) || (orientation == LEFT && test == DOWN)) {
                test = orientation;
                return ("./resources/textures/nibbler/right_down.png");
            }
            if ((orientation == DOWN && test == RIGHT) || (orientation == LEFT && test == UP)) {
                test = orientation;
                return ("./resources/textures/nibbler/right_up.png");
            }
        }
    }
    else if (specialCase == 0) {
        test = orientation;
        switch (orientation) {
            case DOWN: return ("./resources/textures/nibbler/head_up.png");
            case UP: return ("./resources/textures/nibbler/head_down.png");
            case RIGHT: return ("./resources/textures/nibbler/head_left.png");
            case LEFT: return ("./resources/textures/nibbler/head_right.png");
            default: return ("");
        }
    }
    else if (specialCase == 2) {
        switch (test) {
            case UP: return ("./resources/textures/nibbler/tail_up.png");
            case DOWN: return ("./resources/textures/nibbler/tail_down.png");
            case LEFT: return ("./resources/textures/nibbler/tail_left.png");
            case RIGHT: return ("./resources/textures/nibbler/tail_right.png");
            default: return ("");
        }
    }
    return ("");
}

void ArcadeGame::Nibbler::changePositionSnake(float headX, float headY)
{
    float x = 0;
    float y = 0;
    ArcadeGame::entityOrientation orientation = ArcadeGame::entityOrientation::UP;

    tmp = map;
    for (size_t index = indexHeadSnake; index < (map.size()); index++) {
        x = index == indexHeadSnake ? headX : map[index - 1].x;
        y = index == indexHeadSnake ? headY : map[index - 1].y;
        orientation = findOrientation(x, y, map[index].x, map[index].y);
        if (index == indexHeadSnake)
            tmp[index] = {asciiOrientation(orientation, true), "", "", spriteOrientation(orientation, 0), x, y, true};
        else if (index + 1 == map.size())
            tmp[index] = {asciiOrientation(orientation, false), "", "", spriteOrientation(orientation, 2), x, y, true};
        else
            tmp[index] = {asciiOrientation(orientation, false), "", "", spriteOrientation(orientation, 1), x, y, true};
    }
    map = tmp;
}

bool ArcadeGame::Nibbler::compareFloat(float one, float two)
{
    double res_abs = fabs(one - two);

    if (res_abs < 0.05f)
        return (true);
    else
        return (false);
}

extern "C" void ArcadeGame::Nibbler::move(char input)
{
    float x = map[indexHeadSnake].x;
    float y = map[indexHeadSnake].y;

    if(gameFinish != Arcade::statusGame::INGAME)
        return;
    snakeNewPosition(&x, &y, input);
    if ((x == -10.0f && y == -10.0f) || (compareFloat(map[indexFirstTailSnake].x, x) &&
        compareFloat(map[indexFirstTailSnake].y, y))) {
        return;
    }
    if (compareFloat(map[indexFruit].x, x) && compareFloat(map[indexFruit].y, y)) {
        score += 25;
        snakeGrowUp();
        spawnNewFruit();
    }
    if (!checkVoidCell(x, y)) {
        gameFinish = Arcade::statusGame::LOSE;
        return;
    }
    changePositionSnake(x, y);
}

extern "C" std::vector<display_t> &ArcadeGame::Nibbler::getState()
{
    return ((map));
}

extern "C" uint64_t ArcadeGame::Nibbler::getScore()
{
    return (score);
}

extern "C" Arcade::statusGame &ArcadeGame::Nibbler::getStatus()
{
    return (gameFinish);
}

extern "C" void ArcadeGame::Nibbler::restart()
{
    std::srand(std::time(nullptr));
    map = initState;
    tmp = initState;
    gameFinish = Arcade::statusGame::INGAME;
    score = 0;
    lastDirection = 'z';
}

std::vector<display_t> &ArcadeGame::Nibbler::managementSamePosition(std::vector<display_t> &list)
{
    tmp = list;
    for (size_t start = list.size(); start >= nbrBoardElement; start--) {
        for (size_t index = 0; index < nbrBoardElement; index++) {
            if (tmp[index].isPrint && compareFloat(list[start].x, tmp[index].x)
                && compareFloat(list[start].y, tmp[index].y)) {
                tmp[index].isPrint = false;
            }
        }
    }
    return (tmp);
}

bool ArcadeGame::Nibbler::speedGame()
{
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - timeStart).count();
    if (elapsed_seconds >= (450 - (score * 0.3))) {
        timeStart = std::chrono::system_clock::now();
        return true;
    }
    return false;
}