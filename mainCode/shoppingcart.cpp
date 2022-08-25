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

//购物车，包含该账号计划购买的全部物品，可以选择一键购买、部分购买、部分删除
ShoppingCart::~ShoppingCart()
{
    delete ui;
    this->setWindowTitle("网上超市系统");
}

//返回主界面2
void ShoppingCart::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

//购买所有购物车内商品
void ShoppingCart::on_BuyAll_clicked()
{
    PayPage *win = new PayPage;
    win->show();
    this->close();
}

//购买选中的购物车内商品
void ShoppingCart::on_BuyChosen_clicked()
{
    PayPage *win = new PayPage;
    win->show();
    this->close();
}

