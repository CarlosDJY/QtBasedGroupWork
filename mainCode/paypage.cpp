#include "paypage.h"
#include "orderinfo.h"
#include "ui_paypage.h"
#include <QTime>
#include <QtGlobal>

int VerificationCode = 0;

PayPage::PayPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PayPage)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    ui->VerifyCodeEdit->setMaxLength(4);

    srand(QTime(0,0,0).secsTo(QTime::currentTime()));
    VerificationCode = rand()%9000 + 1000;
    ui->VerifyNumber->display(VerificationCode);
}

PayPage::~PayPage()
{
    delete ui;
}

void PayPage::on_Cancel_clicked()
{
    OrderInfo *win = new OrderInfo;
    win->show();
    this->hide();
}


void PayPage::on_Confirm_clicked()
{
    if(VerificationCode == ui->VerifyCodeEdit->text().toInt()){
        QMessageBox::information(this,tr("Payment"),tr("Payment Complete !"), QMessageBox::Ok);

        OrderInfo *win = new OrderInfo;
        win->show();
        this->hide();
    }
    else{
        ui->VerifyCodeEdit->clear();
        QMessageBox::warning(this, tr("Warning"), tr("Verification Code Error !"), QMessageBox::Ok);
    }


}

