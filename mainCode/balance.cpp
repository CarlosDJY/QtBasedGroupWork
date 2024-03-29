#include "balance.h"
#include "accountcontrol.h"
#include "ui_balance.h"
#include <QTimer>
#include <QLineEdit>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

extern QString AccountInfomation;
QFile AccountB("Users.txt");
QString ArrB;
QStringList AcB;

//初始账户余额
double balance;

//账户余额查询与充值
Balance::Balance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    //即时刷新剩余金额
    QTimer *pTimer = new QTimer(this);
    //设置定时间隔
    pTimer->setInterval(100);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    //启动定时器
    pTimer->start();

    AccountB.open(QIODevice::ReadOnly);
    //将对应的account数据行读入Ac中
    while(!AccountB.atEnd()){
        ArrB=(QString)AccountB.readLine();
        AcB=ArrB.split(' ');
        qDebug() << AcB;
        if(QString::compare(AcB[0],AccountInfomation)==0)
        {
            AccountB.close();
            break;
        }
    }
    balance = AcB[7].toDouble();
}

Balance::~Balance()
{
    delete ui;
}

//显示余额
void Balance::onTimeOut()
{
    ui->BalanceNum->display(balance);
}

//+10r
void Balance::on_plus10_clicked()
{
    balance += 10.0;
}

//+50r
void Balance::on_plus50_clicked()
{
    balance += 50.0;
}

//+100r
void Balance::on_plus100_clicked()
{
    balance += 100.0;
}

//自定义增加金额数目
void Balance::on_plusNum_returnPressed()
{
    balance += ui->plusNum->text().toDouble();
    ui->plusNum->clear();
}

void ReplaceLineB(QString AccountID, QString Info){
    AccountB.open(QIODevice::ReadOnly);
    QString ArrRp;
    QStringList ArrTag;
    int count = 0;
    ArrRp=(QString)AccountB.readAll();
    QStringList P = ArrRp.split("\n");

    //判断是否匹配对应账户
    while(true){
        ArrTag = P[count].split(" ");
        if(QString::compare(ArrTag[0],AccountID)==0){

            P[count] = Info;
            AccountB.close();

            //更改数据
            AccountB.open(QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream in(&AccountB);
            for (int i=0; i<P.size(); i++){
                in << P[i] << "\n";
            }
            AccountB.close();
            break;
        }
        else count++;
    }
}

//返回用户管理界面，同时更新余额
void Balance::on_BackButton_clicked()
{
    //更新余额
    //写入AcB
    int i = 0;
    while(i < AcB.length()-1){
        if(QString::compare(AcB[i].at(AcB[i].size() - 1),"\n")==0){
            AcB[i].chop(1);
        }
        i++;
    }
    //两位小数的余额
    AcB[7] = QString::number(balance, 'f', 2);
    QString AcInfoB = AcB.join(" ");
    qDebug() << AcInfoB;

    ReplaceLineB(AccountInfomation, AcInfoB);
    //返回
    AccountControl *win = new AccountControl;
    win->show();
    this->close();
}

