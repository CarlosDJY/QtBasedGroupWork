#include "mainwindow.h"
#include "login.h"
#include "register.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginButton_clicked()
{
    Login *win = new Login;
    win->show();
    this->close();
}

void MainWindow::on_RegisterButton_clicked()
{
    Register *win = new Register;
    win->show();
    this->close();
}

