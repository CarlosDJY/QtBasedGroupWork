#include "productinfo.h"
#include "ui_productinfo.h"
#include "shoppingcart.h"
#include "productsearch.h"
#include <QFile>
#include <time.h>
#include "login.h"
#include <QFileInfo>
extern QString AccountInfomation;
extern int IsAdmin;
QString ShopName;
Shoppingcars Exist[100];
int Storage;
ProductInfo::ProductInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    if(IsAdmin==1)
    {
        ui->AddToCart->setEnabled(false);
    }
    QFile Q("temp.txt");
    Q.open(QIODevice::ReadOnly);
    QString Tmp=(QString)Q.readLine();
    QStringList L=Tmp.split(' ');
    int length=L.length();
    ui->Sale->setText(L[length-1]);
    ui->ProductID->setText(L[0]);
    ui->ProductName->setText(L[1]);
    ui->Price->setText(L[2]);
    ui->SupermarketID->setText(L[3]);
    ShopName=L[3];
    float Discount=L[4].toFloat();
    Storage=L[5].toInt();
    ui->DiscountPrice->setText(QString::number(Discount,'f',2));
    if(Discount!=1.0)
    {
        const time_t StartTime_t=L[5].toInt();
        const time_t EndTime_t=L[6].toInt();

        struct tm StartTime_struct;
        struct tm EndTime_struct;
        localtime_s(&StartTime_struct,&StartTime_t);
        localtime_s(&EndTime_struct,&EndTime_t);
        qDebug()<<EndTime_struct.tm_year+1900;
        QString ST=QString("%1:%2:%3:%4:%5").arg(StartTime_struct.tm_year+1900,4,10,QLatin1Char('0')).arg(StartTime_struct.tm_mon+1,2,10,QLatin1Char('0')).arg(StartTime_struct.tm_mday,2,10,QLatin1Char('0')).arg(StartTime_struct.tm_hour,2,10,QLatin1Char('0')).arg(StartTime_struct.tm_min,2,10,QLatin1Char('0'));
        QString ET=QString("%1:%2:%3:%4:%5").arg(EndTime_struct.tm_year+1900,4,10,QLatin1Char('0')).arg(EndTime_struct.tm_mon+1,2,10,QLatin1Char('0')).arg(EndTime_struct.tm_mday,2,10,QLatin1Char('0')).arg(EndTime_struct.tm_hour,2,10,QLatin1Char('0')).arg(EndTime_struct.tm_min,2,10,QLatin1Char('0'));
        ui->StartTime->setText(ST);
        ui->EndTime->setText(ET);
    }

}
ProductInfo::~ProductInfo()
{
    delete ui;
}
int SetToMemory()
{
    QString FileName="["+AccountInfomation+"]"+"cart"+"[123]"+".txt";
    QFileInfo F(FileName);
    if(!F.exists()){
        return 0;
    }
    else{
        QFile Q(FileName);
        Q.open(QIODevice::ReadOnly);
        int i=0;
        while (!Q.atEnd()) {
            QString Line=(QString)Q.readLine();
            QStringList ProductInfo=Line.split(" ");
            Exist[i].ID=ProductInfo[0];
            Exist[i].Name=ProductInfo[1];
            Exist[i].Num=ProductInfo[2].toInt();
            Exist[i].SellPrice=ProductInfo[3].toFloat();
            Exist[i].Storage=ProductInfo[4].toInt();
            i++;
        }
        Q.close();
        return i;
    }
}
void ProductInfo::on_AddToCart_clicked()
{
   Shoppingcars C;
   C.ID=ui->ProductID->text();
   C.Num=ui->GoodsNumber->text().toInt();
   C.Name=ui->ProductName->text();
   C.SellPrice=ui->Price->text().toFloat();
   QString FileName=AccountInfomation+" "+"cart"+" "+ui->SupermarketID->text()+".txt";
   std::string s=FileName.toStdString();
   const char* res=s.c_str();
   QFile q(res);
   q.open(QIODevice::WriteOnly);
   int i=0;
   int n=SetToMemory();
   if(C.Num>Storage)
   {
        QMessageBox::warning(this, tr("Warning"), tr("没这么多库存"), QMessageBox::Ok);
        return;
   }
   if(n==0)
   {
       QString tmp=ui->ProductID->text()+" "+ui->ProductName->text()+" "+ui->GoodsNumber->text()+" "+QString::number(ui->Price->text().toFloat(),'f',2)+"\n";
       std::string b=tmp.toStdString();
       const char* c=b.c_str();
       q.write(c);
       q.close();
   }
   else
   {
       while(i<n)
       {
           if(QString::compare(Exist[i].ID,C.ID)==0)
           {
               Exist[i].Num=C.Num+Exist[i].Num;
               break;
           }
           else
           {
               i++;
           }
       }
   }
   qDebug()<<Exist[0].Name;
   if(i==n)
   {
       Exist[n].ID=C.ID;
       Exist[n].Name=C.Name;
       Exist[n].SellPrice=C.SellPrice;
       Exist[n].Num=C.Num;
       n++;
   }
   qDebug()<<Exist[1].SellPrice;
   for(i=0;i<n;i++)
   {
          QString Arr=Exist[i].ID+" "+Exist[i].Name+" "+QString::number(Exist[i].Num,10)+" "+QString::number(Exist[i].SellPrice,'f',2)+"\n";
          std::string temp=Arr.toStdString();
          const char* data=temp.c_str();
          q.write(data);
   }
   q.close();
   ShoppingCart* win=new ShoppingCart();
   win->show();
   this->close();
}

void ProductInfo::on_BackButton_clicked()
{
    ProductSearch* win=new ProductSearch();
    win->show();
    this->close();
}


