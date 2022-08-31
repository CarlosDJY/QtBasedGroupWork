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
#include <QTextStream>
#include <QStandardItemModel>
#include "productinfo.h"
extern QString AccountInfomation;
double NumToPay;

QString filters;
QStringList BelongedCartList;
QStringList BelongedOrderList;
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

//购物车，包含该账号计划购买的全部物品，可以选择一键购买、一键清空
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
    QStringList DivCartGoods = CartGoods.split("\n");
    int count = 0;
    while(count < DivCartGoods.length() - 1 && DivCartGoods[count].contains(" ")){
        QStringList DivGoods = DivCartGoods[count].split(" ");
        Price += DivGoods[2].toDouble() * DivGoods[3].toDouble();
        count++;
    }
    CartInit.close();
    NumToPay = Price;
    qDebug() << NumToPay;

    //商店ID需要
    //还是这个问题啊
    //这里没有新建order文件
    //所以写好这个创建就行了
    QString S=CartInit.fileName();
    QStringList p=S.split(" ");
    QString ShopName=p[2];
    QString P=AccountInfomation+" "+"order"+" "+ShopName;
    QFile Q(P);
    Q.open(QIODevice::ReadWrite|QIODevice::Text);
    Q.close();
    CartInit.open(QIODevice::ReadOnly);
    CartGoods = CartInit.readAll();
    filters = AccountInfomation + " order" + "*.txt";
    BelongedOrderList = FindFile("D:\\DataFiles\\C++\\GW_testClone\\QtBasedGroupWork", filters);
    qDebug() << "BOL" <<BelongedOrderList;
    QFile OrderInit(BelongedOrderList[0]);


    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd,hh:mm:ss");

    OrderInit.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream in(&OrderInit);
    in << "\n" << AccountInfomation << " " << current_date << " " << NumToPay << Qt::endl;
    in << CartGoods <<Qt::endl;
    OrderInit.close();
    QStringList OrderSep=BelongedOrderList[0].split(" ");
    QStringList Tmp=OrderSep[2].split(".txt");
    QString FileName=Tmp[0]+" "+"order.txt";
    QFile F(FileName);
    F.open(QIODevice::Append);
    QTextStream on(&F);
    on << "\n" << AccountInfomation << " " << current_date << " " << NumToPay << Qt::endl;
    on << CartGoods <<Qt::endl;
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
        QStringList DivCartGoods = CartGoods.split("\n");
        qDebug() << DivCartGoods;

        QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
        //设置列字段名
        Cart->setColumnCount(4);
        Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
        Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
        Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
        Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

        int count = 0;
        while(count < DivCartGoods.length() - 1 && DivCartGoods[count].contains(" ")){
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
    filters = AccountInfomation + " cart" + "*.txt";
    BelongedCartList = FindFile("D:\\DataFiles\\C++\\GW_testClone\\QtBasedGroupWork", filters);
    currCart = 0;
    countCart = BelongedCartList.length();
    qDebug() << BelongedCartList;
    qDebug() << countCart;
    QFile CartInit(BelongedCartList[currCart]);
    CartInit.open(QIODevice::ReadOnly);
    QString CartGoods = CartInit.readAll();
    QStringList DivCartGoods = CartGoods.split("\n");
    qDebug() << DivCartGoods;

    QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
    //设置列字段名
    Cart->setColumnCount(4);
    Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
    Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
    Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
    Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

    int count = 0;
    while(count < DivCartGoods.length() - 1 && DivCartGoods[count].contains(" ")){
        QStringList DivGoods = DivCartGoods[count].split(" ");
        qDebug()<< "DivGoods" <<DivGoods;
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
        QStringList DivCartGoods = CartGoods.split("\n");
        qDebug() << DivCartGoods;

        QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
        //设置列字段名
        Cart->setColumnCount(4);
        Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
        Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
        Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
        Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

        int count = 0;
        while(count < DivCartGoods.length() - 1 && DivCartGoods[count].contains(" ")){
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


void ShoppingCart::on_DeleteAll_clicked()
{
    QFile CartInit(BelongedCartList[currCart]);
    CartInit.remove();

    filters = AccountInfomation + " cart" +"*.txt";
    BelongedCartList = FindFile("D:\\DataFiles\\C++\\GW_testClone\\QtBasedGroupWork", filters);
    currCart = 0;
    countCart = BelongedCartList.length();
    qDebug() << BelongedCartList;
    qDebug() << countCart;
    CartInit.open(QIODevice::ReadOnly);
    QString CartGoods = CartInit.readAll();
    QStringList DivCartGoods = CartGoods.split("\n");
    qDebug() << DivCartGoods;

    QStandardItemModel* Cart = new QStandardItemModel(ui->tableView);
    //设置列字段名
    Cart->setColumnCount(4);
    Cart->setHeaderData(0,Qt::Horizontal, "商品ID");
    Cart->setHeaderData(1,Qt::Horizontal, "商品名称");
    Cart->setHeaderData(2,Qt::Horizontal, "商品数目");
    Cart->setHeaderData(3,Qt::Horizontal, "商品单价");

    int count = 0;
    while(count < DivCartGoods.length() - 1 && DivCartGoods[count].contains(" ")){
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

