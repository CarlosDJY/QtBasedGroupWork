#include "productsearchadmin.h"
#include "mainwindow2admin.h"
#include "ui_productsearchadmin.h"

ProductSearchAdmin::ProductSearchAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductSearchAdmin)
{
    ui->setupUi(this);
}

ProductSearchAdmin::~ProductSearchAdmin()
{
    delete ui;
}

void ProductSearchAdmin::on_BackButton_clicked()
{
    MainWindow2Admin *win = new MainWindow2Admin;
    win->show();
    this->close();
}

