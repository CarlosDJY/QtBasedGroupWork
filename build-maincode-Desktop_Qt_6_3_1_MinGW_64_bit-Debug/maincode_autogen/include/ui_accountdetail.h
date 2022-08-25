/********************************************************************************
** Form generated from reading UI file 'accountdetail.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTDETAIL_H
#define UI_ACCOUNTDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountDetail
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *IDLabel;
    QLineEdit *IDEdit;
    QLabel *PasswordLabel;
    QLineEdit *PasswordEdit;
    QLabel *NameLabel;
    QLineEdit *NameEdit;
    QLabel *PhoneLabel;
    QLineEdit *PhoneEdit;
    QLabel *SexLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *MaleChoose;
    QRadioButton *FemaleChoose;
    QRadioButton *SecretChoose;
    QLabel *MailLabel;
    QLineEdit *MailEdit;
    QLabel *AddressLabel;
    QLineEdit *AddressEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *SaveButton;
    QPushButton *ReturnButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountDetail)
    {
        if (AccountDetail->objectName().isEmpty())
            AccountDetail->setObjectName(QString::fromUtf8("AccountDetail"));
        AccountDetail->resize(800, 600);
        centralwidget = new QWidget(AccountDetail);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(20, -1, 20, -1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 30, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(40);
        IDLabel = new QLabel(centralwidget);
        IDLabel->setObjectName(QString::fromUtf8("IDLabel"));
        IDLabel->setMinimumSize(QSize(80, 0));
        IDLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(IDLabel, 0, 0, 1, 1);

        IDEdit = new QLineEdit(centralwidget);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));
        IDEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(IDEdit, 0, 1, 1, 1);

        PasswordLabel = new QLabel(centralwidget);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setMinimumSize(QSize(80, 0));
        PasswordLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PasswordLabel, 1, 0, 1, 1);

        PasswordEdit = new QLineEdit(centralwidget);
        PasswordEdit->setObjectName(QString::fromUtf8("PasswordEdit"));
        PasswordEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(PasswordEdit, 1, 1, 1, 1);

        NameLabel = new QLabel(centralwidget);
        NameLabel->setObjectName(QString::fromUtf8("NameLabel"));
        NameLabel->setMinimumSize(QSize(80, 0));
        NameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(NameLabel, 2, 0, 1, 1);

        NameEdit = new QLineEdit(centralwidget);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));
        NameEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(NameEdit, 2, 1, 1, 1);

        PhoneLabel = new QLabel(centralwidget);
        PhoneLabel->setObjectName(QString::fromUtf8("PhoneLabel"));
        PhoneLabel->setMinimumSize(QSize(80, 0));
        PhoneLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PhoneLabel, 3, 0, 1, 1);

        PhoneEdit = new QLineEdit(centralwidget);
        PhoneEdit->setObjectName(QString::fromUtf8("PhoneEdit"));
        PhoneEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(PhoneEdit, 3, 1, 1, 1);

        SexLabel = new QLabel(centralwidget);
        SexLabel->setObjectName(QString::fromUtf8("SexLabel"));
        SexLabel->setMinimumSize(QSize(80, 0));
        SexLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(SexLabel, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        MaleChoose = new QRadioButton(centralwidget);
        MaleChoose->setObjectName(QString::fromUtf8("MaleChoose"));
        MaleChoose->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(MaleChoose);

        FemaleChoose = new QRadioButton(centralwidget);
        FemaleChoose->setObjectName(QString::fromUtf8("FemaleChoose"));
        FemaleChoose->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(FemaleChoose);

        SecretChoose = new QRadioButton(centralwidget);
        SecretChoose->setObjectName(QString::fromUtf8("SecretChoose"));
        SecretChoose->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(SecretChoose);


        gridLayout->addLayout(horizontalLayout_3, 4, 1, 1, 1);

        MailLabel = new QLabel(centralwidget);
        MailLabel->setObjectName(QString::fromUtf8("MailLabel"));
        MailLabel->setMinimumSize(QSize(80, 0));
        MailLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(MailLabel, 5, 0, 1, 1);

        MailEdit = new QLineEdit(centralwidget);
        MailEdit->setObjectName(QString::fromUtf8("MailEdit"));
        MailEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(MailEdit, 5, 1, 1, 1);

        AddressLabel = new QLabel(centralwidget);
        AddressLabel->setObjectName(QString::fromUtf8("AddressLabel"));
        AddressLabel->setMinimumSize(QSize(80, 0));
        AddressLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(AddressLabel, 6, 0, 1, 1);

        AddressEdit = new QLineEdit(centralwidget);
        AddressEdit->setObjectName(QString::fromUtf8("AddressEdit"));
        AddressEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(AddressEdit, 6, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        horizontalLayout_2->addWidget(SaveButton);

        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));

        horizontalLayout_2->addWidget(ReturnButton);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        AccountDetail->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccountDetail);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        AccountDetail->setMenuBar(menubar);
        statusbar = new QStatusBar(AccountDetail);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AccountDetail->setStatusBar(statusbar);

        retranslateUi(AccountDetail);

        QMetaObject::connectSlotsByName(AccountDetail);
    } // setupUi

    void retranslateUi(QMainWindow *AccountDetail)
    {
        AccountDetail->setWindowTitle(QCoreApplication::translate("AccountDetail", "MainWindow", nullptr));
        IDLabel->setText(QCoreApplication::translate("AccountDetail", "\347\224\250\346\210\267ID", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("AccountDetail", "\345\257\206\347\240\201", nullptr));
        NameLabel->setText(QCoreApplication::translate("AccountDetail", "\345\247\223\345\220\215", nullptr));
        PhoneLabel->setText(QCoreApplication::translate("AccountDetail", "\347\224\265\350\257\235", nullptr));
        SexLabel->setText(QCoreApplication::translate("AccountDetail", "\346\200\247\345\210\253", nullptr));
        MaleChoose->setText(QCoreApplication::translate("AccountDetail", "\347\224\267", nullptr));
        FemaleChoose->setText(QCoreApplication::translate("AccountDetail", "\345\245\263", nullptr));
        SecretChoose->setText(QCoreApplication::translate("AccountDetail", "\344\277\235\345\257\206", nullptr));
        MailLabel->setText(QCoreApplication::translate("AccountDetail", "\351\202\256\347\256\261", nullptr));
        AddressLabel->setText(QCoreApplication::translate("AccountDetail", "\346\224\266\350\264\247\345\234\260\345\235\200", nullptr));
        SaveButton->setText(QCoreApplication::translate("AccountDetail", "\344\277\235\345\255\230", nullptr));
        ReturnButton->setText(QCoreApplication::translate("AccountDetail", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountDetail: public Ui_AccountDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDETAIL_H
