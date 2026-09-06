/********************************************************************************
** Form generated from reading UI file 'widge.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WIDGE_H
#define WIDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QLineEdit *IP;
    QSpinBox *Port;
    QPushButton *BConnect;
    QSplitter *splitter2;
//    QLineEdit *IP2;
    QSpinBox *Port2;
    QPushButton *BConnect2;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *SignName;
    QLineEdit *SignPassword;
    QPushButton *BSign;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LoginName;
    QLineEdit *LoginPassword;
    QPushButton *BLogin;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(447, 280);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 358, 177));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        IP = new QLineEdit(splitter);
        IP->setObjectName(QStringLiteral("IP"));
        splitter->addWidget(IP);
        Port = new QSpinBox(splitter);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setMinimum(1025);
        Port->setMaximum(65530);
        Port->setValue(4242);
        splitter->addWidget(Port);
        BConnect = new QPushButton(splitter);
        BConnect->setObjectName(QStringLiteral("BConnect"));
        splitter->addWidget(BConnect);

        splitter2 = new QSplitter(layoutWidget);
        splitter2->setObjectName(QStringLiteral("splitter"));
        splitter2->setOrientation(Qt::Horizontal);
        // IP2 = new QLineEdit(splitter2);
        // IP2->setObjectName(QStringLiteral("IP2"));
        // splitter2->addWidget(IP2);
        // SearchRelation->setGeometry(QRect(860, 30, 221, 31));
        Port2 = new QSpinBox(splitter2);
        Port2->setObjectName(QStringLiteral("Port2"));
        Port2->setMinimum(1025);
        Port2->setMaximum(65530);
        Port2->setValue(4243);
        splitter2->addWidget(Port2);
        // SearchRelation->setGeometry(QRect(860, 30, 221, 31));
        BConnect2 = new QPushButton(splitter2);
        BConnect2->setObjectName(QStringLiteral("BConnect2"));
        splitter2->addWidget(BConnect2);

        splitter2->setGeometry(QRect(0, 40, 358, 25));

        verticalLayout_3->addWidget(splitter);

        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        splitter_2 = new QSplitter(layoutWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget_2 = new QWidget(splitter_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SignName = new QLineEdit(layoutWidget_2);
        SignName->setObjectName(QStringLiteral("SignName"));

        verticalLayout->addWidget(SignName);

        SignPassword = new QLineEdit(layoutWidget_2);
        SignPassword->setObjectName(QStringLiteral("SignPassword"));

        verticalLayout->addWidget(SignPassword);

        BSign = new QPushButton(layoutWidget_2);
        BSign->setObjectName(QStringLiteral("BSign"));

        verticalLayout->addWidget(BSign);

        splitter_2->addWidget(layoutWidget_2);
        layoutWidget_3 = new QWidget(splitter_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        LoginName = new QLineEdit(layoutWidget_3);
        LoginName->setObjectName(QStringLiteral("LoginName"));

        verticalLayout_2->addWidget(LoginName);

        LoginPassword = new QLineEdit(layoutWidget_3);
        LoginPassword->setObjectName(QStringLiteral("LoginPassword"));

        verticalLayout_2->addWidget(LoginPassword);

        BLogin = new QPushButton(layoutWidget_3);
        BLogin->setObjectName(QStringLiteral("BLogin"));

        verticalLayout_2->addWidget(BLogin);

        splitter_2->addWidget(layoutWidget_3);

        verticalLayout_3->addWidget(splitter_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        IP->setText(QApplication::translate("Form", "127.0.0.1", nullptr));
        BConnect->setText(QApplication::translate("Form", "Connect", nullptr));
//        IP2->setText(QApplication::translate("Form", "127.0.0.1", nullptr));
        BConnect2->setText(QApplication::translate("Form", "Bind", nullptr));
        SignName->setText(QApplication::translate("Form", "Name", nullptr));
        SignPassword->setText(QApplication::translate("Form", "Password", nullptr));
        SignPassword->setEchoMode(QLineEdit::Password);
        BSign->setText(QApplication::translate("Form", "Sign in", nullptr));
        LoginName->setText(QApplication::translate("Form", "Name", nullptr));
        LoginPassword->setText(QApplication::translate("Form", "Password", nullptr));
        LoginPassword->setEchoMode(QLineEdit::Password);
        BLogin->setText(QApplication::translate("Form", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDGE_H
