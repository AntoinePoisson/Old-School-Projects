/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** ISocket
*/

#ifndef ISOCKET_H_
#define ISOCKET_H_

#include <QApplication>
#include <QObject>
#include <QWidget>

#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>

#include <QSignalMapper>
#include <QtWidgets>
#include <QtNetwork>
#include <QTcpSocket>
#include <vector>
#include "DataClient.h"

namespace babel
{
    class ISocket
    {
        public:
        virtual ~ISocket() = default;
        virtual void connectSocket(const DataClient &) = 0;

    };
}

#endif /* !ISOCKET_H_ */
