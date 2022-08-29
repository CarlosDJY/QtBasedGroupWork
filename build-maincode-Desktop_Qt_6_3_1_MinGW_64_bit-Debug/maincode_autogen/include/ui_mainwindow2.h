/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *AccountButton;
    QPushButton *OrderButton;
    QPushButton *ProductButton;
    QPushButton *CartButton;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QString::fromUtf8("MainWindow2"));
        MainWindow2->resize(800, 600);
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(15, -1, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(60);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        AccountButton = new QPushButton(centralwidget);
        AccountButton->setObjectName(QString::fromUtf8("AccountButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AccountButton->sizePolicy().hasHeightForWidth());
        AccountButton->setSizePolicy(sizePolicy);
        AccountButton->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(AccountButton);

        OrderButton = new QPushButton(centralwidget);
        OrderButton->setObjectName(QString::fromUtf8("OrderButton"));
        sizePolicy.setHeightForWidth(OrderButton->sizePolicy().hasHeightForWidth());
        OrderButton->setSizePolicy(sizePolicy);
        OrderButton->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(OrderButton);

        ProductButton = new QPushButton(centralwidget);
        ProductButton->setObjectName(QString::fromUtf8("ProductButton"));
        sizePolicy.setHeightForWidth(ProductButton->sizePolicy().hasHeightForWidth());
        ProductButton->setSizePolicy(sizePolicy);
        ProductButton->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(ProductButton);

        CartButton = new QPushButton(centralwidget);
        CartButton->setObjectName(QString::fromUtf8("CartButton"));
        CartButton->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(CartButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        AccountButton->setText(QCoreApplication::translate("MainWindow2", "\350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
        OrderButton->setText(QCoreApplication::translate("MainWindow2", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
        ProductButton->setText(QCoreApplication::translate("MainWindow2", "\345\225\206\345\223\201\346\237\245\350\257\242", nullptr));
        CartButton->setText(QCoreApplication::translate("MainWindow2", "\350\264\255\347\211\251\350\275\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
