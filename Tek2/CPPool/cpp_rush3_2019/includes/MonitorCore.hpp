/*
** EPITECH PROJECT, 2020
** MonitorCore
** File description:
** MonitoreCore
*/

#ifndef MONITORCORE_H
#define MONITORCORE_H

#include <vector>
#include <string>
#include "IMonitorModule.hpp"

class MonitorCore {
	public:
		MonitorCore();
		virtual ~MonitorCore();

        void setModule(IMonitorModule *module);
		std::vector<IMonitorModule *> getModules() const;
		IMonitorModule *getModule(std::string const &name) const;
		IMonitorModule *unSetModule(std::string const &name);
		static std::vector<MonitorCore> setCores();

	protected:
	private:
		std::vector<IMonitorModule *> _modules;
};

#endif /* !MONITORCORE */
