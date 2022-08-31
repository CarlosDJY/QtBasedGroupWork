#include "paypage.h"
#include "orderinfo.h"
#include "ui_paypage.h"
#include <QTime>
#include <QtGlobal>
#include <QLineEdit>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>


int VerificationCode = 0;
double balancePay;
extern double NumToPay;

double price;

extern QString AccountInfomation;
QFile AccountPay("Users.txt");
QString ArrPay;
QStringList AcPay;

//支付页面，输入验证码以完成支付
PayPage::PayPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PayPage)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    ui->VerifyCodeEdit->setMaxLength(4);

    AccountPay.open(QIODevice::ReadOnly);
    //将对应的account数据行读入Ac中
    while(!AccountPay.atEnd()){
        ArrPay=(QString)AccountPay.readLine();
        AcPay=ArrPay.split(' ');
        qDebug() << AcPay;
        if(QString::compare(AcPay[0],AccountInfomation)==0)
        {
            AccountPay.close();
            break;
        }
    }
    balancePay = AcPay[7].toDouble();
    price = NumToPay;
    ui->PriceNumber->display(price);

    //随机生成验证码
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));
    VerificationCode = rand()%9000 + 1000;
    ui->VerifyNumber->display(VerificationCode);
}

PayPage::~PayPage()
{
    delete ui;
}

//取消支付，跳转到订单界面
void PayPage::on_Cancel_clicked()
{
    OrderInfo *win = new OrderInfo;
    win->show();
    this->hide();
}

void ReplaceLinePay(QString AccountID, QString Info){
    AccountPay.open(QIODevice::ReadOnly);
    QString ArrRp;
    QStringList ArrTag;
    int count = 0;
    ArrRp=(QString)AccountPay.readAll();
    QStringList P = ArrRp.split("\n");

    while(true){
        ArrTag = P[count].split(" ");
        if(QString::compare(ArrTag[0],AccountID)==0){

            P[count] = Info;
            AccountPay.close();

            AccountPay.open(QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream in(&AccountPay);
            for (int i=0; i<P.size(); i++){
                in << P[i] << "\n";
            }
            AccountPay.close();
            break;
        }
        else count++;
    }
}

//确认支付，如验证码正确则完成支付
//缺少扣款部分
void PayPage::on_Confirm_clicked()
{
    if(balancePay >= price){
        if(VerificationCode == ui->VerifyCodeEdit->text().toInt()){

            balancePay -= price;
            int i = 0;
            while(i < AcPay.length()-1){
                if(QString::compare(AcPay[i].at(AcPay[i].size() - 1),"\n")==0){
                    AcPay[i].chop(1);
                }
                i++;
            }
            AcPay[7] = QString::number(balancePay, 'f', 2);
            QString AcInfoPay = AcPay.join(" ");
            qDebug() << AcInfoPay;
            ReplaceLinePay(AccountInfomation, AcInfoPay);
            QFile Good("Goods.txt");
            Good.open(QIODevice::ReadWrite);

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
    else{
        QMessageBox::warning(this, tr("Warning"), tr("Not enough money !"), QMessageBox::Ok);
    }

}

