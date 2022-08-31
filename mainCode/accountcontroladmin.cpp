#include "accountcontroladmin.h"
#include "accountdetail.h"
#include "mainwindow.h"
#include "ui_accountcontroladmin.h"
#include "mainwindow2.h"
#include "addproduct.h"
#include <QFile>
extern QString AccountInfomation;
AccountControlAdmin::AccountControlAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountControlAdmin)
{
    ui->setupUi(this);
    ui->PreferenceButton->setEnabled(false);
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
                ui->AddNewItem->setEnabled(false);
                ui->PreferenceButton->setEnabled(false);
            }
            else
            {
                ui->AddNewItem->setEnabled(true);
                ui->PreferenceButton->setEnabled(false);
            }
        }
    }

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
   qApp->quit();
}


void AccountControlAdmin::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

void AccountControlAdmin::on_AddNewItem_clicked()
{
    AddProduct* win=new AddProduct;
    win->show();
    this->close();
}

