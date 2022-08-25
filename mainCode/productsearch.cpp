#include "productsearch.h"
#include "mainwindow2.h"
#include "ui_productsearch.h"
#include <QFile>
#include "productsearch.h"
#include <ctime>
#include <QString>
Good ExistGoods[100];
Good Tmp[100];
void Test()
{
    QFile Q("Goods.txt");
    Q.open(QIODevice::Append);
    Q.write("A 2.0 1.0 1.0 1 AA0001 1 1000 2000\n");
    Q.write("A 30.0 30.0 1.0 2 AA0001 1 1000 2000\n");
    Q.write("B 19.0 1.0 1.0 1 AA0002 1 1000 2000\n");
    Q.write("B 1.0 1.0 0.8 2 AA0002 1 1000 2000\n");
    Q.close();
}
int WriteToMemory()
{
        int i=0;
        QFile Q("Goods.txt");
        Q.open(QIODevice::ReadOnly);
        while(!Q.atEnd())
        {
            QString Arr=(QString)Q.readLine();
            QStringList P=Arr.split(' ');
            ExistGoods[i].Name=P[0];
            ExistGoods[i].SellPrice=P[1].toFloat();
            ExistGoods[i].BuyPrice=P[2].toFloat();
            ExistGoods[i].Discount=P[3].toFloat();
            ExistGoods[i].Shop=P[4];
            ExistGoods[i].ID=P[5];
            ExistGoods[i].Storage=P[6].toInt();
            ExistGoods[i].EndTime=P[7].toLong();
            QStringList Tmp=P[8].split('\n');
            ExistGoods[i].StartTime=Tmp[0].toLong();
            qDebug()<<ExistGoods[i].StartTime;
            i++;
        }
        return i;
}
int SearchByName(int n,QString Search){
    int i=0;//循环变量
    int a=0;//计数变量
    while (i<=n)
    {
        if (QString::compare(Search,ExistGoods[i].Name)==true)
        {
            Tmp[a]=ExistGoods[i];
            i++;
            a++;
        }
        else
        {
            i++;
        }
    }
    for ( i = 0; i <=a; i++)
    {
        ExistGoods[i]=Tmp[i];
    }

    for ( int i = 0; i <a; i++)
    {
        ;
    }
    return a;
}
ProductSearch::ProductSearch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductSearch)
{
    WriteToMemory();
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
}
ProductSearch::~ProductSearch()
{
    delete ui;
}

void ProductSearch::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}


