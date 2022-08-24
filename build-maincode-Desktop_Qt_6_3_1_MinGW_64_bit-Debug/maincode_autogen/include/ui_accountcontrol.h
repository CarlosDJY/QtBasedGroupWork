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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountControl
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *AccountButton;
    QPushButton *BalanceButton;
    QPushButton *PreferenceButton;
    QPushButton *LogOutButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountControl)
    {
        if (AccountControl->objectName().isEmpty())
            AccountControl->setObjectName(QString::fromUtf8("AccountControl"));
        AccountControl->resize(800, 600);
        centralwidget = new QWidget(AccountControl);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(30);
        gridLayout->setContentsMargins(-1, 20, -1, 20);
        AccountButton = new QPushButton(centralwidget);
        AccountButton->setObjectName(QString::fromUtf8("AccountButton"));
        AccountButton->setMinimumSize(QSize(150, 60));
        AccountButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(AccountButton, 0, 0, 1, 1);

        BalanceButton = new QPushButton(centralwidget);
        BalanceButton->setObjectName(QString::fromUtf8("BalanceButton"));
        BalanceButton->setMinimumSize(QSize(150, 60));
        BalanceButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(BalanceButton, 0, 1, 1, 1);

        PreferenceButton = new QPushButton(centralwidget);
        PreferenceButton->setObjectName(QString::fromUtf8("PreferenceButton"));
        PreferenceButton->setMinimumSize(QSize(150, 60));
        PreferenceButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(PreferenceButton, 1, 0, 1, 1);

        LogOutButton = new QPushButton(centralwidget);
        LogOutButton->setObjectName(QString::fromUtf8("LogOutButton"));
        LogOutButton->setMinimumSize(QSize(150, 60));
        LogOutButton->setMaximumSize(QSize(150, 60));

        gridLayout->addWidget(LogOutButton, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(428, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setMinimumSize(QSize(60, 30));

        gridLayout_2->addWidget(BackButton, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

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
