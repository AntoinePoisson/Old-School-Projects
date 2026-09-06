/*
** EPITECH PROJECT, 2020
** MonitorCore
** File description:
** MonitorCore
*/

#include "MonitorCore.hpp"
#include "Modules/DateTime.hpp"
#include "Modules/HostUserName.hpp"
#include "Modules/OperatingSysKer.hpp"
#include "Modules/RAM.hpp"
#include "Modules/CPU.hpp"

MonitorCore::MonitorCore()
{
}

MonitorCore::~MonitorCore()
{
}

void MonitorCore::setModule(IMonitorModule *module)
{
    int size = _modules.size();

    for (int i = 0;i < size;i++)
        if (module->getName() == _modules[i]->getName())
            return ;
    _modules.push_back(module);
}

std::vector<IMonitorModule *> MonitorCore::getModules() const
{
    return (_modules);
}

IMonitorModule *MonitorCore::getModule(std::string const &name) const
{
    int size = _modules.size();
    for (int i = 0;i < size;i++)
        if (_modules[i]->getName() == name)
            return (_modules[i]);
    return (nullptr);
}

IMonitorModule *MonitorCore::unSetModule(std::string const &name)
{
    IMonitorModule *temp = nullptr;
    for (std::vector<IMonitorModule *>::iterator it = _modules.begin();it != _modules.end();it++) {
        if ((*it)->getName() == name) {  
            temp = *it;
            _modules.erase(it);
            return (temp);
        }
    }
    return (nullptr);
}

std::vector<MonitorCore> MonitorCore::setCores()
{
    std::vector<MonitorCore> cores;
    MonitorCore core1;
    MonitorCore core2;
    IMonitorModule *mod1 = new HostUserName("Host");
    IMonitorModule *mod2 = new OperatingSysKer("System");
    IMonitorModule *mod3 = new DateTime("Date");
    IMonitorModule *mod4 = new RAM("RAM");
    IMonitorModule *mod5 = new CPU("cpu");
    core1.setModule(mod1);
    core1.setModule(mod2);
    core1.setModule(mod3);
    core1.setModule(mod4);
    core1.setModule(mod5);
    core2 = core1;
    cores.push_back(core1);
    // cores.push_back(core2);
    return (cores);
}