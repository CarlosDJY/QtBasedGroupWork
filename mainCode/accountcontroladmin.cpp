#include "accountcontroladmin.h"
#include "accountdetail.h"
#include "mainwindow.h"
#include "mainwindow2admin.h"
#include "ui_accountcontroladmin.h"

AccountControlAdmin::AccountControlAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountControlAdmin)
{
    ui->setupUi(this);
}

AccountControlAdmin::~AccountControlAdmin()
{
    delete ui;
}

void AccountControlAdmin::on_AccountButton_clicked()
{
    AccountDetail *win = new AccountDetail;
    win->show();
    this->close();
}

void AccountControlAdmin::on_LogOutButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}


void AccountControlAdmin::on_BackButton_clicked()
{
    MainWindow2Admin *win = new MainWindow2Admin;
    win->show();
    this->close();
}

