#include "orderinfoadmin.h"
#include "mainwindow2admin.h"
#include "ui_orderinfoadmin.h"

OrderInfoAdmin::OrderInfoAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderInfoAdmin)
{
    ui->setupUi(this);
}

OrderInfoAdmin::~OrderInfoAdmin()
{
    delete ui;
}

void OrderInfoAdmin::on_BackButton_clicked()
{
    MainWindow2Admin *win = new MainWindow2Admin;
    win->show();
    this->close();
}

