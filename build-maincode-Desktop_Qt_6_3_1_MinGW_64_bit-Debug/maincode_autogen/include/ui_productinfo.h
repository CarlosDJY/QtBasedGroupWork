/********************************************************************************
** Form generated from reading UI file 'productinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTINFO_H
#define UI_PRODUCTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductInfo
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *ProductID;
    QLabel *label_6;
    QLabel *Sale;
    QLabel *Price;
    QLabel *StartTime;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *SupermarketID;
    QLabel *label_5;
    QLabel *DiscountPrice;
    QLabel *label_7;
    QLabel *EndTime;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *AddToCart;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductInfo)
    {
        if (ProductInfo->objectName().isEmpty())
            ProductInfo->setObjectName(QString::fromUtf8("ProductInfo"));
        ProductInfo->resize(800, 600);
        centralwidget = new QWidget(ProductInfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(1000, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(30);
        gridLayout->setContentsMargins(-1, 15, -1, 15);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        ProductID = new QLabel(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(ProductID, 1, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        Sale = new QLabel(centralwidget);
        Sale->setObjectName(QString::fromUtf8("Sale"));
        Sale->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(Sale, 0, 1, 1, 1);

        Price = new QLabel(centralwidget);
        Price->setObjectName(QString::fromUtf8("Price"));
        Price->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(Price, 2, 1, 1, 1);

        StartTime = new QLabel(centralwidget);
        StartTime->setObjectName(QString::fromUtf8("StartTime"));
        StartTime->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(StartTime, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 4, 1);

        horizontalSpacer = new QSpacerItem(350, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(60, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(30);
        gridLayout_2->setContentsMargins(-1, 15, -1, 15);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 27));
        label_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        SupermarketID = new QLabel(centralwidget);
        SupermarketID->setObjectName(QString::fromUtf8("SupermarketID"));
        SupermarketID->setMinimumSize(QSize(180, 27));
        SupermarketID->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(SupermarketID, 0, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 27));
        label_5->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        DiscountPrice = new QLabel(centralwidget);
        DiscountPrice->setObjectName(QString::fromUtf8("DiscountPrice"));
        DiscountPrice->setMinimumSize(QSize(180, 27));
        DiscountPrice->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(DiscountPrice, 1, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 27));
        label_7->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        EndTime = new QLabel(centralwidget);
        EndTime->setObjectName(QString::fromUtf8("EndTime"));
        EndTime->setMinimumSize(QSize(180, 27));
        EndTime->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(EndTime, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 2, 3, 1);

        horizontalSpacer_6 = new QSpacerItem(60, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 2, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(60, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 3, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(100, 14, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        AddToCart = new QPushButton(centralwidget);
        AddToCart->setObjectName(QString::fromUtf8("AddToCart"));
        AddToCart->setMinimumSize(QSize(120, 40));

        gridLayout_4->addWidget(AddToCart, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(138, 17, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setMinimumSize(QSize(120, 40));

        gridLayout_4->addWidget(BackButton, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(100, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 4, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(1000, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        ProductInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductInfo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ProductInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductInfo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProductInfo->setStatusBar(statusbar);

        retranslateUi(ProductInfo);

        QMetaObject::connectSlotsByName(ProductInfo);
    } // setupUi

    void retranslateUi(QMainWindow *ProductInfo)
    {
        ProductInfo->setWindowTitle(QCoreApplication::translate("ProductInfo", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\351\233\266\345\224\256\344\273\267\346\240\274</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\351\224\200\351\207\217</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\345\225\206\345\223\201\345\217\267</p></body></html>", nullptr));
        ProductID->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">ProductID</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\346\212\230\346\211\243\345\274\200\345\247\213\346\227\266\351\227\264</p></body></html>", nullptr));
        Sale->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">Sale</p></body></html>", nullptr));
        Price->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">Price</p></body></html>", nullptr));
        StartTime->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">StartTime</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\346\211\200\345\261\236\350\266\205\345\270\202</p></body></html>", nullptr));
        SupermarketID->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">SupermarketID</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\346\212\230\346\211\243\344\273\267\346\240\274</p></body></html>", nullptr));
        DiscountPrice->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">DiscountPrice</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">\346\212\230\346\211\243\347\273\223\346\235\237\346\227\266\351\227\264</p></body></html>", nullptr));
        EndTime->setText(QCoreApplication::translate("ProductInfo", "<html><head/><body><p align=\"center\">EndTime</p></body></html>", nullptr));
        AddToCart->setText(QCoreApplication::translate("ProductInfo", "\346\267\273\345\212\240\350\207\263\350\264\255\347\211\251\350\275\246", nullptr));
        BackButton->setText(QCoreApplication::translate("ProductInfo", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductInfo: public Ui_ProductInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTINFO_H
