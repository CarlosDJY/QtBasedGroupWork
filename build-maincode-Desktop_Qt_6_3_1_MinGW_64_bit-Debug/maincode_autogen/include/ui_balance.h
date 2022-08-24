/********************************************************************************
** Form generated from reading UI file 'balance.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCE_H
#define UI_BALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Balance
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *BalanceNum;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *plus10;
    QPushButton *plus50;
    QPushButton *plus100;
    QLineEdit *plusNum;
    QPushButton *BackButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Balance)
    {
        if (Balance->objectName().isEmpty())
            Balance->setObjectName(QString::fromUtf8("Balance"));
        Balance->resize(800, 600);
        centralwidget = new QWidget(Balance);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 130, 491, 281));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        BalanceNum = new QLCDNumber(widget);
        BalanceNum->setObjectName(QString::fromUtf8("BalanceNum"));
        BalanceNum->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(BalanceNum);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plus10 = new QPushButton(widget);
        plus10->setObjectName(QString::fromUtf8("plus10"));
        plus10->setMinimumSize(QSize(120, 60));
        plus10->setMaximumSize(QSize(120, 60));

        gridLayout->addWidget(plus10, 0, 0, 1, 1);

        plus50 = new QPushButton(widget);
        plus50->setObjectName(QString::fromUtf8("plus50"));
        plus50->setMinimumSize(QSize(120, 60));
        plus50->setMaximumSize(QSize(120, 60));

        gridLayout->addWidget(plus50, 0, 1, 1, 1);

        plus100 = new QPushButton(widget);
        plus100->setObjectName(QString::fromUtf8("plus100"));
        plus100->setMinimumSize(QSize(120, 60));
        plus100->setMaximumSize(QSize(120, 60));

        gridLayout->addWidget(plus100, 0, 2, 1, 1);

        plusNum = new QLineEdit(widget);
        plusNum->setObjectName(QString::fromUtf8("plusNum"));
        plusNum->setMinimumSize(QSize(240, 40));
        plusNum->setMaximumSize(QSize(240, 40));

        gridLayout->addWidget(plusNum, 1, 0, 1, 2);

        BackButton = new QPushButton(widget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setMinimumSize(QSize(120, 60));
        BackButton->setMaximumSize(QSize(120, 60));

        gridLayout->addWidget(BackButton, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        Balance->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Balance);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Balance->setMenuBar(menubar);
        statusbar = new QStatusBar(Balance);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Balance->setStatusBar(statusbar);

        retranslateUi(Balance);

        QMetaObject::connectSlotsByName(Balance);
    } // setupUi

    void retranslateUi(QMainWindow *Balance)
    {
        Balance->setWindowTitle(QCoreApplication::translate("Balance", "MainWindow", nullptr));
        plus10->setText(QCoreApplication::translate("Balance", "+10", nullptr));
        plus50->setText(QCoreApplication::translate("Balance", "+50", nullptr));
        plus100->setText(QCoreApplication::translate("Balance", "+100", nullptr));
        BackButton->setText(QCoreApplication::translate("Balance", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Balance: public Ui_Balance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCE_H
