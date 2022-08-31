#include "accountcontrol.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "accountdetail.h"
#include "balance.h"
#include "preference.h"
#include "ui_accountcontrol.h"
#include <QFile>
extern QString  AccountInfomation;
//账号管理界面，导航至用户信息更改、余额充值、用户偏好更改、登出
AccountControl::AccountControl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountControl)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    QFile User("Users.txt");
    User.open(QIODevice::ReadOnly);

    while(!User.atEnd())
    {
        QString Arr=(QString)User.readLine();
        qDebug()<<Arr;
        QStringList Tmp=Arr.split(" ");
        if(QString::compare(Tmp[0],AccountInfomation)==0)
        {
            if(QString::compare(Tmp[2],"0\n")==0||QString::compare(Tmp[2],"1\n")==0)
            {
                ui->BalanceButton->setEnabled(false);
                ui->PreferenceButton->setEnabled(false);
            }
            else
            {
                ui->BalanceButton->setEnabled(true);
                ui->PreferenceButton->setEnabled(true);
            }
        }
    }
}

AccountControl::~AccountControl()
{
    delete ui;
}

//退出登录，回到主界面1
void AccountControl::on_LogOutButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}

//更改用户信息
void AccountControl::on_AccountButton_clicked()
{
    AccountDetail *win = new AccountDetail;
    win->show();
    this->close();
}

//更改用户偏好
void AccountControl::on_PreferenceButton_clicked()
{
    Preference *win = new Preference;
    win->show();
    this->close();
}

//用户余额充值
void AccountControl::on_BalanceButton_clicked()
{
    Balance *win = new Balance;
    win->show();
    this->close();
}

//返回主菜单
void AccountControl::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

