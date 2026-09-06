/*
** EPITECH PROJECT, 2020
** IMonitorDisplay
** File description:
** IMonitorDisplay
*/

#ifndef IMonitorDisplay_HPP
#define IMonitorDisplay_HPP

class IMonitorDisplay {
	public:
		virtual ~IMonitorDisplay() = default;

		virtual int launch() = 0;
    protected:
	private:
};

#endif /* !IMonitorDisplay */
