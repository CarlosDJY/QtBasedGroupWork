#include "mainwindow.h"
#include "register.h"
#include "ui_register.h"
#include <QLineEdit>
#include <QMessageBox>

QString AdminPw = "123";


Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("网上超市系统");

    ui->AccountLineEdit->setMaxLength(10);
    ui->PasswordLineEdit->setMaxLength(10);
    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->AdminPasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->AdminPasswordLineEdit->setPlaceholderText("输入管理员密码以注册管理员帐号");
}

Register::~Register()
{
    delete ui;
}

void Register::on_BackButton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->close();
}

//待补充：判断字符串是否符合要求
int isValidID(QString)
{
    return 1;
}

void Register::on_ConfirmButton_clicked()
{
        if (isValidID(ui->AccountLineEdit->text())){
            if (isValidID(ui->PasswordLineEdit->text())){
                if(ui->AdminPasswordLineEdit->text()==AdminPw){
                    MainWindow *win = new MainWindow;
                    win->show();
                    this->close();
                    }
                else if(ui->AdminPasswordLineEdit->text()==""){
                        MainWindow *win = new MainWindow;
                        win->show();
                        this->close();
                    }
                else {
                    QMessageBox::warning(this, tr("Warning"), tr("Admin Password error !"), QMessageBox::Yes);
                }
            }
            else{
                QMessageBox::warning(this, tr("Warning"), tr("Invalid Password !"), QMessageBox::Yes);
            }
        }
        else{
            QMessageBox::warning(this, tr("Warning"), tr("Invalid User name !"), QMessageBox::Yes);
        }
}
