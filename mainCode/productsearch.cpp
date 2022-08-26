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
Good ExistGoods[100];//从文件中读取所有内容存入内存中，保存在此结构体数组中
Good Tmp[100];//用于筛选过程的临时结构体数组
void Test()//测试函数,用于在未完成编程时向文件内写入测试用例
{
    QFile Q("Goods.txt");
    Q.open(QIODevice::WriteOnly);
    Q.write("国际学院本科毕业证 70000 1.0 1.0 北邮 AA0001 1  \n");
    Q.write("伦敦玛丽女王大学学士学位证 70000 1.0 0.8 QMUL AA0002 1 2021 10 01 12 00 2019 10 01 12 00\n");
    Q.write("《我在成都火车站捡了个彝族美女》 1.6 1.0 0.8 广西玉林高中 AA0001 1 2021 10 01 12 00 2019 10 01 12 00\n");
    Q.close();
}
int WriteToMemory()//从文件中读取所有内容写入结构体数组中，返回商品总数
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

            }
            else{
                ExistGoods[i].EndTime.tm_year=P[7].toInt();
                ExistGoods[i].EndTime.tm_mon=P[8].toInt();
                ExistGoods[i].EndTime.tm_mday=P[9].toInt();
                ExistGoods[i].EndTime.tm_hour=P[10].toInt();
                ExistGoods[i].EndTime.tm_min=P[11].toInt();
                ExistGoods[i].StartTime.tm_year=P[12].toInt();
                ExistGoods[i].StartTime.tm_mon=P[13].toInt();
                ExistGoods[i].StartTime.tm_mday=P[14].toInt();
                ExistGoods[i].StartTime.tm_hour=P[15].toInt();//开始时间有问题
                ExistGoods[i].StartTime.tm_min=P[16].toInt();
                i++;
            }
        }
        return i;
}
int SearchByName(int n,QString Search){/*通过商品名称筛选，n为符合前序筛选结果的商品总数，Search为查询名称*/
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
    Test();//向文件中写入测试数据
    /*读取用户输入*/
    QString GoodName=ui->lineEdit->text();
    QString ShopName=ui->lineEdit_2->text();
    /*对输出筛选结果的表格进行初始化*/
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStandardItemModel* model = new QStandardItemModel(this);
    QStringList labels = QObject::tr("名称,售价,折扣,超市名称,库存,折扣结束时间,折扣开始时间").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setStyleSheet("QTableView { border: none;"
                                     "selection-background-color: #8EDE21;"
                                     "color: red}");
    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    /*按照用户在前端的设定对数据进行筛选与排序*/
    int flag;
    if(ui->checkBox->isChecked()==true)//仅显示折扣商品
    {
        if(QString::compare(ShopName,"")==0&&QString::compare(GoodName,"")==0){//当用户不输入任何筛选条件时，返回所有折扣商品
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
        switch(ui->comboBox->currentIndex())//依照用户的输入选择一种排序方式
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
    else//显示所有商品
    {
        if(QString::compare(ShopName,"")==0&&QString::compare(GoodName,"")==0){//当用户不输入任何筛选条件，返回所有商品
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
        switch (ui->comboBox->currentIndex())//依照用户的输入选择一种排序方式
        {
        case 1:
            SortingByTheSaledAmount(flag);
            break;
        case 2:
            SortingBySellPrice(flag);
            break;
        default:
            break;
        }
    }
    int i=0;
    /*将筛选排序后的结果返回前端，向用户展示*/
    while(i<flag){
        QString Sell= QString::number(ExistGoods[i].SellPrice,'f',2);
        model->setItem(i,0,new QStandardItem(ExistGoods[i].Name));
        model->setItem(i,1,new QStandardItem(Sell));
        QString Discount=QString::number(ExistGoods[i].Discount,'f',2);
        model->setItem(i,2,new QStandardItem(Discount));
        model->setItem(i,3,new QStandardItem(ExistGoods[i].Shop));
        QString Storage=QString::number(ExistGoods[i].Storage,10);
        model->setItem(i,4,new QStandardItem(Storage));        
        if(ExistGoods[i].Discount !=1.0)
        {

            QString EndTime=QString::number(ExistGoods[i].EndTime.tm_year)+":"+QString::number(ExistGoods[i].EndTime.tm_mon)+":"+QString::number(ExistGoods[i].EndTime.tm_mday)+":"+QString::number(ExistGoods[i].EndTime.tm_hour)+":"+QString::number(ExistGoods[i].EndTime.tm_min);
            QString StartTime=QString::number(ExistGoods[i].StartTime.tm_year)+":"+QString::number(ExistGoods[i].StartTime.tm_mon)+":"+QString::number(ExistGoods[i].StartTime.tm_mday)+":"+QString::number(ExistGoods[i].StartTime.tm_hour)+":"+QString::number(ExistGoods[i].StartTime.tm_min);
            model->setItem(i,5,new QStandardItem(EndTime));
            model->setItem(i,6,new QStandardItem(StartTime));
            i++;
        }
        else
        {
            i++;
        }

    }
}
/*当用户双击某一商品时，转到该商品的信息页*///未完成
void ProductSearch::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QModelIndex record = ui->tableView->currentIndex();
    qDebug()<<record.data();
}

