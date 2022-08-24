/********************************************************************************
** Form generated from reading UI file 'productsearch.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTSEARCH_H
#define UI_PRODUCTSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductSearch
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *BackButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductSearch)
    {
        if (ProductSearch->objectName().isEmpty())
            ProductSearch->setObjectName(QString::fromUtf8("ProductSearch"));
        ProductSearch->resize(800, 600);
        centralwidget = new QWidget(ProductSearch);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 15, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setVerticalSpacing(0);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(250, 20));
        lineEdit_2->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 40));
        label_2->setMaximumSize(QSize(80, 40));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 40));
        label->setMaximumSize(QSize(80, 40));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(250, 20));
        lineEdit->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(comboBox, 1, 2, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(checkBox, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(38, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(pushButton_3, 0, 3, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 1, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(678, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 4);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy);
        BackButton->setMinimumSize(QSize(90, 30));
        BackButton->setMaximumSize(QSize(90, 30));
        BackButton->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(BackButton, 2, 4, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        ProductSearch->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductSearch);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ProductSearch->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductSearch);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProductSearch->setStatusBar(statusbar);

        retranslateUi(ProductSearch);

        QMetaObject::connectSlotsByName(ProductSearch);
    } // setupUi

    void retranslateUi(QMainWindow *ProductSearch)
    {
        ProductSearch->setWindowTitle(QCoreApplication::translate("ProductSearch", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("ProductSearch", "\350\266\205\345\270\202\345\220\215\347\247\260", nullptr));
        label->setText(QCoreApplication::translate("ProductSearch", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ProductSearch", "\347\273\274\345\220\210\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ProductSearch", "\351\224\200\351\207\217 \344\273\216\351\253\230\345\210\260\344\275\216", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ProductSearch", "\344\273\267\346\240\274 \344\273\216\344\275\216\345\210\260\351\253\230", nullptr));

        checkBox->setText(QCoreApplication::translate("ProductSearch", "\344\273\205\346\230\276\347\244\272\344\277\203\351\224\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ProductSearch", "\346\237\245\350\257\242", nullptr));
        BackButton->setText(QCoreApplication::translate("ProductSearch", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductSearch: public Ui_ProductSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSEARCH_H
