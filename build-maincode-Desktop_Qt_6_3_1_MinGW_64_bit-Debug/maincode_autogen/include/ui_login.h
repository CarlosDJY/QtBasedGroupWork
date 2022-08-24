/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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

class Ui_Login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *AccountLineEdit;
    QLabel *label_3;
    QLineEdit *PasswordLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ConfirmButton;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(50);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(30);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font.setPointSize(14);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(30);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        AccountLineEdit = new QLineEdit(centralwidget);
        AccountLineEdit->setObjectName(QString::fromUtf8("AccountLineEdit"));
        AccountLineEdit->setAutoFillBackground(false);

        gridLayout->addWidget(AccountLineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::RichText);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setAutoFillBackground(false);

        gridLayout->addWidget(PasswordLineEdit, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ConfirmButton = new QPushButton(centralwidget);
        ConfirmButton->setObjectName(QString::fromUtf8("ConfirmButton"));
        ConfirmButton->setFont(font1);

        horizontalLayout->addWidget(ConfirmButton);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setFont(font1);

        horizontalLayout->addWidget(BackButton);

        horizontalSpacer_2 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\350\264\246\345\217\267</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
        BackButton->setText(QCoreApplication::translate("Login", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
