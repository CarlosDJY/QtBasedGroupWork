/********************************************************************************
** Form generated from reading UI file 'paypage.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYPAGE_H
#define UI_PAYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PayPage
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QLCDNumber *PriceNumber;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLCDNumber *VerifyNumber;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *VerifyCodeEdit;
    QPushButton *Confirm;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *Cancel;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PayPage)
    {
        if (PayPage->objectName().isEmpty())
            PayPage->setObjectName(QString::fromUtf8("PayPage"));
        PayPage->resize(800, 600);
        centralwidget = new QWidget(PayPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(30);
        horizontalSpacer_6 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 50));
        label_2->setMaximumSize(QSize(120, 50));

        gridLayout->addWidget(label_2, 0, 1, 1, 2);

        PriceNumber = new QLCDNumber(centralwidget);
        PriceNumber->setObjectName(QString::fromUtf8("PriceNumber"));
        PriceNumber->setMinimumSize(QSize(150, 0));
        PriceNumber->setMaximumSize(QSize(200, 50));

        gridLayout->addWidget(PriceNumber, 0, 3, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 50));
        label_3->setMaximumSize(QSize(120, 50));

        gridLayout->addWidget(label_3, 0, 5, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 8, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(label, 1, 0, 1, 9);

        horizontalSpacer_4 = new QSpacerItem(168, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 3);

        VerifyNumber = new QLCDNumber(centralwidget);
        VerifyNumber->setObjectName(QString::fromUtf8("VerifyNumber"));
        VerifyNumber->setMinimumSize(QSize(120, 40));
        VerifyNumber->setMaximumSize(QSize(150, 50));

        gridLayout->addWidget(VerifyNumber, 2, 3, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(178, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 5, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 2);

        VerifyCodeEdit = new QLineEdit(centralwidget);
        VerifyCodeEdit->setObjectName(QString::fromUtf8("VerifyCodeEdit"));
        VerifyCodeEdit->setMinimumSize(QSize(0, 20));
        VerifyCodeEdit->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(VerifyCodeEdit, 3, 2, 1, 2);

        Confirm = new QPushButton(centralwidget);
        Confirm->setObjectName(QString::fromUtf8("Confirm"));
        Confirm->setMinimumSize(QSize(0, 40));
        Confirm->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(Confirm, 3, 4, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 6, 1, 3);

        horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 7);

        Cancel = new QPushButton(centralwidget);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setMinimumSize(QSize(0, 40));
        Cancel->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(Cancel, 4, 7, 1, 2);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        PayPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PayPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        PayPage->setMenuBar(menubar);
        statusbar = new QStatusBar(PayPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PayPage->setStatusBar(statusbar);

        retranslateUi(PayPage);

        QMetaObject::connectSlotsByName(PayPage);
    } // setupUi

    void retranslateUi(QMainWindow *PayPage)
    {
        PayPage->setWindowTitle(QCoreApplication::translate("PayPage", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("PayPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\351\234\200\350\246\201\346\224\257\344\273\230</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("PayPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\205\203</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("PayPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201\344\273\245\346\224\257\344\273\230\357\274\232</span></p></body></html>", nullptr));
        Confirm->setText(QCoreApplication::translate("PayPage", "\347\253\213\345\210\273\346\224\257\344\273\230", nullptr));
        Cancel->setText(QCoreApplication::translate("PayPage", "\347\250\215\345\220\216\346\224\257\344\273\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PayPage: public Ui_PayPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYPAGE_H
