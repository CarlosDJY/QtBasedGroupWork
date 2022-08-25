#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_BackButton_clicked();

    void on_ConfirmButton_clicked();

private:
    Ui::Login *ui;
};


#endif // LOGIN_H
