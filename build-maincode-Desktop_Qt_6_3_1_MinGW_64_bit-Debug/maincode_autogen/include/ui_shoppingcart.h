/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShoppingCart
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QTableView *tableView;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *BuyAll;
    QPushButton *BuyChosen;
    QPushButton *DeleteChosen;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShoppingCart)
    {
        if (ShoppingCart->objectName().isEmpty())
            ShoppingCart->setObjectName(QString::fromUtf8("ShoppingCart"));
        ShoppingCart->resize(800, 600);
        centralwidget = new QWidget(ShoppingCart);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(50);
        gridLayout->setContentsMargins(30, 10, 30, 10);
        horizontalSpacer_3 = new QSpacerItem(268, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(250, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 5, 1, 3);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 8);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 2, 0, 1, 8);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 8);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        BuyAll = new QPushButton(centralwidget);
        BuyAll->setObjectName(QString::fromUtf8("BuyAll"));
        BuyAll->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(BuyAll, 4, 1, 1, 1);

        BuyChosen = new QPushButton(centralwidget);
        BuyChosen->setObjectName(QString::fromUtf8("BuyChosen"));
        BuyChosen->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(BuyChosen, 4, 2, 1, 2);

        DeleteChosen = new QPushButton(centralwidget);
        DeleteChosen->setObjectName(QString::fromUtf8("DeleteChosen"));
        DeleteChosen->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(DeleteChosen, 4, 4, 1, 2);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(BackButton, 4, 6, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 7, 1, 1);


        verticalLayout->addLayout(gridLayout);

        ShoppingCart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShoppingCart);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ShoppingCart->setMenuBar(menubar);
        statusbar = new QStatusBar(ShoppingCart);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShoppingCart->setStatusBar(statusbar);

        retranslateUi(ShoppingCart);

        QMetaObject::connectSlotsByName(ShoppingCart);
    } // setupUi

    void retranslateUi(QMainWindow *ShoppingCart)
    {
        ShoppingCart->setWindowTitle(QCoreApplication::translate("ShoppingCart", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ShoppingCart", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\350\264\255\347\211\251\350\275\246</span></p></body></html>", nullptr));
        BuyAll->setText(QCoreApplication::translate("ShoppingCart", "\345\205\250\351\203\250\350\264\255\344\271\260", nullptr));
        BuyChosen->setText(QCoreApplication::translate("ShoppingCart", "\350\264\255\344\271\260\351\200\211\344\270\255", nullptr));
        DeleteChosen->setText(QCoreApplication::translate("ShoppingCart", "\345\210\240\351\231\244\351\200\211\344\270\255", nullptr));
        BackButton->setText(QCoreApplication::translate("ShoppingCart", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShoppingCart: public Ui_ShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
