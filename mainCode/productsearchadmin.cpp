#include "productsearchadmin.h"
#include "productsearch.h"
#include "mainwindow2.h"
#include "productinfo.h"
#include "ui_productsearchadmin.h"
#include <QFile>
#include <QStandardItemModel>
extern Good ExistGoods[100];
extern Good Tmp[100];
QStandardItemModel* Showingmodel;
int IsPressed;
int PassedNumber;
extern QString AccountInfomation;
ProductSearchAdmin::ProductSearchAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductSearchAdmin)
{
    ui->setupUi(this);
    ui->SuperMarketName->setEnabled(false);
}
ProductSearchAdmin::~ProductSearchAdmin()
{
    delete ui;
}

void ProductSearchAdmin::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

void SortingByProfit(int n)//按利润从高到低排序已筛选商品，n为符合筛选规则商品的数目
{
    int i;
    int j;
    int a=0;
    Good temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if (ExistGoods[j].SellPrice-ExistGoods[j].BuyPrice<ExistGoods[j+1].SellPrice-ExistGoods[j+1].BuyPrice)
            {
                temp=ExistGoods[j];
                ExistGoods[j]=ExistGoods[j+1];
                ExistGoods[j+1]=temp;
            }
        }
    }
}
float SearchForTurnover(Good G)//查询某商品的营业额
{
    return G.Sale*G.SellPrice;
}
void SortingByTheTurnover(int n)//按营业额从高到低排序已筛选商品，n为符合筛选规则商品的数目
{
    int i;
    int j;
    int a=0;
    Good temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if (SearchForTurnover(ExistGoods[j])<SearchForTurnover(ExistGoods[j+1]))
            {
                temp=ExistGoods[j];
                ExistGoods[j]=ExistGoods[j+1];
                ExistGoods[j+1]=temp;
            }
        }
    }
}
bool IsLack(Good G)//判断某款商品是否缺货
{
    if(G.Storage==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsUnsalable(Good G)//判断是否滞销
{
    if(G.Storage>500)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int SearchForLack(int n)//筛选出缺货商品，n为符合前序筛选规则的商品数目，返回符合前序与新增筛选规则商品的数目
{
    int i=0;
    int a=0;
    while (i<n)
    {
        if (IsLack(ExistGoods[i])==true)
        {
            Tmp[a]=ExistGoods[i];
            i++;
            a++;
        }
        else{
            i++;
        }
    }
    for ( i = 0; i <=a; i++)
    {
        ExistGoods[i]=Tmp[i];
    }

    return a;
}
int SearchForUnsalable(int n){//筛选出滞销商品，n为符合前序筛选规则的商品数目，返回符合前序与新增筛选规则商品的数目
    int i=0;
    int a=0;
    while (i<n)
    {
        if (IsUnsalable(ExistGoods[i])==true)
        {
            Tmp[a]=ExistGoods[i];
            i++;
            a++;
        }
        else{
            i++;
        }
    }
    for ( i = 0; i <=a; i++)
    {
        ExistGoods[i]=Tmp[i];
    }
    return a;
}
void ProductSearchAdmin::on_pushButton_3_clicked()
{
    /*读取用户输入*/
    QString GoodName=ui->ProductName->text();
    QString ShopName;
    QFile LookForName("Users.txt");
    LookForName.open(QIODevice::ReadOnly);
    while(!LookForName.atEnd())
    {
        QString Line=(QString)LookForName.readLine();
        QStringList Arr=Line.split(' ');
        if(QString::compare(Arr[0],AccountInfomation)==0)
        {
            ShopName=Arr[6];
            break;
        }
    }
    /*对输出筛选结果的表格进行初始化*/
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Showingmodel = new QStandardItemModel(this);
    QStringList labels = QObject::tr("名称,售价,折扣,超市名称,库存,折扣结束时间,折扣开始时间").simplified().split(",");
    Showingmodel->setHorizontalHeaderLabels(labels);
    ui->tableView->setStyleSheet("QTableView { border: none;"
                                     "selection-background-color: #8EDE21;"
                                     "color: red}");
    ui->tableView->setModel(Showingmodel);
    ui->tableView->show();
    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    /*按照用户在前端的设定对数据进行筛选与排序*/
    if(ui->checkBox_2->isChecked()==true)//仅显示折扣商品
    {
        if(QString::compare(ShopName,"")==0&&QString::compare(GoodName,"")==0){//当用户不输入任何筛选条件时，返回所有折扣商品
            PassedNumber=SearchForDiscount(WriteToMemory());
        }
        else if(QString::compare(ShopName,"")==0){
            PassedNumber=SearchByName(SearchForDiscount(WriteToMemory()),GoodName);
        }
        else if(QString::compare(GoodName,"")==0){
            PassedNumber=SearchByShop(SearchForDiscount(WriteToMemory()),ShopName);
        }
        else{
            PassedNumber=SearchByName(SearchByShop(WriteToMemory(),ShopName),GoodName);
        }
        if(PassedNumber==0){
            return;
        }
        switch(ui->comboBox_2->currentIndex())//依照用户的输入选择一种排序方式
        {
            case 0:
                SortingByTheSaledAmount(PassedNumber);
                break;
            case 1:
                SortingBySellPrice(PassedNumber);
                qDebug()<<ExistGoods[0].Name;
                break;
        case 2:
            SortingByProfit(PassedNumber);
            break;
        case 3:
            SortingByTheTurnover(PassedNumber);
            break;
        case 4:
            SearchForUnsalable(PassedNumber);
            break;
        case 5:
            SearchForLack(PassedNumber);
            default:
                break;
        }
     }
    else//显示所有商品
    {
        if(QString::compare(ShopName,"")==0&&QString::compare(GoodName,"")==0){//当用户不输入任何筛选条件，返回所有商品
            PassedNumber=(WriteToMemory());
        }
        else if(QString::compare(ShopName,"")==0){
                    PassedNumber=SearchByName(WriteToMemory(),GoodName);
                }
        else if(QString::compare(GoodName,"")==0){
                    PassedNumber=SearchByShop(WriteToMemory(),ShopName);
                }
        else{
                    PassedNumber=SearchByShop(SearchByName(WriteToMemory(),GoodName),ShopName);
                }
        if(PassedNumber==0){
            return;
        }
        switch (ui->comboBox_2->currentIndex())//依照用户的输入选择一种排序方式
        {
        case 0:
            SortingByTheSaledAmount(PassedNumber);
            break;
        case 1:
            SortingBySellPrice(PassedNumber);
            break;
        case 2:
            SortingByProfit(PassedNumber);
            break;
        case 3:
            SortingByTheTurnover(PassedNumber);
            break;
        case 4:
            PassedNumber=SearchForUnsalable(PassedNumber);
            break;
        case 5:
            PassedNumber=SearchForLack(PassedNumber);
        default:
            break;
        }
    }
    int i=0;
    /*将筛选排序后的结果返回前端，向用户展示*/
    while(i<PassedNumber){
        QString Sell= QString::number(ExistGoods[i].SellPrice,'f',2);
        Showingmodel->setItem(i,0,new QStandardItem(ExistGoods[i].Name));
        Showingmodel->setItem(i,1,new QStandardItem(Sell));
        QString Discount=QString::number(ExistGoods[i].Discount,'f',2);
        Showingmodel->setItem(i,2,new QStandardItem(Discount));
        Showingmodel->setItem(i,3,new QStandardItem(ExistGoods[i].Shop));
        QString Storage=QString::number(ExistGoods[i].Storage,10);
        Showingmodel->setItem(i,4,new QStandardItem(Storage));
        if(ExistGoods[i].Discount !=1.0)//未完成
        {
            QString ST=QString("%1:%2:%3:%4:%5").arg(ExistGoods[i].StartTime.tm_year+1900,4,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_mon+1,2,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_mday,2,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_hour,2,10,QLatin1Char('0')).arg(ExistGoods[i].StartTime.tm_min,2,10,QLatin1Char('0'));
            QString ET=QString("%1:%2:%3:%4:%5").arg(ExistGoods[i].EndTime.tm_year+1900,4,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_mon+1,2,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_mday,2,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_hour,2,10,QLatin1Char('0')).arg(ExistGoods[i].EndTime.tm_min,2,10,QLatin1Char('0'));
            Showingmodel->setItem(i,5,new QStandardItem(ET));
            Showingmodel->setItem(i,6,new QStandardItem(ST));
            i++;
        }
        else
        {
            i++;
        }
    }
    IsPressed=1;
}


void ProductSearchAdmin::on_ComfirmingButtom_clicked()
{
    if(QString::compare(ui->IndexOfProduct->text(),"")!=0&&IsPressed==1)
    {
        if(ui->IndexOfProduct->text().toInt()>PassedNumber||ui->IndexOfProduct->text().toInt()<=0)
        {
            return;
        }
        int flag=ui->IndexOfProduct->text().toInt()-1;
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

