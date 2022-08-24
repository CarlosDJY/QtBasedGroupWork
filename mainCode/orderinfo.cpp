#include "orderinfo.h"
#include "mainwindow2.h"
#include "ui_orderinfo.h"
#include <qtablewidget>
#include <QHeaderView>
#include <QStandardItemModel>

OrderInfo::OrderInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderInfo)
{
    ui->setupUi(this);

    //订单编号、购物日期、所购商品（编号、名称、数量、单价）、购物总价格等
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("订单编号")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("购物日期")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("所购商品")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("购物总价格")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("订单状态")));
    ui->OrderTable->setModel(model);
    ui->OrderTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->OrderTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    int i = 0;
    while(i < 5){
        ui->OrderTable->setColumnWidth(i,775/5-1);
        ui->OrderTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        i+=1;
    }

}

OrderInfo::~OrderInfo()
{
    delete ui;
}

void OrderInfo::on_BackButton_clicked()
{
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

