#include "preference.h"
#include "accountcontrol.h"
#include "ui_preference.h"
#include <QLineEdit>
#include <QFile>
#include <QFileInfo>
#include <QRadioButton>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

extern QString AccountInfomation;
QFile AccountP("Users.txt");
QString ArrP;
QStringList AcP;
int preference;
int PricePre, DiscountPre, SalesPre;

Preference::Preference(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    QButtonGroup *Price=new QButtonGroup(this);
    QButtonGroup *Discount=new QButtonGroup(this);
    QButtonGroup *Sales=new QButtonGroup(this);

    Price->addButton(ui->PriceHigh,1);
    Price->addButton(ui->PriceLow,0);
    Discount->addButton(ui->DiscountHigh,1);
    Discount->addButton(ui->DiscountLow,0);
    Sales->addButton(ui->SalesHigh,1);
    Sales->addButton(ui->SalesLow,0);

    AccountP.open(QIODevice::ReadOnly);
    //将对应的account数据行读入Ac中
    while(!AccountP.atEnd()){
        ArrP=(QString)AccountP.readLine();
        AcP=ArrP.split(' ');
        qDebug() << AcP;
        if(QString::compare(AcP[0],AccountInfomation)==0)
        {
            AccountP.close();
            break;
        }
    }
    //QString tmp = AcP[8];
    //tmp.chop(2);
    preference = AcP[8].toInt();

    PricePre = preference / 100;
    DiscountPre = (preference - 100 * PricePre) / 10;
    SalesPre = (preference - 100 * PricePre - 10 * DiscountPre);

    ui->PriceHigh->setChecked(PricePre==1);
    ui->PriceLow->setChecked(PricePre==2);
    ui->DiscountHigh->setChecked(DiscountPre==1);
    ui->DiscountLow->setChecked(DiscountPre==2);
    ui->SalesHigh->setChecked(SalesPre==1);
    ui->SalesLow->setChecked(SalesPre==2);
}

Preference::~Preference()
{
    delete ui;
}

void ReplaceLineP(QString AccountID, QString Info){
    AccountP.open(QIODevice::ReadOnly);
    QString ArrRp;
    QStringList ArrTag;
    int count = 0;
    ArrRp=(QString)AccountP.readAll();
    QStringList P = ArrRp.split("\n");

    while(true){
        ArrTag = P[count].split(" ");
        if(QString::compare(ArrTag[0],AccountID)==0){

            P[count] = Info;
            AccountP.close();

            AccountP.open(QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream in(&AccountP);
            for (int i=0; i<P.size(); i++){
                in << P[i] << "\n";
            }
            AccountP.close();
            break;
        }
        else count++;
    }
}

void Preference::on_BackButton_clicked()
{
    preference = 100 * PricePre + 10 * DiscountPre + SalesPre;
    if(QString::compare(AcP[1].at(AcP[1].size() - 1),"\n")==0){
        AcP[1].chop(1);
    }
    AcP[8] = QString::number(preference);

    QString AcInfoB = AcP.join(" ");
    qDebug() << AcInfoB;
    ReplaceLineP(AccountInfomation, AcInfoB);

    AccountControl *win = new AccountControl;
    win->show();
    this->close();
}


void Preference::on_PriceHigh_clicked()
{
    PricePre = 1;
}


void Preference::on_PriceLow_clicked()
{
    PricePre = 2;
}


void Preference::on_DiscountHigh_clicked()
{
    DiscountPre = 1;
}


void Preference::on_DiscountLow_clicked()
{
    DiscountPre = 2;
}


void Preference::on_SalesHigh_clicked()
{
    SalesPre = 1;
}


void Preference::on_SalesLow_clicked()
{
    SalesPre = 2;
}

