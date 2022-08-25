#include "mainwindow2.h"
#include "accountcontrol.h"
#include "orderinfo.h"
#include "productsearch.h"
#include "shoppingcart.h"
#include "ui_mainwindow2.h"

extern QString AccountInfomation;

//主界面2，下属账号管理，订单管理，商品查询，购物车四个分支
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

//转到账号管理界面
void MainWindow2::on_AccountButton_clicked()
{
    AccountControl *win = new AccountControl;
    win->show();
    this->hide();
}

//转到订单管理界面
void MainWindow2::on_OrderButton_clicked()
{
    OrderInfo *win = new OrderInfo;
    win->show();
    this->hide();
}

//转到商品查询界面
void MainWindow2::on_ProductButton_clicked()
{
    ProductSearch *win = new ProductSearch;
    win->show();
    this->hide();
}

//转到购物车界面
void MainWindow2::on_CartButton_clicked()
{
    ShoppingCart *win = new ShoppingCart;
    win->show();
    this->hide();
}

