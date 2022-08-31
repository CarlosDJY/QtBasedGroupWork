#include "orderinfoadmin.h"
#include "mainwindow2.h"
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
    MainWindow2 *win = new MainWindow2;
    win->show();
    this->close();
}

