#include "mainwindow2.h"
#include "accountdetail.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    if(!DetailReady){
        ui->OrderButton->setEnabled(false);
        ui->ProductButton->setEnabled(false);
    }
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_AccountButton_clicked()
{
    AccountDetail *win = new AccountDetail;
    win->show();
    this->close();
}
