#include "accountcontrol.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "accountdetail.h"
#include "balance.h"
#include "preference.h"
#include "ui_accountcontrol.h"

AccountControl::AccountControl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountControl)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
}

AccountControl::~AccountControl()
{
    delete ui;
}

void AccountControl::on_LogOutButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}


void AccountControl::on_AccountButton_clicked()
{
    AccountDetail *win = new AccountDetail;
    win->show();
    this->close();
}


void AccountControl::on_PreferenceButton_clicked()
{
    Preference *win = new Preference;
    win->show();
    this->close();
}


void AccountControl::on_BalanceButton_clicked()
{
    Balance *win = new Balance;
    win->show();
    this->close();
}


void AccountControl::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

