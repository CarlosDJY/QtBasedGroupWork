#include "balance.h"
#include "accountcontrol.h"
#include "ui_balance.h"
#include <QTimer>

double balance = 45.50;

Balance::Balance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    QTimer *pTimer = new QTimer(this);
    // 设置定时间隔
    pTimer->setInterval(100);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    // 启动定时器
    pTimer->start();
}

Balance::~Balance()
{
    delete ui;
}

void Balance::onTimeOut()
{
    ui->BalanceNum->display(balance);
}


void Balance::on_plus10_clicked()
{
    balance += 10.0;
}


void Balance::on_plus50_clicked()
{
    balance += 50.0;
}


void Balance::on_plus100_clicked()
{
    balance += 100.0;
}


void Balance::on_plusNum_returnPressed()
{
    balance += ui->plusNum->text().toDouble();
    ui->plusNum->clear();
}


void Balance::on_BackButton_clicked()
{
    AccountControl *win = new AccountControl;
    win->show();
    this->close();
}

