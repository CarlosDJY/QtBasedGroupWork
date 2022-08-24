#include "paypage.h"
#include "orderinfo.h"
#include "ui_paypage.h"

int VerificationCode = 1234;

PayPage::PayPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PayPage)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    ui->VerifyNumber->display(VerificationCode);
    ui->VerifyCodeEdit->setMaxLength(4);
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
        QMessageBox::information(this,tr("Payment"),tr("Payment Complete !"), QMessageBox::Yes);

        OrderInfo *win = new OrderInfo;
        win->show();
        this->hide();
    }
    else{
        ui->VerifyCodeEdit->clear();
        QMessageBox::warning(this, tr("Warning"), tr("Verification Code Error !"), QMessageBox::Yes);
    }


}

