#include "mainwindow2.h"
#include "accountcontrol.h"
#include "orderinfo.h"
#include "ProductSearch.h"
#include "ui_mainwindow2.h"

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

void MainWindow2::on_AccountButton_clicked()
{
    AccountControl *win = new AccountControl;
    win->show();
    this->hide();
}


void MainWindow2::on_OrderButton_clicked()
{
    OrderInfo *win = new OrderInfo;
    win->show();
    this->hide();
}


void MainWindow2::on_ProductButton_clicked()
{
    ProductSearch *win = new ProductSearch;
    win->show();
    this->hide();
}

