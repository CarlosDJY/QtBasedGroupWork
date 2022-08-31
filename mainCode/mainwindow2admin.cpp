#include "mainwindow2admin.h"
#include "accountcontroladmin.h"
#include "orderinfoadmin.h"
#include "productsearchadmin.h"
#include "ui_mainwindow2admin.h"
MainWindow2Admin::MainWindow2Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2Admin)
{
    ui->setupUi(this);
}

MainWindow2Admin::~MainWindow2Admin()
{
    delete ui;
}

void MainWindow2Admin::on_AccountButton_clicked()
{
    AccountControlAdmin *win = new AccountControlAdmin;
    win->show();
    this->hide();
}


void MainWindow2Admin::on_OrderButton_clicked()
{
    OrderInfoAdmin *win = new OrderInfoAdmin;
    win->show();
    this->hide();
}


void MainWindow2Admin::on_ProductButton_clicked()
{
    ProductSearchAdmin *win = new ProductSearchAdmin;
    win->show();
    this->hide();
}

