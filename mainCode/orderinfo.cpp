#include "orderinfo.h"
#include "mainwindow2.h"
#include "ui_orderinfo.h"
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

QString filtersO;
extern QString AccountInfomation;
QStringList BelongedOrderTxt;
QStringList BelongedOrders;
int countOrder;
int currOrder;

OrderInfo::OrderInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

}

OrderInfo::~OrderInfo()
{
    delete ui;
}

QStringList FindFileO(const QString &strFilePath, const QString &strNameFilters)
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



void OrderInfo::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}


void OrderInfo::on_FindOrder_clicked()
{
    filtersO = AccountInfomation + " order" + "*.txt";
    BelongedOrderTxt = FindFileO("D:\\DataFiles\\C++\\GW_testClone\\QtBasedGroupWork", filtersO);

    QString OrderAddress = BelongedOrderTxt[0];
    QFile Orders(OrderAddress);
    Orders.open(QIODevice::ReadOnly);
    QString tempList = Orders.readAll();
    BelongedOrders = tempList.split("\n\n\n");
    currOrder = 0;
    countOrder = BelongedOrders.length();
    qDebug() << BelongedOrders;
    qDebug() << countOrder;

    BelongedOrders[currOrder].replace("\r\n","\n");
    QStringList OrderInfo = BelongedOrders[currOrder].split("\n",Qt::SkipEmptyParts);
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


void OrderInfo::on_pushButton_clicked()
{
    //下一订单
    if(currOrder + 1 < countOrder){
        currOrder += 1;

        QFile Orders(BelongedOrderTxt[0]);
        Orders.open(QIODevice::ReadOnly);

        BelongedOrders[currOrder].replace("\r\n","\n");
        QStringList OrderInfo = BelongedOrders[currOrder].split("\n",Qt::SkipEmptyParts);
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
        QMessageBox::warning(this, tr("Warning"), tr("Last Order Reached !"), QMessageBox::Ok);
    }
}


void OrderInfo::on_pushButton_2_clicked()
{
    if(currOrder - 1 >= 0){
        currOrder -= 1;

        QFile Orders(BelongedOrderTxt[0]);
        Orders.open(QIODevice::ReadOnly);

        BelongedOrders[currOrder].replace("\r\n","\n");
        QStringList OrderInfo = BelongedOrders[currOrder].split("\n",Qt::SkipEmptyParts);
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
        QMessageBox::warning(this, tr("Warning"), tr("First Order Reached !"), QMessageBox::Ok);
    }
}


void OrderInfo::on_PayButton_clicked()
{

}

