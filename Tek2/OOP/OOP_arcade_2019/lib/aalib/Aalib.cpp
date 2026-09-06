/*
** EPITECH PROJECT, 2020
** Aalib
** File description:
** Aalib
*/

#include "Aalib.hpp"

    //Constructor
ArcadeLib::Aalib::Aalib()
{
    aa_defparams.height = 65;
    aa_defparams.width = 175;
    context = aa_autoinit(&aa_defparams);
    timeStart = std::chrono::system_clock::now();
    if (!context)
        throw 0;
    if (!aa_autoinitkbd(context, 0)) {
        std::cerr << "Can not intialize keyboard" << std::endl;
        aa_close(context);
        throw 0;
    }
}

    //Class Methode
extern "C" Arcade::IGraphics *create()
{
    return (new ArcadeLib::Aalib());
}

extern "C" char ArcadeLib::Aalib::getEvent() 
{
    int value = aa_getevent(context, 0);
    // aa_getkey(c, 1);

    if (value != ' ') {
        if ((value >= 'a' && value <= 'z') || (value == '\n') ||  (value == 27) || (value >= '1' && value <= '9'))
            return (value);
        switch (value) {
            case 305: return (27);
            case 38: return ('1');
            case -23: return ('2');
            case 34: return ('3');
            case 39: return ('4');
            case 40: return ('5');
            case 45: return ('6');
            case -24: return ('7');
            case 95: return ('8');
            case -25: return ('9');
            default: return(-1);
        }
    }
    return (-1);
}

extern "C" void ArcadeLib::Aalib::print(display_t &display) 
{
    if (!display.isPrint)
        return;
    if (display.ascii != "") {
        aa_puts(context, display.x * 3.5, display.y / 2.8, AA_NORMAL, display.ascii.c_str());
    }
}

extern "C" void ArcadeLib::Aalib::destructor() 
{
    aa_close(context);
}

extern "C" void ArcadeLib::Aalib::refresh() 
{
    aa_flush(context);
    int height = getWindowHeight();
    int width = getWindowWidth();
    for (int i = 0; i < height; i++) {
        for (int index = 0; index < width; index++) {
            aa_puts(context, i, index, AA_NORMAL, " ");
        }
    }
}

extern "C" bool ArcadeLib::Aalib::clockDisplay()
{
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - timeStart).count();
    if (elapsed_seconds >= 1) {
        timeStart = std::chrono::system_clock::now();
        return true;
    }
    return false;
}

extern "C" int ArcadeLib::Aalib::getWindowHeight()
{
    int x = 0;
    int y = 0;

    context->driver->getsize(context, &x, &y);
    return (x);
}

extern "C" int ArcadeLib::Aalib::getWindowWidth()
{
    int x = 0;
    int y = 0;

    context->driver->getsize(context, &x, &y);
    return (y);
}