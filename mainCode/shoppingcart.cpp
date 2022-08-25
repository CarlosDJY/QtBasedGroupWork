#include "shoppingcart.h"
#include "mainwindow2.h"
#include "paypage.h"
#include "ui_shoppingcart.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDirIterator>
#include <QStandardItemModel>

extern QString AccountInfomation;
double NumToPay;

QString filters;
QStringList BelongedCartList;
int countCart;
int currCart;

QStringList FindFile(const QString &strFilePath, const QString &strNameFilters);

ShoppingCart::ShoppingCart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

//购物车，包含该账号计划购买的全部物品，可以选择一键购买、部分购买、部分删除
ShoppingCart::~ShoppingCart()
{
    delete ui;
    this->setWindowTitle("网上超市系统");

}

//找到路径下符合过滤器名称的文件
QStringList FindFile(const QString &strFilePath, const QString &strNameFilters)
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

//返回主界面2
void ShoppingCart::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

//购买所有购物车内商品
void ShoppingCart::on_BuyAll_clicked()
{
    double Price = 0;
    QFile CartInit(BelongedCartList[currCart]);
    CartInit.open(QIODevice::ReadOnly);
    QString CartGoods = CartInit.readAll();
    QStringList DivCartGoods = CartGoods.split("\r\n");
    int count = 0;
    while(count < DivCartGoods.length() - 1){
        QStringList DivGoods = DivCartGoods[count].split(" ");
        Price += DivGoods[2].toDouble() * DivGoods[3].toDouble();
        count++;
    }
    CartInit.close();
    NumToPay = Price;
    qDebug() << NumToPay;

    PayPage *win = new PayPage;
    win->show();
    this->close();
}


void ShoppingCart::on_NextPage_clicked()
{
    if(currCart+2<=countCart){
        currCart += 1;
        QFile CartInit(BelongedCartList[currCart]);
        CartInit.open(QIODevice::ReadOnly);
        QString CartGoods = CartInit.readAll();
        QStringList DivCartGoods = CartGoods.split("\r\n");
        qDebug() << DivCartGoods;

        QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
        //设置列字段名
        Cart->setColumnCount(4);
        Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
        Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
        Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
        Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

        int count = 0;
        while(count < DivCartGoods.length() - 1){
            QStringList DivGoods = DivCartGoods[count].split(" ");
            for(int itr = 0; itr < 4; itr++){
                Cart->setItem(count, itr, new QStandardItem(DivGoods[itr]));
            }
            count++;
        }
        CartInit.close();

        ui->tableView->setModel(Cart);
        int i = 0;
        while(i < 4){
            ui->tableView->setColumnWidth(i,775/4-5);
            ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
            i++;
        }
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("Last Cart Reached !"), QMessageBox::Ok);
    }
}


void ShoppingCart::on_FindCart_clicked()
{
    filters = AccountInfomation + "*.txt";
    BelongedCartList = FindFile("D:\\DataFiles\\C++\\GW_testClone\\QtBasedGroupWork", filters);
    currCart = 0;
    countCart = BelongedCartList.length();
    qDebug() << BelongedCartList;
    qDebug() << countCart;
    QFile CartInit(BelongedCartList[currCart]);
    CartInit.open(QIODevice::ReadOnly);
    QString CartGoods = CartInit.readAll();
    QStringList DivCartGoods = CartGoods.split("\r\n");
    qDebug() << DivCartGoods;

    QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
    //设置列字段名
    Cart->setColumnCount(4);
    Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
    Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
    Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
    Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

    int count = 0;
    while(count < DivCartGoods.length() - 1){
        QStringList DivGoods = DivCartGoods[count].split(" ");
        for(int itr = 0; itr < 4; itr++){
            Cart->setItem(count, itr, new QStandardItem(DivGoods[itr]));
        }
        count++;
    }
    CartInit.close();

    ui->tableView->setModel(Cart);
    int i = 0;
    while(i < 4){
        ui->tableView->setColumnWidth(i,775/4-5);
        ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        i++;
    }
}


void ShoppingCart::on_PrevPage_clicked()
{
    if(currCart-1>=0){
        currCart -= 1;
        QFile CartInit(BelongedCartList[currCart]);
        CartInit.open(QIODevice::ReadOnly);
        QString CartGoods = CartInit.readAll();
        QStringList DivCartGoods = CartGoods.split("\r\n");
        qDebug() << DivCartGoods;

        QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
        //设置列字段名
        Cart->setColumnCount(4);
        Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
        Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
        Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
        Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

        int count = 0;
        while(count < DivCartGoods.length() - 1){
            QStringList DivGoods = DivCartGoods[count].split(" ");
            for(int itr = 0; itr < 4; itr++){
                Cart->setItem(count, itr, new QStandardItem(DivGoods[itr]));
            }
            count++;
        }
        CartInit.close();

        ui->tableView->setModel(Cart);
        int i = 0;
        while(i < 4){
            ui->tableView->setColumnWidth(i,775/4-5);
            ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
            i++;
        }
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("First Cart Reached !"), QMessageBox::Ok);
    }
}

