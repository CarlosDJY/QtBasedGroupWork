/********************************************************************************
** Form generated from reading UI file 'accountcontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTCONTROL_H
#define UI_ACCOUNTCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountControl
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *AccountButton;
    QPushButton *BalanceButton;
    QPushButton *PreferenceButton;
    QPushButton *LogOutButton;
    QPushButton *BackButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountControl)
    {
        if (AccountControl->objectName().isEmpty())
            AccountControl->setObjectName(QString::fromUtf8("AccountControl"));
        AccountControl->resize(800, 600);
        centralwidget = new QWidget(AccountControl);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 260, 431, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        AccountButton = new QPushButton(layoutWidget);
        AccountButton->setObjectName(QString::fromUtf8("AccountButton"));
        AccountButton->setMinimumSize(QSize(150, 60));
        AccountButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(AccountButton, 0, 0, 1, 1);

        BalanceButton = new QPushButton(layoutWidget);
        BalanceButton->setObjectName(QString::fromUtf8("BalanceButton"));
        BalanceButton->setMinimumSize(QSize(150, 60));
        BalanceButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(BalanceButton, 0, 1, 1, 1);

        PreferenceButton = new QPushButton(layoutWidget);
        PreferenceButton->setObjectName(QString::fromUtf8("PreferenceButton"));
        PreferenceButton->setMinimumSize(QSize(150, 60));
        PreferenceButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(PreferenceButton, 1, 0, 1, 1);

        LogOutButton = new QPushButton(layoutWidget);
        LogOutButton->setObjectName(QString::fromUtf8("LogOutButton"));
        LogOutButton->setMinimumSize(QSize(150, 60));
        LogOutButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(LogOutButton, 1, 1, 1, 1);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(650, 490, 93, 30));
        BackButton->setMinimumSize(QSize(60, 30));
        AccountControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccountControl);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        AccountControl->setMenuBar(menubar);
        statusbar = new QStatusBar(AccountControl);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AccountControl->setStatusBar(statusbar);

        retranslateUi(AccountControl);

        QMetaObject::connectSlotsByName(AccountControl);
    } // setupUi

    void retranslateUi(QMainWindow *AccountControl)
    {
        AccountControl->setWindowTitle(QCoreApplication::translate("AccountControl", "MainWindow", nullptr));
        AccountButton->setText(QCoreApplication::translate("AccountControl", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        BalanceButton->setText(QCoreApplication::translate("AccountControl", "\344\275\231\351\242\235\346\237\245\350\257\242", nullptr));
        PreferenceButton->setText(QCoreApplication::translate("AccountControl", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        LogOutButton->setText(QCoreApplication::translate("AccountControl", "\347\231\273\345\207\272", nullptr));
        BackButton->setText(QCoreApplication::translate("AccountControl", " \350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountControl: public Ui_AccountControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTCONTROL_H
