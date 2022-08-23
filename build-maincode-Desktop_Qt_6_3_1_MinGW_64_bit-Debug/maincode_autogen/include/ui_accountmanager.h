/********************************************************************************
** Form generated from reading UI file 'accountmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTMANAGER_H
#define UI_ACCOUNTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountManager
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountManager)
    {
        if (AccountManager->objectName().isEmpty())
            AccountManager->setObjectName(QString::fromUtf8("AccountManager"));
        AccountManager->resize(800, 600);
        menubar = new QMenuBar(AccountManager);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        AccountManager->setMenuBar(menubar);
        centralwidget = new QWidget(AccountManager);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AccountManager->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AccountManager);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AccountManager->setStatusBar(statusbar);

        retranslateUi(AccountManager);

        QMetaObject::connectSlotsByName(AccountManager);
    } // setupUi

    void retranslateUi(QMainWindow *AccountManager)
    {
        AccountManager->setWindowTitle(QCoreApplication::translate("AccountManager", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountManager: public Ui_AccountManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTMANAGER_H
