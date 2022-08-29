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

/*
 *
 *暂时缺少判断数据是否合理这一功能；
 *需要添加保存和返回时返回到admin分支；
 *未接入余额与偏好模块(已完成）
 *
 */

//更改用户信息

extern QString AccountInfomation;
int DetailReady = 0;
int NeedEdit = 5;

QFile Account("Users.txt");

QString Arr;
QStringList Ac;
void ReplaceLine(QString AccountID, QString Info);

int Sex = 0;
int SexNotEdit = 1;

AccountDetail::AccountDetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountDetail)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    //ID不可更改
    ui->IDEdit->setReadOnly(true);
    //密码和手机号限制长度
    ui->PasswordEdit->setMaxLength(10);
    ui->PhoneEdit->setMaxLength(11);

    Account.open(QIODevice::ReadOnly);
    //将对应的account数据行读入Ac中
    while(!Account.atEnd()){
        Arr=(QString)Account.readLine();
        Ac=Arr.split(' ');
        if(QString::compare(Ac[0],AccountInfomation)==0)
        {
            Account.close();
            break;
        }
    }
    DetailReady = 7 - Ac.length();
    NeedEdit = 7 - Ac.length();

    while(Ac.length()<9){
        Ac << "";
    }

    //性别暂未设置
    ui->IDEdit->setText(Ac[0]);
    ui->PasswordEdit->setText(Ac[1]);
    ui->NameEdit->setText(Ac[2]);
    ui->MaleChoose->setChecked(Ac[3]=="1");
    ui->FemaleChoose->setChecked(Ac[3]=="2");
    ui->SecretChoose->setChecked(Ac[3]=="3");
    ui->PhoneEdit->setText(Ac[4]);
    ui->MailEdit->setText(Ac[5]);
    ui->AddressEdit->setText(Ac[6]);

}

AccountDetail::~AccountDetail()
{
    delete ui;
}

void AccountDetail::on_ReturnButton_clicked()
{
    if(NeedEdit > 0){
        QMessageBox::warning(this, tr("Warning"), tr("Edit not Complete !"), QMessageBox::Ok);
    }
    else if(!DetailReady){
        QMessageBox::warning(this, tr("Warning"), tr("Save Edit First !"), QMessageBox::Ok);
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

    //尚未完成初次编辑
    if(NeedEdit > 0){
        QMessageBox::warning(this, tr("Warning"), tr("Edit not Complete !"), QMessageBox::Ok);
    }

    //已完成初次编辑
    else {
        //写入Ac
        if(QString::compare(Ac[7],"")==0){
            Ac[7] = "44.5";
        }
        if(QString::compare(Ac[8],"")==0){
            Ac[8] = "222";
        }
        int i = 0;
        while(i < Ac.length()-1){
            if(QString::compare(Ac[i].at(Ac[i].size() - 1),"\n")==0){
                Ac[i].chop(1);
            }
            i++;
        }
        QString AcInfo = Ac.join(" ");
        qDebug() << AcInfo;

        ReplaceLine(AccountInfomation, AcInfo);

        QMessageBox::information(this, tr(""),tr("Data Updated !"), QMessageBox::Ok);

        AccountControl *win = new AccountControl;
        win->show();
        this->hide();
    }
}

//删除对应account的单行内容，并更改为更新后的数据
void ReplaceLine(QString AccountID, QString Info){
    Account.open(QIODevice::ReadOnly);
    QString ArrRp;
    QStringList ArrTag;
    int count = 0;
    ArrRp=(QString)Account.readAll();
    QStringList P = ArrRp.split("\n");

    while(true){
        ArrTag = P[count].split(" ");
        if(QString::compare(ArrTag[0],AccountID)==0){

            P[count] = Info;
            Account.close();

            Account.open(QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream in(&Account);
            for (int i=0; i<P.size(); i++){
                in << P[i] << "\n";
            }
            Account.close();

            break;
        }
        else count++;
    }

}


int NameNotEdit = 1;
void AccountDetail::on_NameEdit_editingFinished()
{
    if(ui->NameEdit->text()!="" && NameNotEdit){
        Ac[2] = ui->NameEdit->text();
        NameNotEdit = 0;
        NeedEdit -= 1;
    }
}


void AccountDetail::on_MaleChoose_clicked()
{
    Sex = 1;
    if(SexNotEdit){
        Ac[3] = "1";
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
}


void AccountDetail::on_FemaleChoose_clicked()
{
    Sex = 2;
    if(SexNotEdit){
        Ac[3] = "2";
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
}


void AccountDetail::on_SecretChoose_clicked()
{
    Sex = 3;
    if(SexNotEdit){
        Ac[3] = "3";
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
}

int PhoneNotEdit = 1;
void AccountDetail::on_PhoneEdit_editingFinished()
{
    if(ui->PhoneEdit->text()!="" && PhoneNotEdit){
        Ac[4] = ui->PhoneEdit->text();
        PhoneNotEdit = 0;
        NeedEdit -= 1;
    }
}

int MailNotEdit = 1;
void AccountDetail::on_MailEdit_editingFinished()
{
    if(ui->MailEdit->text()!="" && MailNotEdit){
        Ac[5] = ui->MailEdit->text();
        MailNotEdit = 0;
        NeedEdit -= 1;
    }
}

int AddressNotEdit = 1;
void AccountDetail::on_AddressEdit_editingFinished()
{
    if(ui->AddressEdit->text()!="" && AddressNotEdit){
        Ac[6] = ui->AddressEdit->text();
        AddressNotEdit = 0;
        NeedEdit -= 1;
    }
}


void AccountDetail::on_PasswordEdit_editingFinished()
{
    if(ui->PasswordEdit->text()!=""){
        Ac[1] = ui->PasswordEdit->text();
    }
}

