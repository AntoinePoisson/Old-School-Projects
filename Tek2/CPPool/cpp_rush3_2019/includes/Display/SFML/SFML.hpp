/*
** EPITECH PROJECT, 2020
** SFML
** File description:
** SFML
*/

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include "MonitorCore.hpp"
#include "IMonitorDisplay.hpp"
#include "Modules/DateTime.hpp"
#include "Modules/HostUserName.hpp"
#include "Modules/Module.hpp"
#include "Modules/RAM.hpp"
#include "Modules/CPU.hpp"
#include "Modules/OperatingSysKer.hpp"

class SFML : public IMonitorDisplay {
	public:
		explicit SFML(std::vector<MonitorCore> core_list, int height, int width, std::string title);
		~SFML();

		int launch();
		int initialization();


	protected:
	private:
		int MainLoop();
		void DisplayCore();
		void callModule(IMonitorModule *type);
		void DisplayOneModule();

		void DisplayDateTime(std::vector<std::string> const &data);
		void DisplayHostUserName(std::vector<std::string> const &data);
		void DisplayOperatingSysKer(std::vector<std::string> const &data);
		void DisplayRAM(std::vector<std::string> const &data);
		void DisplayCPU(std::vector<std::string> const &data);

		int _wight_core;
		int _height_core;
		std::vector<MonitorCore> _core_list;
		sf::RenderWindow _window;
		sf::Event _event;
		sf::Time _time;
		sf::Clock _clock;
		sf::Vector2f _posi;
		sf::Text _text;
		sf::Font _font;
};

#endif /* !SFML_HPP */
