#include "shoppingcart.h"
#include "mainwindow2.h"
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
}

void ShoppingCart::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

