#include "shoppingcart.h"
#include "mainwindow2.h"
#include "paypage.h"
#include "ui_shoppingcart.h"

ShoppingCart::ShoppingCart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
}

ShoppingCart::~ShoppingCart()
{
    delete ui;
    this->setWindowTitle("网上超市系统");
}

void ShoppingCart::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}


void ShoppingCart::on_BuyAll_clicked()
{
    PayPage *win = new PayPage;
    win->show();
    this->close();
}

