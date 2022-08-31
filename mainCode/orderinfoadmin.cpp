#include "accountdetail.h"
#include "orderinfoadmin.h"
#include "mainwindow2admin.h"
#include "ui_orderinfoadmin.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDirIterator>
#include <QTextStream>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QHeaderView>

QString filtersOA;
extern QString AccountInfomation;
extern QString ShopInfo;
QStringList BelongedAOrderTxt;
QStringList BelongedAOrders;
int countOrderA;
int currOrderA;

OrderInfoAdmin::OrderInfoAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderInfoAdmin)
{
    QFile Q("Users.txt");
    Q.open(QIODevice::ReadOnly);
    while(!Q.atEnd()){
        QString Arr=(QString)Q.readLine();
        Arr.remove("\n");
        QStringList P=Arr.split(' ');
        if(QString::compare(P[0],AccountInfomation)==0)
        {
            ShopInfo=P[6];
        }
    }
    ui->setupUi(this);
    ui->label_2->setText(ShopInfo);
}

OrderInfoAdmin::~OrderInfoAdmin()
{
    delete ui;
}

QStringList FindFileOA(const QString &strFilePath, const QString &strNameFilters)
{
    if (strFilePath.isEmpty() || strNameFilters.isEmpty())
    {
     return QStringList();
    }

    QDir dir;
    QStringList filters;
    QStringList FindFiles;

    filters << strNameFilters;
    dir.setPath(strFilePath);
    qDebug() << dir.path();
    dir.setNameFilters(filters);
    qDebug() << dir.nameFilters();

    QDirIterator iter(dir, QDirIterator::Subdirectories);

    while (iter.hasNext())
    {
        iter.next();
        QFileInfo info=iter.fileInfo();
        if (info.isFile()){
            FindFiles << info.absoluteFilePath().replace('/', '\\');
        }
    }
    return FindFiles;
}

void OrderInfoAdmin::on_BackButton_clicked()
{
    MainWindow2Admin *win = new MainWindow2Admin;
    win->show();
    this->close();
}


void OrderInfoAdmin::on_FindOrder_clicked()
{
    //查询
    filtersOA = ShopInfo + " order" + "*.txt";
    //这里要改成对应的商店的info
    BelongedAOrderTxt = FindFileOA("D:\\DataFiles\\C++\\GW_testClone\\QtBasedGroupWork", filtersOA);
    QString OrderAddress = BelongedAOrderTxt[0];
    QFile Orders(OrderAddress);
    Orders.open(QIODevice::ReadOnly);
    QString tempList = Orders.readAll();
    BelongedAOrders = tempList.split("\n\n\n");
    currOrderA = 0;
    countOrderA = BelongedAOrders.length();
    qDebug() << BelongedAOrders;
    qDebug() << countOrderA;

    BelongedAOrders[currOrderA].replace("\r\n","\n");
    QStringList OrderInfo = BelongedAOrders[currOrderA].split("\n",Qt::SkipEmptyParts);
    qDebug() << "OrderInfo" << OrderInfo;

    ui->OrderTime->setText(OrderInfo[0].split(" ")[1]);
    ui->TotalValue->setText(OrderInfo[0].split(" ")[2]);

    QStandardItemModel* Order = new QStandardItemModel(ui->OrderTable);
    //设置列字段名
    Order->setColumnCount(4);
    Order->setHeaderData(0,Qt::Horizontal, "商品ID");
    Order->setHeaderData(1,Qt::Horizontal, "商品名称");
    Order->setHeaderData(2,Qt::Horizontal, "商品数目");
    Order->setHeaderData(3,Qt::Horizontal, "商品单价");

    int count = 1;
    while(count < OrderInfo.length()){
        QStringList DivOrder = OrderInfo[count].split(" ");
        for(int itr = 0; itr < 4; itr++){
            Order->setItem(count-1, itr, new QStandardItem(DivOrder[itr]));
        }
        count++;
    }
    Orders.close();

    ui->OrderTable->setModel(Order);
    int i = 0;
    while(i < 4){
        ui->OrderTable->setColumnWidth(i,775/4-10);
        ui->OrderTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        i++;
    }
}


void OrderInfoAdmin::on_pushButton_clicked()
{
    //下一订单
    if(currOrderA + 1 < countOrderA){
        currOrderA += 1;

        QFile Orders(BelongedAOrderTxt[0]);
        Orders.open(QIODevice::ReadOnly);

        BelongedAOrders[currOrderA].replace("\r\n","\n");
        QStringList OrderInfo = BelongedAOrders[currOrderA].split("\n",Qt::SkipEmptyParts);
        qDebug() << "OrderInfo" << OrderInfo;

        ui->OrderTime->setText(OrderInfo[0].split(" ")[1]);
        ui->TotalValue->setText(OrderInfo[0].split(" ")[2]);

        QStandardItemModel* Order = new QStandardItemModel(ui->OrderTable);
        //设置列字段名
        Order->setColumnCount(4);
        Order->setHeaderData(0,Qt::Horizontal, "商品ID");
        Order->setHeaderData(1,Qt::Horizontal, "商品名称");
        Order->setHeaderData(2,Qt::Horizontal, "商品数目");
        Order->setHeaderData(3,Qt::Horizontal, "商品单价");

        int count = 1;
        while(count < OrderInfo.length()){
            QStringList DivOrder = OrderInfo[count].split(" ");
            for(int itr = 0; itr < 4; itr++){
                Order->setItem(count-1, itr, new QStandardItem(DivOrder[itr]));
            }
            count++;
        }
        Orders.close();

        ui->OrderTable->setModel(Order);
        int i = 0;
        while(i < 4){
            ui->OrderTable->setColumnWidth(i,775/4-10);
            ui->OrderTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
            i++;
        }
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr("Last Cart Reached !"), QMessageBox::Ok);
        return;
    }
}


void OrderInfoAdmin::on_pushButton_2_clicked()
{
    if(currOrderA - 1 >= 0){
        currOrderA -= 1;

        QFile Orders(BelongedAOrderTxt[0]);
        Orders.open(QIODevice::ReadOnly);

        BelongedAOrders[currOrderA].replace("\r\n","\n");
        QStringList OrderInfo = BelongedAOrders[currOrderA].split("\n",Qt::SkipEmptyParts);
        qDebug() << "OrderInfo" << OrderInfo;

        ui->OrderTime->setText(OrderInfo[0].split(" ")[1]);
        ui->TotalValue->setText(OrderInfo[0].split(" ")[2]);

        QStandardItemModel* Order = new QStandardItemModel(ui->OrderTable);
        //设置列字段名
        Order->setColumnCount(4);
        Order->setHeaderData(0,Qt::Horizontal, "商品ID");
        Order->setHeaderData(1,Qt::Horizontal, "商品名称");
        Order->setHeaderData(2,Qt::Horizontal, "商品数目");
        Order->setHeaderData(3,Qt::Horizontal, "商品单价");

        int count = 1;
        while(count < OrderInfo.length()){
            QStringList DivOrder = OrderInfo[count].split(" ");
            for(int itr = 0; itr < 4; itr++){
                Order->setItem(count-1, itr, new QStandardItem(DivOrder[itr]));
            }
            count++;
        }
        Orders.close();

        ui->OrderTable->setModel(Order);
        int i = 0;
        while(i < 4){
            ui->OrderTable->setColumnWidth(i,775/4-10);
            ui->OrderTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
            i++;
        }
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr("First Cart Reached !"), QMessageBox::Ok);
    }
}

