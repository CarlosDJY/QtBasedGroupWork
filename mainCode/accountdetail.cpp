#include "accountdetail.h"
#include "accountcontrol.h"
#include "ui_accountdetail.h"
#include <stdio.h>
#include <QLineEdit>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

using namespace std;

int DetailReady = 0;
int NeedEdit = 5;

QFile Account("Users.txt");

QString Arr;

int editCount = 0;
int Sex = 0;
int SexNotEdit = 1;

AccountDetail::AccountDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountDetail)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    ui->IDEdit->setReadOnly(true);
    ui->PasswordEdit->setMaxLength(10);
    ui->PhoneEdit->setMaxLength(13);

    Account.open(QIODevice::ReadOnly);
    Arr=(QString)Account.readAll();
    QStringList P = Arr.split("\n");
    qDebug() << Arr;
    qDebug() << P;
}

AccountDetail::~AccountDetail()
{
    delete ui;
}

bool isDetailReady(){
    return DetailReady;
}

void AccountDetail::on_ReturnButton_clicked()
{
    if(NeedEdit > 0){
        QMessageBox::warning(this, tr("Warning"), tr("Edit not Complete !"), QMessageBox::Ok);
    }
    else if(DetailReady == 0){
        QMessageBox::warning(this, tr("Warning"), tr("Save Edit First !"), QMessageBox::Ok);
    }
    else if(editCount != 0){
        QMessageBox::warning(this, tr("Warning"), tr("Changes not Saved !"), QMessageBox::Ok);
    }
    else{
        AccountControl *win = new AccountControl;
        win->show();
        this->hide();
    }
}


void AccountDetail::on_SaveButton_clicked()
{
    //update all data "Account.txt",

    if(NeedEdit != 0){
        Account.open(QIODeviceBase::ReadWrite);
        QByteArray str;
        str = QString::fromStdString("ERROR\n").toUtf8();
        Account.write(str);
        Account.close();
        QMessageBox::warning(this, tr("Warning"), tr("Edit not Complete !"), QMessageBox::Ok);

    }
    else if(DetailReady == 0){
        Account.open(QIODeviceBase::ReadWrite);
        QByteArray str;
        str = ui->IDEdit->text().toUtf8();
        Account.write(str);
        str = ui->NameEdit->text().toUtf8();
        Account.write(str);
        str = ui->PasswordEdit->text().toUtf8();
        Account.write(str);
        str = QString::fromStdString("123123").toUtf8();
        Account.write(str);
        Account.close();

        DetailReady = 1;
        editCount = 0;
        AccountControl *win = new AccountControl;
        win->show();
        this->hide();
    }
    else {
        Account.open(QIODeviceBase::ReadWrite);
        QByteArray str;
        str = QString::fromStdString("123123").toUtf8();
        Account.write(str);
        Account.close();

        editCount = 0;
        AccountControl *win = new AccountControl;
        win->show();
        this->hide();
    }
}

int NameNotEdit = 1;
void AccountDetail::on_NameEdit_editingFinished()
{
    if(ui->NameEdit->text()!="" && NameNotEdit){
        NeedEdit -= 1;
    }
}


void AccountDetail::on_MaleChoose_clicked()
{
    Sex = 1;
    if(SexNotEdit){
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
}


void AccountDetail::on_FemaleChoose_clicked()
{
    Sex = 2;
    if(SexNotEdit){
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
}


void AccountDetail::on_SecretChoose_clicked()
{
    Sex = 3;
    if(SexNotEdit){
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
}

int PhoneNotEdit = 1;
void AccountDetail::on_PhoneEdit_editingFinished()
{
    if(ui->PhoneEdit->text()!="" && PhoneNotEdit){
        NeedEdit -= 1;
    }
}

int MailNotEdit = 1;
void AccountDetail::on_MailEdit_editingFinished()
{
    if(ui->MailEdit->text()!="" && MailNotEdit){
        NeedEdit -= 1;
    }
}

int AddressNotEdit = 1;
void AccountDetail::on_AddressEdit_editingFinished()
{
    if(ui->AddressEdit->text()!="" && AddressNotEdit){
        NeedEdit -= 1;
    }
}

