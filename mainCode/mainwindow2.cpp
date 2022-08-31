#include "mainwindow2.h"
#include "accountcontrol.h"
#include "accountcontroladmin.h"
#include "orderinfo.h"
#include "orderinfoadmin.h"
#include "productsearch.h"
#include "productsearchadmin.h"
#include "shoppingcart.h"
#include "ui_mainwindow2.h"
#include "login.h"
extern int IsAdmin;
extern QString AccountInfomation;

//主界面2，下属账号管理，订单管理，商品查询，购物车四个分支
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    QFile User("Users.txt");
    User.open(QIODevice::ReadOnly);

    //在输入详细信息前不能访问其他内容
    while(!User.atEnd())
    {
        QString Arr=(QString)User.readLine();
        qDebug()<<Arr;
        QStringList Tmp=Arr.split(" ");
        if(QString::compare(Tmp[0],AccountInfomation)==0)
        {
            if(QString::compare(Tmp[2],"0\n")==0||QString::compare(Tmp[2],"1\n")==0)
            {
                ui->OrderButton->setEnabled(false);
                ui->ProductButton->setEnabled(false);
                ui->CartButton->setEnabled(false);
            }
        }
    }
    if(IsAdmin==1)
    {
        ui->CartButton->setEnabled(false);

    }
    else
    {
        ui->CartButton->setEnabled(true);

    }
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

//转到账号管理界面
void MainWindow2::on_AccountButton_clicked()
{
    if(IsAdmin==1)
    {
        AccountControlAdmin *win=new AccountControlAdmin;
        win->show();
        this->close();
    }
    else
    {
        AccountControl *win = new AccountControl;
        win->show();
        this->hide();
    }
}

//转到订单管理界面
void MainWindow2::on_OrderButton_clicked()
{
    if(IsAdmin==1)
    {
        OrderInfoAdmin *win=new OrderInfoAdmin;
        win->show();
        this->hide();
    }
    else
    {
        OrderInfo *win = new OrderInfo;
        win->show();
        this->hide();
    }
}

//转到商品查询界面
void MainWindow2::on_ProductButton_clicked()
{
    if(IsAdmin==1)
    {
        ProductSearchAdmin *win=new ProductSearchAdmin;
        win->show();
        this->hide();
    }
    else
    {
        ProductSearch *win = new ProductSearch;
        win->show();
        this->hide();
    }
}

//转到购物车界面
void MainWindow2::on_CartButton_clicked()
{
    ShoppingCart *win = new ShoppingCart;
    win->show();
    this->hide();
}

