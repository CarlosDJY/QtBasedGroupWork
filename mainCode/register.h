#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_BackButton_clicked();

    void on_ConfirmButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
