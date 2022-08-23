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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountDetail
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *IDLabel;
    QLineEdit *IDEdit;
    QLabel *NameLabel;
    QLineEdit *NameEdit;
    QLabel *SexLabel;
    QLabel *PhoneLabel;
    QLineEdit *PhoneEdit;
    QLabel *PasswordLabel;
    QLineEdit *PasswordEdit;
    QLabel *MailLabel;
    QLineEdit *MailEdit;
    QLabel *AddressLabel;
    QLineEdit *AddressEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *MaleChoose;
    QRadioButton *FemaleChoose;
    QRadioButton *SecretChoose;
    QSpacerItem *horizontalSpacer;
    QWidget *horizontalLayoutWidget_2;
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
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 40, 781, 421));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(10, -1, 10, -1);
        IDLabel = new QLabel(horizontalLayoutWidget);
        IDLabel->setObjectName(QString::fromUtf8("IDLabel"));
        IDLabel->setMinimumSize(QSize(80, 0));
        IDLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, IDLabel);

        IDEdit = new QLineEdit(horizontalLayoutWidget);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));
        IDEdit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, IDEdit);

        NameLabel = new QLabel(horizontalLayoutWidget);
        NameLabel->setObjectName(QString::fromUtf8("NameLabel"));
        NameLabel->setMinimumSize(QSize(80, 0));
        NameLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, NameLabel);

        NameEdit = new QLineEdit(horizontalLayoutWidget);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));
        NameEdit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(1, QFormLayout::FieldRole, NameEdit);

        SexLabel = new QLabel(horizontalLayoutWidget);
        SexLabel->setObjectName(QString::fromUtf8("SexLabel"));
        SexLabel->setMinimumSize(QSize(80, 0));
        SexLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, SexLabel);

        PhoneLabel = new QLabel(horizontalLayoutWidget);
        PhoneLabel->setObjectName(QString::fromUtf8("PhoneLabel"));
        PhoneLabel->setMinimumSize(QSize(80, 0));
        PhoneLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, PhoneLabel);

        PhoneEdit = new QLineEdit(horizontalLayoutWidget);
        PhoneEdit->setObjectName(QString::fromUtf8("PhoneEdit"));
        PhoneEdit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(3, QFormLayout::FieldRole, PhoneEdit);

        PasswordLabel = new QLabel(horizontalLayoutWidget);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setMinimumSize(QSize(80, 0));
        PasswordLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, PasswordLabel);

        PasswordEdit = new QLineEdit(horizontalLayoutWidget);
        PasswordEdit->setObjectName(QString::fromUtf8("PasswordEdit"));
        PasswordEdit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(4, QFormLayout::FieldRole, PasswordEdit);

        MailLabel = new QLabel(horizontalLayoutWidget);
        MailLabel->setObjectName(QString::fromUtf8("MailLabel"));
        MailLabel->setMinimumSize(QSize(80, 0));
        MailLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, MailLabel);

        MailEdit = new QLineEdit(horizontalLayoutWidget);
        MailEdit->setObjectName(QString::fromUtf8("MailEdit"));
        MailEdit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(5, QFormLayout::FieldRole, MailEdit);

        AddressLabel = new QLabel(horizontalLayoutWidget);
        AddressLabel->setObjectName(QString::fromUtf8("AddressLabel"));
        AddressLabel->setMinimumSize(QSize(80, 0));
        AddressLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, AddressLabel);

        AddressEdit = new QLineEdit(horizontalLayoutWidget);
        AddressEdit->setObjectName(QString::fromUtf8("AddressEdit"));
        AddressEdit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(6, QFormLayout::FieldRole, AddressEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        MaleChoose = new QRadioButton(horizontalLayoutWidget);
        MaleChoose->setObjectName(QString::fromUtf8("MaleChoose"));
        MaleChoose->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(MaleChoose);

        FemaleChoose = new QRadioButton(horizontalLayoutWidget);
        FemaleChoose->setObjectName(QString::fromUtf8("FemaleChoose"));
        FemaleChoose->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(FemaleChoose);

        SecretChoose = new QRadioButton(horizontalLayoutWidget);
        SecretChoose->setObjectName(QString::fromUtf8("SecretChoose"));
        SecretChoose->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(SecretChoose);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(1, 50);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(570, 470, 195, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        SaveButton = new QPushButton(horizontalLayoutWidget_2);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        horizontalLayout_2->addWidget(SaveButton);

        ReturnButton = new QPushButton(horizontalLayoutWidget_2);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));

        horizontalLayout_2->addWidget(ReturnButton);

        AccountDetail->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccountDetail);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        NameLabel->setText(QCoreApplication::translate("AccountDetail", "\345\247\223\345\220\215", nullptr));
        SexLabel->setText(QCoreApplication::translate("AccountDetail", "\346\200\247\345\210\253", nullptr));
        PhoneLabel->setText(QCoreApplication::translate("AccountDetail", "\347\224\265\350\257\235", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("AccountDetail", "\345\257\206\347\240\201", nullptr));
        MailLabel->setText(QCoreApplication::translate("AccountDetail", "\351\202\256\347\256\261", nullptr));
        AddressLabel->setText(QCoreApplication::translate("AccountDetail", "\346\224\266\350\264\247\345\234\260\345\235\200", nullptr));
        MaleChoose->setText(QCoreApplication::translate("AccountDetail", "\347\224\267", nullptr));
        FemaleChoose->setText(QCoreApplication::translate("AccountDetail", "\345\245\263", nullptr));
        SecretChoose->setText(QCoreApplication::translate("AccountDetail", "\344\277\235\345\257\206", nullptr));
        SaveButton->setText(QCoreApplication::translate("AccountDetail", "\344\277\235\345\255\230", nullptr));
        ReturnButton->setText(QCoreApplication::translate("AccountDetail", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountDetail: public Ui_AccountDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDETAIL_H
