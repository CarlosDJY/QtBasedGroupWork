#include "productsearch.h"
#include "mainwindow2.h"
#include "ui_productsearch.h"
#include "productinfo.h"
#include <QFile>
#include "productsearch.h"
#include <time.h>
#include <QString>
#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QObject>
#include <QDateTime>
extern QString AccountInfomation;
Good ExistGoods[100];//从文件中读取所有内容存入内存中，保存在此结构体数组中
Good Tmp[100];//用于筛选过程的临时结构体数组
QStandardItemModel* model;
int Set;//用于确定查询按钮是否按下的变量，0为未按下，1为已按下
int flag;//用于确定通过所有筛选器的数据数量
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
            int length=P.length();
            ExistGoods[i].Sale=P[length-1].toInt();
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
                ExistGoods[i].StartTime.tm_hour=P[15].toInt();
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
int SearchForTheSaledAmount(Good G)//查询某商品的销量
{
    return G.Sale;
}
float SearchForTheGereralPrefenres(Good G)//查询用户User对商品的偏好指数
{
    QFile P("Users.txt");
    P.open(QIODevice::ReadOnly);
    QString Prefenres;
    while(!P.atEnd())
    {
          QString line=(QString)P.readLine();
          QStringList arr=line.split(" ");
          if(QString::compare(arr[0],AccountInfomation)==0)
          {
              Prefenres=arr[8];
              break;
          }
    }
    QStringList Pr=Prefenres.split("");
    int PricePre=Pr[0].toInt();
    int DiscountPre=Pr[1].toInt();
    int SellPre=Pr[2].toInt();
    float pre=1/G.SellPrice*PricePre/(PricePre+DiscountPre+SellPre)+1/G.Discount*DiscountPre/(PricePre+DiscountPre+SellPre)+G.Sale*SellPre/(PricePre+DiscountPre+SellPre);
    return pre;
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
void SortingByTheGeneralPrefenrence(int n)//按综合偏好从高到低排序已筛选商品，n为符合筛选规则商品的数目
{
    int i;
    int j;
    int a=0;
    Good temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if (SearchForTheGereralPrefenres(ExistGoods[j])<SearchForTheGereralPrefenres(ExistGoods[j+1]))
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
    connect(ui->ComfirmingButtom,&QPushButton::clicked,this,&ProductSearch::on_ComfirmingButtom_clicked);
    Set=0;
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
    /*读取用户输入*/
    QString GoodName=ui->lineEdit->text();
    QString ShopName=ui->lineEdit_2->text();
    /*对输出筛选结果的表格进行初始化*/
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    model = new QStandardItemModel(this);
    QStringList labels = QObject::tr("名称,售价,折扣,超市名称,库存,折扣结束时间,折扣开始时间").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setStyleSheet("QTableView { border: none;"
                                     "selection-background-color: #8EDE21;"
                                     "color: red}");
    ui->tableView->setModel(model);
    ui->tableView->show();
    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    /*按照用户在前端的设定对数据进行筛选与排序*/
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
            case 0:
                SortingByTheGeneralPrefenrence(flag);
                break;
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
        case 0:
            SortingByTheGeneralPrefenrence(flag);
            break;
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
        if(ExistGoods[i].Discount !=1.0)//未完成
        {
            QString ST=QString("%1:%2:%3:%4:%5").arg(ExistGoods[i].StartTime.tm_year+1900,4,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_mon+1,2,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_mday,2,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_hour,2,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_min,2,10,QLatin1Char('0'));
            QString ET=QString("%1:%2:%3:%4:%5").arg(ExistGoods[i].EndTime.tm_year+1900,4,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_mon+1,2,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_mday,2,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_hour,2,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_min,2,10,QLatin1Char('0'));
            model->setItem(i,5,new QStandardItem(ET));
            model->setItem(i,6,new QStandardItem(ST));
            i++;
        }
        else
        {
            i++;
        }
    }
    Set=1;
}


void ProductSearch::on_ComfirmingButtom_clicked()
{
    if(QString::compare(ui->lineEdit_3->text(),"")!=0&&Set==1)
    {
        if(ui->lineEdit_3->text().toInt()>flag||ui->lineEdit_3->text().toInt()<=0)
        {
            return;
        }
        int flag=ui->lineEdit_3->text().toInt()-1;
        QFile Q("temp.txt");
        Q.open(QIODevice::WriteOnly);
        if(ExistGoods[flag].Discount==1.0)
        {
            QString Tmp=ExistGoods[flag].ID+" "+ExistGoods[flag].Name+" "+QString::number(ExistGoods[flag].SellPrice,'f',2)+" "+ExistGoods[flag].Shop+" "+QString::number(ExistGoods[flag].Discount,'f',2)+" "+QString::number(ExistGoods[flag].Sale);
            std::string TEST=Tmp.toStdString();
            const char* data=TEST.c_str();
            Q.write(data);
            Q.close();
        }
        else
        {
            time_t ST=mktime(&ExistGoods[flag].StartTime);
            time_t ET=mktime(&ExistGoods[flag].EndTime);
            QString Tmp=ExistGoods[flag].ID+" "+ExistGoods[flag].Name+" "+QString::number(ExistGoods[flag].SellPrice,'f',2)+" "+ExistGoods[flag].Shop+" "+QString::number(ExistGoods[flag].Discount,'f',2)+" "+QString::number(ST,10)+" "+QString::number(ET,10)+" "+QString::number(ExistGoods[flag].Sale);
            std::string TEST=Tmp.toStdString();
            const char* data=TEST.c_str();
            Q.write(data);
            Q.close();
        }
        ProductInfo* win=new ProductInfo();
        win->show();
        this->close();
    }
    else
    {
        return;
    }
}


