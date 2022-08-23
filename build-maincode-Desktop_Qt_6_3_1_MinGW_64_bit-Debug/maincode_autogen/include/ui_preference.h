/********************************************************************************
** Form generated from reading UI file 'preference.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCE_H
#define UI_PREFERENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preference
{
public:
    QWidget *centralwidget;
    QPushButton *BackButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QRadioButton *PriceHigh;
    QRadioButton *PriceLow;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QRadioButton *DiscountHigh;
    QRadioButton *DiscountLow;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QRadioButton *SalesHigh;
    QRadioButton *SalesLow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Preference)
    {
        if (Preference->objectName().isEmpty())
            Preference->setObjectName(QString::fromUtf8("Preference"));
        Preference->resize(800, 600);
        centralwidget = new QWidget(Preference);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(590, 420, 100, 60));
        BackButton->setMinimumSize(QSize(100, 60));
        BackButton->setMaximumSize(QSize(100, 60));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 141, 801, 241));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 60));
        label->setMaximumSize(QSize(60, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font.setPointSize(14);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        PriceHigh = new QRadioButton(widget);
        PriceHigh->setObjectName(QString::fromUtf8("PriceHigh"));
        PriceHigh->setMinimumSize(QSize(60, 60));
        PriceHigh->setMaximumSize(QSize(60, 16777215));
        PriceHigh->setFont(font);
        PriceHigh->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(PriceHigh, 0, 2, 1, 1);

        PriceLow = new QRadioButton(widget);
        PriceLow->setObjectName(QString::fromUtf8("PriceLow"));
        PriceLow->setMinimumSize(QSize(60, 60));
        PriceLow->setMaximumSize(QSize(60, 16777215));
        PriceLow->setFont(font);
        PriceLow->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(PriceLow, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 60));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        DiscountHigh = new QRadioButton(widget);
        DiscountHigh->setObjectName(QString::fromUtf8("DiscountHigh"));
        DiscountHigh->setMinimumSize(QSize(60, 60));
        DiscountHigh->setMaximumSize(QSize(60, 16777215));
        DiscountHigh->setFont(font);
        DiscountHigh->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(DiscountHigh, 1, 2, 1, 1);

        DiscountLow = new QRadioButton(widget);
        DiscountLow->setObjectName(QString::fromUtf8("DiscountLow"));
        DiscountLow->setMinimumSize(QSize(60, 60));
        DiscountLow->setMaximumSize(QSize(60, 16777215));
        DiscountLow->setFont(font);
        DiscountLow->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(DiscountLow, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 60));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        SalesHigh = new QRadioButton(widget);
        SalesHigh->setObjectName(QString::fromUtf8("SalesHigh"));
        SalesHigh->setMinimumSize(QSize(60, 60));
        SalesHigh->setMaximumSize(QSize(60, 16777215));
        SalesHigh->setFont(font);
        SalesHigh->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(SalesHigh, 2, 2, 1, 1);

        SalesLow = new QRadioButton(widget);
        SalesLow->setObjectName(QString::fromUtf8("SalesLow"));
        SalesLow->setMinimumSize(QSize(60, 60));
        SalesLow->setMaximumSize(QSize(60, 16777215));
        SalesLow->setFont(font);
        SalesLow->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(SalesLow, 2, 3, 1, 1);

        Preference->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Preference);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Preference->setMenuBar(menubar);
        statusbar = new QStatusBar(Preference);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Preference->setStatusBar(statusbar);

        retranslateUi(Preference);

        QMetaObject::connectSlotsByName(Preference);
    } // setupUi

    void retranslateUi(QMainWindow *Preference)
    {
        Preference->setWindowTitle(QCoreApplication::translate("Preference", "MainWindow", nullptr));
        BackButton->setText(QCoreApplication::translate("Preference", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("Preference", "\344\273\267\346\240\274", nullptr));
        PriceHigh->setText(QCoreApplication::translate("Preference", "\351\253\230", nullptr));
        PriceLow->setText(QCoreApplication::translate("Preference", "\344\275\216", nullptr));
        label_2->setText(QCoreApplication::translate("Preference", "\346\212\230\346\211\243", nullptr));
        DiscountHigh->setText(QCoreApplication::translate("Preference", "\351\253\230", nullptr));
        DiscountLow->setText(QCoreApplication::translate("Preference", "\344\275\216", nullptr));
        label_3->setText(QCoreApplication::translate("Preference", "\351\224\200\351\207\217", nullptr));
        SalesHigh->setText(QCoreApplication::translate("Preference", "\351\253\230", nullptr));
        SalesLow->setText(QCoreApplication::translate("Preference", "\344\275\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Preference: public Ui_Preference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCE_H
