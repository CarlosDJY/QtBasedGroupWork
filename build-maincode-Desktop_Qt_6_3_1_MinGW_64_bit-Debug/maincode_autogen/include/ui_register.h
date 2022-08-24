/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
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

class Ui_Register
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *PasswordLineEdit;
    QLabel *label_4;
    QLineEdit *AdminPasswordLineEdit;
    QLineEdit *AccountLineEdit;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *ConfirmButton;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(800, 600);
        centralwidget = new QWidget(Register);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(40);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

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

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(-1, 5, -1, 5);
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

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        label_5->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::RichText);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setAutoFillBackground(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, PasswordLineEdit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font1);
        label_4->setTextFormat(Qt::RichText);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        AdminPasswordLineEdit = new QLineEdit(centralwidget);
        AdminPasswordLineEdit->setObjectName(QString::fromUtf8("AdminPasswordLineEdit"));
        AdminPasswordLineEdit->setAutoFillBackground(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, AdminPasswordLineEdit);

        AccountLineEdit = new QLineEdit(centralwidget);
        AccountLineEdit->setObjectName(QString::fromUtf8("AccountLineEdit"));
        AccountLineEdit->setAutoFillBackground(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, AccountLineEdit);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        formLayout->setWidget(3, QFormLayout::FieldRole, label_6);


        gridLayout->addLayout(formLayout, 1, 0, 1, 5);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ConfirmButton = new QPushButton(centralwidget);
        ConfirmButton->setObjectName(QString::fromUtf8("ConfirmButton"));
        ConfirmButton->setFont(font1);

        horizontalLayout->addWidget(ConfirmButton);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setFont(font1);

        horizontalLayout->addWidget(BackButton);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        Register->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Register);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Register->setMenuBar(menubar);
        statusbar = new QStatusBar(Register);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Register->setStatusBar(statusbar);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QMainWindow *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">\346\263\250\345\206\214</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">\350\264\246\345\217\267\357\274\210\345\277\205\345\241\253\357\274\211</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Register", "\346\263\250\346\204\217\357\274\2321.\347\231\273\351\231\206ID\345\277\205\351\241\273\344\270\272\345\255\227\346\257\215\346\225\260\345\255\227\346\267\267\345\220\210 2.\347\224\250\346\210\267ID\351\225\277\345\272\246\345\234\2506-10\344\270\252\345\255\227\350\212\202", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">\345\257\206\347\240\201\357\274\210\345\277\205\345\241\253\357\274\211</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\">\347\256\241\347\220\206\345\257\206\347\240\201</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Register", "\346\263\250\346\204\217\357\274\2321.\347\231\273\351\231\206\345\257\206\347\240\201\345\277\205\351\241\273\344\270\272\345\255\227\346\257\215\346\225\260\345\255\227\346\267\267\345\220\210 2.\347\231\273\351\231\206\345\257\206\347\240\201\351\225\277\345\272\246\345\234\2506-10\344\270\252\345\255\227\350\212\202", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("Register", "\347\241\256\345\256\232", nullptr));
        BackButton->setText(QCoreApplication::translate("Register", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
