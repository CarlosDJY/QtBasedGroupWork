#include "accountdetail.h"
#include "accountcontrol.h"
#include "accountcontroladmin.h"
#include "ui_accountdetail.h"
#include <stdio.h>
#include "login.h"
#include <QLineEdit>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>

using namespace std;

/*
 *
 *暂时缺少判断数据是否合理这一功能；
 *未接入余额与偏好模块(已完成）
 *
 */

//更改用户信息

extern QString AccountInfomation;
QString ShopInfo;
int DetailReady = 0;
int NeedEdit = 5;
extern int IsAdmin;
QFile Account("Users.txt");

QString Arr;
QStringList Ac;
QStringList Mail;
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
    if(IsAdmin==1)
    {
        ui->AddressLabel->setText("超市名称");
    }
    if(IsAdmin==0)
    {
        ui->AddressLabel->setText("收货地址");
    }
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

    //用于判断剩余待编辑项
    DetailReady = 7 - Ac.length();
    NeedEdit = 7 - Ac.length();

    //补全Account信息的长度
    while(Ac.length()<9){
        Ac << "";
    }

    //设置初始信息
    ui->IDEdit->setText(Ac[0]);
    ui->PasswordEdit->setText(Ac[1]);
    if(Ac[2]=="1\n"||Ac[2]=="0\n")
    {
        Ac[2]="";
    }
    ui->NameEdit->setText(Ac[2]);
    ui->MaleChoose->setChecked(Ac[3]=="1");
    ui->FemaleChoose->setChecked(Ac[3]=="2");
    ui->SecretChoose->setChecked(Ac[3]=="3");
    ui->PhoneEdit->setText(Ac[4]);
    ui->MailEdit->setText(Ac[5]);
    ui->AddressEdit->setText(Ac[6]);
    ShopInfo=Ac[6];
}

AccountDetail::~AccountDetail()
{
    delete ui;
}

void AccountDetail::on_ReturnButton_clicked()
{
    //未完成编辑时报错
    if(NeedEdit > 0){
        QMessageBox::warning(this, tr("Warning"), tr("Edit not Complete !"), QMessageBox::Ok);
    }
    //未完成初次编辑时报错
    else if(!DetailReady){
        QMessageBox::warning(this, tr("Warning"), tr("Save Edit First !"), QMessageBox::Ok);
    }
    //返回
    else{
            if(IsAdmin==1)
            {
                AccountControlAdmin* win=new AccountControlAdmin;
                win->show();
                this->close();
            }
            else
            {
                AccountControl* win=new AccountControl;
                win->show();
                this->close();
            }
        }
}


void AccountDetail::on_SaveButton_clicked()
{
    //update all data "Account.txt",

    //尚未完成初次编辑
    if(NeedEdit > 0){
        qDebug()<<NeedEdit;
        QMessageBox::warning(this, tr("Warning"), tr("Edit not Complete !"), QMessageBox::Ok);
    }

    //已完成初次编辑
    else {
        if(QString::compare(Ac[7],"")==0){
            Ac[7] = "44.5";
        }
        if(QString::compare(Ac[8],"")==0){
            Ac[8] = "222";
        }
        int ValidMail = 0;
        Mail = Ac[5].split("@");
        qDebug() << Mail;
        if (Mail.length() == 2) {
            QStringList MailLast = Mail[1].split(".");
            qDebug() << MailLast;
            if (MailLast.length()>=2) {
                ValidMail = 1;
            }
        }
        int ValidPhone = -10;
        QString Phone = Ac[4];
        Phone.remove(QRegularExpression("[0-9]"));
        ValidPhone += Ac[4].length() - Phone.length();;
        if(ValidMail <= 0){
            QMessageBox::warning(this, tr("Warning"), tr("Invalid Mail !"), QMessageBox::Ok);
        }
        else if(ValidPhone <= 0){
            qDebug() << ValidPhone;
            QMessageBox::warning(this, tr("Warning"), tr("Invalid Phone !"), QMessageBox::Ok);
        }
        else
        {
            int i = 0;
            qDebug()<<"Ac" << Ac;
            while(i < Ac.length()){
                //Ac[i].remove(" ");
                if(QString::compare(Ac[i].at(Ac[i].size() - 1),"\n")==0){
                    Ac[i].chop(1);
                }
                i++;
            }
            //合并全部信息
            QString AcInfo = Ac.join(" ");
            qDebug() << AcInfo;
            AcInfo.remove("/n");
            if(Ac[Ac.length()-1] == QString("1") || Ac[Ac.length()-1] == QString("0")){
                AcInfo.chop(2);
            }
            AcInfo=AcInfo + " " + QString::number(IsAdmin) + "\n";
            qDebug() <<  "AcInfo" << AcInfo;

            //取代原先的信息行
            ReplaceLine(AccountInfomation, AcInfo);

            //完成编辑
            QMessageBox::information(this, tr(""),tr("Data Updated !"), QMessageBox::Ok);
            if(IsAdmin==1)
            {
                AccountControlAdmin* win=new AccountControlAdmin;
                win->show();
                this->close();
            }
            else
            {
                AccountControl* win=new AccountControl;
                win->show();
                this->close();
            }

        }
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
            //改写文件内容
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

//判断是否被编辑过
int NameNotEdit = 1;
void AccountDetail::on_NameEdit_editingFinished()
{
    if(ui->NameEdit->text()!=""){
        if(NameNotEdit){
            NameNotEdit = 0;
            NeedEdit -= 1;
        }
        Ac[2] = ui->NameEdit->text();
    }
}



void AccountDetail::on_MaleChoose_clicked()
{
    Sex = 1;
    if(SexNotEdit){
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
    Ac[3] = "1";
}


void AccountDetail::on_FemaleChoose_clicked()
{
    Sex = 2;
    if(SexNotEdit){
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
    Ac[3] = "2";
}


void AccountDetail::on_SecretChoose_clicked()
{
    Sex = 3;
    if(SexNotEdit){
        SexNotEdit = 0;
        NeedEdit -= 1;
    }
    Ac[3] = "3";
}

int PhoneNotEdit = 1;
void AccountDetail::on_PhoneEdit_editingFinished()
{
    if(ui->PhoneEdit->text()!=""){
        if(PhoneNotEdit){
            PhoneNotEdit = 0;
            NeedEdit -= 1;
        }
        Ac[4] = ui->PhoneEdit->text();
    }
}

int MailNotEdit = 1;
void AccountDetail::on_MailEdit_editingFinished()
{
    if(ui->MailEdit->text()!=""){
        if(MailNotEdit){
            MailNotEdit = 0;
            NeedEdit -= 1;
        }
        Ac[5] = ui->MailEdit->text();
    }
}

int AddressNotEdit = 1;
void AccountDetail::on_AddressEdit_editingFinished()
{
    if(ui->AddressEdit->text()!=""){
        if(AddressNotEdit){
            AddressNotEdit = 0;
            NeedEdit -= 1;
        }
        Ac[6] = ui->AddressEdit->text();
    }
}


void AccountDetail::on_PasswordEdit_editingFinished()
{
    if(ui->PasswordEdit->text()!=""){
        Ac[1] = ui->PasswordEdit->text();
    }
}

