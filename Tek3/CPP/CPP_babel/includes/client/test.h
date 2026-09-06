/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TEST_H
#define TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_APP
{
public:
    QPushButton *BLogout;
    QLineEdit *SearchRelation;
    QPushButton *BRelation;
    QPushButton *BAccept;
    QPushButton *BRefuse;
    QPushButton *BCall;
    QPushButton *BAcceptCall;
    QPushButton *BRefuseCall;
    QPushButton *BRefresh;

    void setupUi(QWidget *APP)
    {
        if (APP->objectName().isEmpty())
            APP->setObjectName(QStringLiteral("APP"));
        APP->resize(1124, 851);

        BLogout = new QPushButton(APP);
        BLogout->setObjectName(QStringLiteral("BLogout"));
        BLogout->setGeometry(QRect(30, 30, 121, 21));

        SearchRelation = new QLineEdit(APP);
        SearchRelation->setObjectName(QStringLiteral("SearchRelation"));
        SearchRelation->setGeometry(QRect(860, 30, 221, 31));

        BRelation = new QPushButton(APP);
        BRelation->setObjectName(QStringLiteral("BRelation"));
        BRelation->setGeometry(QRect(350, 50, 150, 75));

        BRefresh = new QPushButton(APP);
        BRefresh->setObjectName(QStringLiteral("BRefresh"));
        BRefresh->setGeometry(QRect(200, 30, 121, 21));

        BAccept = new QPushButton(BRelation);
        BAccept->setObjectName(QStringLiteral("BAccept"));
        BAccept->setGeometry(QRect(5, 55, 45, 15));

        BRefuse = new QPushButton(BRelation);
        BRefuse->setObjectName(QStringLiteral("BRefuse"));
        BRefuse->setGeometry(QRect(100, 55, 45, 15));

        BCall = new QPushButton(APP);
        BCall->setObjectName(QStringLiteral("BCall"));
        BCall->setGeometry(QRect(550, 50, 150, 75));

        BAcceptCall = new QPushButton(BCall);
        BAcceptCall->setObjectName(QStringLiteral("BAcceptCall"));
        BAcceptCall->setGeometry(QRect(5, 55, 45, 15));

        BRefuseCall = new QPushButton(BCall);
        BRefuseCall->setObjectName(QStringLiteral("BRefuseCall"));
        BRefuseCall->setGeometry(QRect(100, 55, 45, 15));


        retranslateUi(APP);

        QMetaObject::connectSlotsByName(APP);
    } // setupUi

    void retranslateUi(QWidget *APP)
    {
        APP->setWindowTitle(QApplication::translate("APP", "Form", nullptr));
        BLogout->setText(QApplication::translate("APP", "Logout", nullptr));

        BAccept->setText(QApplication::translate("APP", "Accept", nullptr));
        BRefuse->setText(QApplication::translate("APP", "Refuse", nullptr));

        BAcceptCall->setText(QApplication::translate("APP", "Accept", nullptr));
        BRefuseCall->setText(QApplication::translate("APP", "Refuse", nullptr));

        BRefresh->setText(QApplication::translate("APP", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class APP: public Ui_APP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TEST_H
