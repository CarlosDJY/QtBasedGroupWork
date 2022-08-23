#include "mainwindow.h"
#include "mainwindow2.h"
#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::on_BackButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}

int isExistingAccount(QString){
    return 1;
}

int isMappingPassword(QString, QString){
    return 1;
}

void Login::on_ConfirmButton_clicked()
{
    if(isExistingAccount(ui->AccountLineEdit->text())) {
        QString Account = ui->AccountLineEdit->text();
        if(isMappingPassword(Account, ui->PasswordLineEdit->text()))
        {
            MainWindow2 *win = new MainWindow2;
            win->show();
            this->close();
        }
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("User name or Password error !"), QMessageBox::Yes);
    }
}

