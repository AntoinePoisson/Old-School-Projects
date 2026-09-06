/*
** EPITECH PROJECT, 2020
** IMonitorModule
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE
#define IMONITORMODULE

#include <string>
#include <vector>

class IMonitorModule {
	public:
		virtual ~IMonitorModule() = default;

        virtual void refreshData() = 0;
        virtual std::vector<std::string> const &getData() = 0;
        virtual std::vector<std::string> const &getRefreshData() = 0;
        virtual void setName(std::string const &name) = 0;
        virtual std::string const &getName() = 0;
	protected:
	private:
};

#endif /* !IMONITORMODULE */
