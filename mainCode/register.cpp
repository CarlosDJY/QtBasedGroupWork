#include "mainwindow.h"
#include "register.h"
#include "ui_register.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QFile>
#include <string>
using namespace std;
QString AdminPw = "123";

void WriteToFile(QString UserName,QString Password)
{
    QFile Q("Users.txt");
    Q.open(QIODevice::Append);
    QString Arr=UserName+' '+Password+'\n';
    std::string s=Arr.toStdString();
    const char* res=s.c_str();
    Q.write(res);
    Q.close();
}
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
int isValidID(QString Q)
{
    if(Q.length()<6||Q.length()>10)
    {
        return 0;
    }
    int i=0;
    std::string STR=Q.toStdString();
    const char* arr=STR.c_str();
    while (i<10)
    {
        if(std::isdigit(arr[i])==false)
        {
            return 1;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

void Register::on_ConfirmButton_clicked()
{
        if (isValidID(ui->AccountLineEdit->text())){
            if (isValidID(ui->PasswordLineEdit->text())){
                if(ui->AdminPasswordLineEdit->text()==AdminPw){
                    MainWindow *win = new MainWindow;
                    win->show();
                    this->close();
                    WriteToFile(ui->AccountLineEdit->text(),ui->PasswordLineEdit->text());
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
