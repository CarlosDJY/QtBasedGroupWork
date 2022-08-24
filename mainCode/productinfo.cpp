#include "productinfo.h"
#include "ui_productinfo.h"

ProductInfo::ProductInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
}

ProductInfo::~ProductInfo()
{
    delete ui;
}
