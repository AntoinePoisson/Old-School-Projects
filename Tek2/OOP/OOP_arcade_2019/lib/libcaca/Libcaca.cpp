/*
** EPITECH PROJECT, 2020
** Libcaca
** File description:
** Libcaca
*/

#include "Libcaca.hpp"

    //Constructor
ArcadeLib::Libcaca::Libcaca()
    : canvas(NULL), window(NULL)
{
    canvas = caca_create_canvas(170, 55);
    if (!canvas)
        throw 0;
    window = caca_create_display(canvas);
    if (!window)
        throw 0;
    caca_set_display_title(window, "Arcacade");
    caca_set_color_ansi(canvas, CACA_BLACK, CACA_WHITE);
    caca_set_display_time(window, 30);
    timeStart = std::chrono::system_clock::now();
}

    //Class Methode
extern "C" Arcade::IGraphics *create()
{
    return (new ArcadeLib::Libcaca());
}

extern "C" char ArcadeLib::Libcaca::getEvent() 
{
    caca_get_event(window, CACA_EVENT_QUIT, &event, 1000);
    if (caca_get_event_type(&event) == CACA_EVENT_QUIT)
        return (0);
    caca_get_event(window, CACA_EVENT_KEY_PRESS, &event, 1000);
    if (caca_get_event_type(&event) == CACA_EVENT_KEY_PRESS) {
        char value = caca_get_event_key_ch(&event);
        if ((value >= 'a' && value <= 'z') || (value == '\n') ||  (value == 27) || (value >= '1' && value <= '9'))
            return (value);
        switch (value) {
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

extern "C" void ArcadeLib::Libcaca::print(display_t &display) 
{
    if (!display.isPrint)
        return;
    if (display.ascii != "") {
        canvas = caca_get_canvas(window);
        caca_put_str(canvas, display.x * 1 / 7, display.y * 1 / 17, display.ascii.c_str());
    }
}

extern "C" bool ArcadeLib::Libcaca::clockDisplay()
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

extern "C" void ArcadeLib::Libcaca::destructor() 
{
    caca_free_display(window);
    caca_free_canvas(canvas);
}

extern "C" void ArcadeLib::Libcaca::refresh() 
{
    caca_refresh_display(window);
    caca_clear_canvas(canvas);
}

extern "C" int ArcadeLib::Libcaca::getWindowHeight()
{
    return (caca_get_display_height(window));
}

extern "C" int ArcadeLib::Libcaca::getWindowWidth()
{
    return (caca_get_display_width(window));
}