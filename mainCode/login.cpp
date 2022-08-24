#include "mainwindow.h"
#include "mainwindow2.h"
#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <stdio.h>
#include <QFile>
#include <qstring.h>
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

void Login::on_BackButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}

int isExistingAccount(QString Q){
    QFile File1("Users.txt");
    File1.open(QIODevice::ReadOnly);
    QString Arr;
    int i=0;
    while(!File1.atEnd())
       {
         Arr=(QString)File1.readLine();
         QStringList P=Arr.split(' ');
         if(QString::compare(P[0],Q)==0)
            {
                    File1.close();
                    return true;
            }
       }
    File1.close();
    return false;
}

int isMappingPassword(QString Account, QString Password){
    QFile File1("Users.txt");
    File1.open(QIODevice::ReadOnly);
    QString Arr;
    int i=0;
    while(!File1.atEnd())
    {
         Arr=(QString)File1.readLine();
         QStringList P=Arr.split(' ');
         if(isExistingAccount(Account))
         {
             qDebug()<<"rua";
             if(QString::compare(P[1],Password)==0)
             {
                 return true;
             }
         }
    }
    return false;
}

void Login::on_ConfirmButton_clicked()
{
    if(isExistingAccount(ui->AccountLineEdit->text())) {
        QString Account = ui->AccountLineEdit->text();
        if(isMappingPassword(Account, ui->PasswordLineEdit->text()))
        {
            MainWindow2 *win = new MainWindow2;
            win->show();
            this->close();
        }
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("User name or Password error !"), QMessageBox::Yes);
    }
}

