#ifndef ACCOUNTCONTROLADMIN_H
#define ACCOUNTCONTROLADMIN_H

#include <QMainWindow>

namespace Ui {
class AccountControlAdmin;
}

class AccountControlAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountControlAdmin(QWidget *parent = nullptr);
    ~AccountControlAdmin();

private slots:
    void on_AccountButton_clicked();

    void on_LogOutButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::AccountControlAdmin *ui;
};

#endif // ACCOUNTCONTROLADMIN_H
