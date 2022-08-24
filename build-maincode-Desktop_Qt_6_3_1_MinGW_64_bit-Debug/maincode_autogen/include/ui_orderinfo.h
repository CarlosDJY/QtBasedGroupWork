/********************************************************************************
** Form generated from reading UI file 'orderinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERINFO_H
#define UI_ORDERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderInfo
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QTableView *OrderTable;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OrderInfo)
    {
        if (OrderInfo->objectName().isEmpty())
            OrderInfo->setObjectName(QString::fromUtf8("OrderInfo"));
        OrderInfo->resize(800, 600);
        centralwidget = new QWidget(OrderInfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        OrderTable = new QTableView(centralwidget);
        OrderTable->setObjectName(QString::fromUtf8("OrderTable"));
        OrderTable->setMinimumSize(QSize(0, 0));
        OrderTable->setMaximumSize(QSize(1000000, 1000000));

        gridLayout->addWidget(OrderTable, 0, 0, 1, 2);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setMinimumSize(QSize(90, 30));
        BackButton->setMaximumSize(QSize(90, 30));
        BackButton->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(BackButton, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        OrderInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OrderInfo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        OrderInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(OrderInfo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OrderInfo->setStatusBar(statusbar);

        retranslateUi(OrderInfo);

        QMetaObject::connectSlotsByName(OrderInfo);
    } // setupUi

    void retranslateUi(QMainWindow *OrderInfo)
    {
        OrderInfo->setWindowTitle(QCoreApplication::translate("OrderInfo", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        BackButton->setToolTip(QCoreApplication::translate("OrderInfo", "<html><head/><body><p>\350\277\224\345\233\236</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BackButton->setText(QCoreApplication::translate("OrderInfo", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderInfo: public Ui_OrderInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERINFO_H
