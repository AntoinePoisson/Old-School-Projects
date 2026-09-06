/*
** EPITECH PROJECT, 2020
** main
** File description:
** main_sfml
*/

#include "Display/SFML/SFML.hpp"

SFML::SFML(std::vector<MonitorCore> core_list, int height, int width, std::string title)
: _core_list(core_list), _window(sf::VideoMode(height, width), title, sf::Style::Titlebar | sf::Style::Close)
{
    int size = core_list.size();
    int size_height = 1;

    for (int i = 0; i < size; i++)
        if (size_height < core_list[i].getModules().size())
            size_height = core_list[i].getModules().size();
    _wight_core = 250;
    _height_core = 170;
}

SFML::~SFML()
{
}

int SFML::initialization()
{
    _window.setFramerateLimit(60);
    if (!_font.loadFromFile("./src/font/Arial.ttf")) {
        exit(84);
    }
    _text.setCharacterSize(20);
    _text.setFont(_font);
    _posi.x = 10;
    _posi.y = 10;
    _window.draw(_text);
    return (0);
}

void SFML::DisplayDateTime(std::vector<std::string> const &data)
{
    _text.setFont(_font);
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setSize(sf::Vector2f(250, 170));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(_posi);
    _window.draw(rectangle);
    _text.setString("Date & Time:");
    _text.setPosition(sf::Vector2f(_posi.x + 70, _posi.y + 40));
    _window.draw(_text);
    _text.setString(data[0]);
    _text.setPosition(sf::Vector2f(_posi.x + 50, _posi.y + 70));
    _window.draw(_text);
    _text.setFont(_font);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(sf::Vector2f(_posi.x + 85, _posi.y + 100));    
    _text.setString(data[1]);
    _window.draw(_text);
}

void SFML::DisplayHostUserName(std::vector<std::string> const &data)
{
    _text.setFont(_font);
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setSize(sf::Vector2f(250, 170));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(_posi);
    _window.draw(rectangle);
    _text.setString("HostUser & Name:");
    _text.setPosition(sf::Vector2f(_posi.x + 50, _posi.y + 35));
    _window.draw(_text);

    _text.setString(data[0]);
    _text.setPosition(sf::Vector2f(_posi.x + 40, _posi.y + 70));
    _window.draw(_text);
    _text.setFont(_font);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(sf::Vector2f(_posi.x + 40, _posi.y + 100));    
    _text.setString(data[1]);
    _window.draw(_text);
}

void SFML::DisplayOperatingSysKer(std::vector<std::string> const &data)
{
    _text.setFont(_font);
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setSize(sf::Vector2f(250, 170));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(_posi);
    _window.draw(rectangle);
    _text.setString("Operating System & Kern:");
    _text.setPosition(sf::Vector2f(_posi.x + 10, _posi.y + 25));
    _window.draw(_text);
    _text.setString(data[1]);
    _text.setPosition(sf::Vector2f(_posi.x + 20, _posi.y + 60));
    _window.draw(_text);
    _text.setFont(_font);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(sf::Vector2f(_posi.x + 20, _posi.y + 90));    
    _text.setString(data[0]);
    _window.draw(_text);
}

void SFML::DisplayRAM(std::vector<std::string> const &data)
{
    _text.setFont(_font);
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setSize(sf::Vector2f(250, 170));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(_posi);
    _window.draw(rectangle);
    if (data[0].length() == 17)
        _text.setString("Size RAM : " + data[0].substr(0, 1) + " Go");
    else if (data[0].length() == 18)
        _text.setString("Size RAM : " + data[0].substr(0, 2) + " Go");
    else
        _text.setString("Size RAM : ?? Go");
    _text.setPosition(sf::Vector2f(_posi.x + 50, _posi.y + 60));
    _window.draw(_text);
    _text.setFont(_font);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(sf::Vector2f(_posi.x + 50, _posi.y + 90));    
    _text.setString("Used RAM: "+ data[1].substr(0, 2) + "%");
    _window.draw(_text);
}

void SFML::DisplayCPU(std::vector<std::string> const &data)
{
    _text.setFont(_font);
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setSize(sf::Vector2f(250, 170));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(_posi);
    _window.draw(rectangle);


    std::string pourcent = "0%";
    int pct = 0;

    if (stoi(data[2]) > 0) {
        pourcent = data[2] + "%";
        pct = stoi(data[2]);
    }
    rectangle.setSize(sf::Vector2f(90, -(140 * pct / 100)));
    if (pct > 80)
        rectangle.setFillColor(sf::Color::Red);
    else if (pct > 50)
        rectangle.setFillColor(sf::Color::Yellow);
    else
        rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(sf::Vector2f(_posi.x + 150, _posi.y + 145));
    _window.draw(rectangle);

    _text.setString("CPU: " + pourcent);
    _text.setPosition(sf::Vector2f(_posi.x + 20, _posi.y + 60));
    _window.draw(_text);
}

void SFML::callModule(IMonitorModule *type)
{
    if (dynamic_cast<DateTime*> (type) != nullptr) {
        DisplayDateTime(type->getRefreshData());
    } else if (dynamic_cast<HostUserName*> (type) != nullptr) {
        DisplayHostUserName(type->getRefreshData());
    } else if (dynamic_cast<OperatingSysKer*> (type) != nullptr) {
        DisplayOperatingSysKer(type->getRefreshData());
    } else if (dynamic_cast<RAM*> (type) != nullptr) {
        DisplayRAM(type->getRefreshData());
    } else if (dynamic_cast<CPU*> (type) != nullptr) {
        DisplayCPU(type->getRefreshData());
    }
}

void SFML::DisplayCore()
{
    _posi.x = 0;
    _posi.y = 0;
    std::vector<IMonitorModule *> element;
    for (unsigned int i = 0; i < _core_list.size(); i++) {
        element = _core_list[i].getModules();
        _posi.y = 0;
        for (unsigned int count = 0; count < element.size(); count++) {
            callModule(element[count]);
            _posi.y += 200;
        }
        _posi.x += 270;
    }
}


int SFML::MainLoop()
{
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
        }
        _time = _clock.getElapsedTime();
        if (_time.asSeconds() >= 1) {
            _window.clear(sf::Color(0, 0, 0, 255));
            DisplayCore();
            _clock.restart();
        }
        _window.setActive();
        _window.display();
    }
    return (0);
}

int SFML::launch()
{
    initialization();
    return (MainLoop());
}