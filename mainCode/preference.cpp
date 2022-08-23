#include "preference.h"
#include "accountcontrol.h"
#include "ui_preference.h"

Preference::Preference(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    QButtonGroup *Price=new QButtonGroup(this);
    QButtonGroup *Discount=new QButtonGroup(this);
    QButtonGroup *Sales=new QButtonGroup(this);

    Price->addButton(ui->PriceHigh,1);
    Price->addButton(ui->PriceLow,0);
    Discount->addButton(ui->DiscountHigh,1);
    Discount->addButton(ui->DiscountLow,0);
    Sales->addButton(ui->SalesHigh,1);
    Sales->addButton(ui->SalesLow,0);
}

Preference::~Preference()
{
    delete ui;
}

void Preference::on_BackButton_clicked()
{
    AccountControl *win = new AccountControl;
    win->show();
    this->close();
}

