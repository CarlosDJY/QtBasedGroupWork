#include "productsearch.h"
#include "mainwindow2.h"
#include "ui_productsearch.h"
#include <QFile>
#include "productsearch.h"
#include <time.h>
#include <QString>
#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QObject>
Good ExistGoods[100];
Good Tmp[100];
void Test()
{
    QFile Q("Goods.txt");
    Q.open(QIODevice::WriteOnly);
    Q.write("国际学院本科毕业证 70000 1.0 1.0 北邮 AA0001 1 1000 2000\n");
    Q.write("伦敦玛丽女王大学学士学位证 70000 1.0 0.8 QMUL AA0002 1 1000 2000\n");
    Q.write("《我在成都火车站捡了个彝族美女》 1.6 1.0 0.8 北邮 AA0001 1 1000 2000\n");
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
            if(P[3].toFloat()==1.0){
                 i++;
                 continue;
            }
            else{
                ExistGoods[i].EndTime=P[7].toLong();
                QStringList Tmp=P[8].split('\n');
                ExistGoods[i].StartTime=Tmp[0].toLong();
                i++;
            }
        }
        return i;
}
int SearchByName(int n,QString Search){
    if(n==0){
        return 0;
    }
    int i=0;//循环变量
    int a=0;//计数变量
    while (i<=n)
    {
        if (QString::compare(Search,ExistGoods[i].Name)==0)
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
    return a;
}
int SearchByShop(int n,QString Search){//按商店名称查找商品，n为符合之前查找条件下的商品总数，返回符合原有与新增查找条件下的商品总数
    if(n==0){
        return 0;
    }
    int i=0;
    int a=0;
    while (i<n)
    {
        if (QString::compare(Search,ExistGoods[i].Shop)==0)
        {
            Tmp[a]=ExistGoods[i];
            i++;
            a++;
        }
        else{
            i++;
        }
    }
    for ( i = 0; i <a; i++)
    {
        ExistGoods[i]=Tmp[i];
    }
    return a;
}
int SearchForDiscount(int n){//按是否折扣查找商品，n为符合之前查找条件下的商品总数，返回符合原有与新增查找条件下的商品总数
    int i=0;
    int a=0;
    while (i<n)
    {
        if (ExistGoods[i].Discount<1.0)
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
    if(a==0)
    {
        return 0;
    }
    for ( i = 0; i <=a; i++)
    {
        ExistGoods[i]=Tmp[i];
    }
    return a;
}
void SortingBySellPrice(int n){//按售价从低到高排序已筛选商品，n为符合筛选规则商品的数目
    int i=0;
    int j;
    Good temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if (ExistGoods[j].SellPrice>ExistGoods[j+1].SellPrice)
            {
                temp=ExistGoods[j];
                ExistGoods[j]=ExistGoods[j+1];
                ExistGoods[j+1]=temp;
            }
        }
    }
}
float SearchForTheSaledAmount(Good G)//查询某商品的销量
{
    return 0;//未完成
}
void SortingByTheSaledAmount(int n)//按销量从高到低排序已筛选商品，n为符合筛选规则商品的数目
{
    int i;
    int j;
    int a=0;
    Good temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if (SearchForTheSaledAmount(ExistGoods[j])<SearchForTheSaledAmount(ExistGoods[j+1]))
            {
                temp=ExistGoods[j];
                ExistGoods[j]=ExistGoods[j+1];
                ExistGoods[j+1]=temp;
            }
        }
    }
}

ProductSearch::ProductSearch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductSearch)
{
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

void ProductSearch::on_pushButton_3_clicked()
{
    Test();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QString GoodName=ui->lineEdit->text();
    QString ShopName=ui->lineEdit_2->text();
    QStandardItemModel* model = new QStandardItemModel(this);
    QStringList labels = QObject::tr("名称,售价,折扣,卖家,库存,折扣结束时间,折扣开始时间").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setStyleSheet("QTableView { border: none;"
                                     "selection-background-color: #8EDE21;"
                                     "color: red}");
    ui->tableView->setModel(model);
    ui->tableView->show();
    int flag;
    if(ui->checkBox->isChecked()==true)
    {
        if(QString::compare(ShopName,"")==0&&QString::compare(GoodName,"")==0){
            flag=SearchForDiscount(WriteToMemory());
        }
        else if(QString::compare(ShopName,"")==0){
            flag=SearchByName(SearchForDiscount(WriteToMemory()),GoodName);
        }
        else if(QString::compare(GoodName,"")==0){
            flag=SearchByShop(SearchForDiscount(WriteToMemory()),ShopName);
        }
        else{
            flag=SearchByName(SearchByShop(WriteToMemory(),ShopName),GoodName);
        }
        if(flag==0){
            return;
        }
        switch(ui->comboBox->currentIndex())
        {
            case 1:
                SortingByTheSaledAmount(flag);
                break;
            case 2:
                SortingBySellPrice(flag);
                qDebug()<<ExistGoods[0].Name;
                break;
            default:
                break;
        }
     }
    else
    {
        if(QString::compare(ShopName,"")==0&&QString::compare(GoodName,"")==0){
            flag=(WriteToMemory());
        }
        else if(QString::compare(ShopName,"")==0){
                    flag=SearchByName(WriteToMemory(),GoodName);
                }
        else if(QString::compare(GoodName,"")==0){
                    flag=SearchByShop(WriteToMemory(),ShopName);
                }
        else{
                    flag=SearchByShop(SearchByName(WriteToMemory(),GoodName),ShopName);
                }
        if(flag==0){
            return;
        }
        switch (ui->comboBox->currentIndex())
        {
        case 1:
            SortingByTheSaledAmount(flag);
            break;
        case 2:
            SortingBySellPrice(flag);
            qDebug()<<ExistGoods[0].Name;
            break;
        default:
            break;
        }
    }
    int i=0;
    while(i<flag){
        QString Sell= QString::number(ExistGoods[i].SellPrice,'f',2);
        model->setItem(i,0,new QStandardItem(ExistGoods[i].Name));
        model->setItem(i,1,new QStandardItem(Sell));
        QString Discount=QString::number(ExistGoods[i].Discount,'f',2);
        model->setItem(i,2,new QStandardItem(Discount));
        model->setItem(i,3,new QStandardItem(ExistGoods[i].Shop));
        QString Storage=QString::number(ExistGoods[i].Storage,10);
        model->setItem(i,4,new QStandardItem(Storage));
        i++;
    }
}


