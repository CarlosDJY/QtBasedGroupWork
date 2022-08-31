#include "mainwindow.h"
#include "mainwindow2.h"
#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <stdio.h>
#include <QFile>
#include <qstring.h>
#include "register.h"
QFile File1("Users.txt");
QString AccountInfomation;
int IsAdmin;
//登录模块
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

//返回主界面
void Login::on_BackButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}

//检测用户ID是否存在
int isExistingAccount(QString Q){
    if(!File1.isOpen()){
        File1.open(QIODevice::ReadOnly);
    }
    QString Arr;
    while(!File1.atEnd())
       {
         Arr=(QString)File1.readLine();
         QStringList P=Arr.split(' ');
         if(QString::compare(P[0],Q)==0)
            {
                    qDebug() << "ID" << P[0];
                    File1.close();
                    return true;
            }
       }
    File1.close();
    return false;
}

//检测用户ID对应的密码是否正确
int isMappingPassword(QString Account, QString Password){

    if(!File1.isOpen()){
        File1.open(QIODevice::ReadOnly);
    }
    QString Arr;
    QStringList P;

    while(!File1.atEnd()){
        Arr=(QString)File1.readLine();
        Arr.remove("\n");
        P=Arr.split(' ');
        if(P.length()>1){
            if(QString::compare(P[0],Account)==0 && QString::compare(P[1],Password)==0)
            {
                qDebug() << "PW" << P[1];
                AccountInfomation = P[0];
                int length=P.length();
                IsAdmin=P[length-1].toInt();
                File1.close();
                return true;
            }
        }
    }
    File1.close();
    return false;
}

//确认登录
void Login::on_ConfirmButton_clicked()
{
    if(isExistingAccount(ui->AccountLineEdit->text())){
        QString AccountTmp = ui->AccountLineEdit->text();
        if(isMappingPassword(AccountTmp, ui->PasswordLineEdit->text()))
        {
                MainWindow2 *win=new MainWindow2;
                win->show();
                this->close();
        }
        else{
            QMessageBox::warning(this, tr("Warning"), tr("User name or Password error !"), QMessageBox::Ok);
        }
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("User name or Password error !"), QMessageBox::Ok);
    }
}
