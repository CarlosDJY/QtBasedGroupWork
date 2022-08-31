#include "addproduct.h"
#include "ui_addproduct.h"
#include "accountcontrol.h"
#include "accountcontroladmin.h"
#include <QFile>
#include  "login.h"
#include "productsearch.h"
#include <QValidator>
extern Good ExistGoods[100];
extern QString AccountInfomation;
AddProduct::AddProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
    ui->SuperMarket_name->setEnabled(false);
    ui->ProductID->setMaxLength(6);
    QIntValidator* a=new QIntValidator;
    QDoubleValidator* b=new QDoubleValidator;
    QDoubleValidator* c=new QDoubleValidator;
    c->setRange(0,100000);
    b->setRange(0,1);
    a->setRange(1,100000);
    ui->Storage->setValidator(a);
    ui->Discount->setValidator(b);
    ui->Original_Price->setValidator(c);
    ui->ProductID_2->setValidator(c);
    ui->Sale->setValidator(a);
    QFile Q("Users.txt");
    Q.open(QIODevice::ReadOnly);
    while (!Q.atEnd())
    {
        QString P=(QString)Q.readLine();
        QStringList Arr=P.split(" ");
        if(QString::compare(Arr[0],AccountInfomation)==0)
        {
            ui->SuperMarket_name->setText(Arr[6]);
        }
    }
    Q.close();
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_AddToCart_clicked()
{
    int n=SearchByShop(WriteToMemory(),ui->SuperMarket_name->text());
    for (int i = 0; i < n; ++i)
    {
        if(QString::compare(ExistGoods[i].ID,ui->ProductID->text())==0)
        {
            ExistGoods[i].Storage+=ui->Storage->text().toInt();
            for (int i = 0; i < n; ++i)
            {
                if(ExistGoods[i].Discount<1.0&&ExistGoods[i].Discount>0)
                {
                    QFile F("Goods.txt");
                    F.open(QIODevice::WriteOnly);
                    QString Arr=ExistGoods[i].Name+" "+QString::number(ExistGoods[i].SellPrice,'f',2)+" "+ExistGoods[i].Name+" "+QString::number(ExistGoods[i].Discount,'f',2)+" "
                            +ExistGoods[i].Shop+" "+ExistGoods[i].ID+" "+QString::number(ExistGoods[i].Storage)+" "+QString::number(ExistGoods[i].EndTime.tm_year)
                            +" "+QString::number(ExistGoods[i].EndTime.tm_mon)+" "+QString::number(ExistGoods[i].EndTime.tm_mday)
                            +" "+QString::number(ExistGoods[i].EndTime.tm_hour)+" "+QString::number(ExistGoods[i].EndTime.tm_min)
                            +" "+QString::number(ExistGoods[i].StartTime.tm_year)+" "+QString::number(ExistGoods[i].StartTime.tm_mon)
                            +" "+QString::number(ExistGoods[i].StartTime.tm_mday)+" "+QString::number(ExistGoods[i].StartTime.tm_hour)
                            +" "+QString::number(ExistGoods[i].StartTime.tm_min)+" "+QString::number(ExistGoods[i].Sale)+"\n";
                    std::string tmp=Arr.toStdString();
                    const char* sr=tmp.c_str();
                    F.write(sr);
                    F.close();
                }
                else
                {

                    QString Arr=ExistGoods[i].Name+" "+QString::number(ExistGoods[i].SellPrice,'f',2)+" "+ExistGoods[i].Name+" "+QString::number(ExistGoods[i].Discount,'f',2)+" "
                            +ExistGoods[i].Shop+" "+ExistGoods[i].ID+" "+QString::number(ExistGoods[i].Storage)+" "+QString::number(ExistGoods[i].Sale)+"\n";
                    std::string tmp=Arr.toStdString();
                    const char* sr=tmp.c_str();
                    QFile A("Goods.txt");
                    A.open(QIODevice::Append);
                    A.write(sr);
                    A.close();
                }
            }
            break;
        }
    }
    Good G;
    G.Sale=ui->Sale->text().toInt();
    G.ID=ui->ProductID->text();
    G.SellPrice=ui->Original_Price->text().toFloat();
    G.Discount=ui->Discount->text().toFloat();
    G.Name=ui->ProductName->text();
    G.Storage=ui->Storage->text().toInt();
    G.Shop=ui->SuperMarket_name->text();
    if(G.Discount<1.0&&G.Discount>0)
    {
        QString ST=ui->StartTime->text();
        QStringList StartTime_list=ST.split(":");
        QString ET=ui->EndTime->text();
        QStringList EndTime_list=ET.split(":");
        G.StartTime.tm_year=StartTime_list[0].toInt()-1900;
        G.StartTime.tm_mon=StartTime_list[1].toInt()-1;
        G.StartTime.tm_mday=StartTime_list[2].toInt();
        G.StartTime.tm_hour=StartTime_list[3].toInt();
        G.StartTime.tm_min=StartTime_list[4].toInt();
        G.EndTime.tm_year=EndTime_list[0].toInt()-1900;
        G.EndTime.tm_mon=EndTime_list[1].toInt()-1;
        G.EndTime.tm_mday=EndTime_list[2].toInt();
        G.EndTime.tm_hour=EndTime_list[3].toInt();
        G.EndTime.tm_min=EndTime_list[4].toInt();
        QFile F("Goods.txt");
        F.open(QIODevice::Append);
        QString Arr=G.Name+" "+QString::number(G.SellPrice,'f',2)+" "+ui->ProductID_2->text()+" "+QString::number(G.Discount,'f',2)+" "
                +G.Shop+" "+G.ID+" "+QString::number(G.Storage)+" "+QString::number(G.EndTime.tm_year)
                +" "+QString::number(G.EndTime.tm_mon)+" "+QString::number(G.EndTime.tm_mday)
                +" "+QString::number(G.EndTime.tm_hour)+" "+QString::number(G.EndTime.tm_min)
                +" "+QString::number(G.StartTime.tm_year)+" "+QString::number(G.StartTime.tm_mon)
                +" "+QString::number(G.StartTime.tm_mday)+" "+QString::number(G.StartTime.tm_hour)
                +" "+QString::number(G.StartTime.tm_min)+" "+QString::number(G.Sale)+"\n";
        std::string tmp=Arr.toStdString();
        const char* sr=tmp.c_str();
        F.write(sr);
        F.close();
        AccountControlAdmin* win=new AccountControlAdmin;
        win->show();
        this->close();
    }
    if(G.Discount==1.0)
    {
        QString Arr=G.Name+" "+QString::number(G.SellPrice,'f',2)+" "+ui->ProductID_2->text()+" "+QString::number(G.Discount,'f',2)+" "
                +G.Shop+" "+G.ID+" "+QString::number(G.Storage)+" "+QString::number(G.Sale)+"\n";
        std::string tmp=Arr.toStdString();
        const char* sr=tmp.c_str();
        QFile A("Goods.txt");
        A.open(QIODevice::Append);
        A.write(sr);
        A.close();
        AccountControlAdmin* win=new AccountControlAdmin;
        win->show();
        this->close();
    }
    else
    {
        return;
    }
}


void AddProduct::on_BackButton_clicked()
{
    AccountControlAdmin* win=new AccountControlAdmin;
    win->show();
    this->close();
}

