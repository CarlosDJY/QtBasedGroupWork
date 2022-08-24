#ifndef ACCOUNTCONTROL_H
#define ACCOUNTCONTROL_H

#include <QMainWindow>

namespace Ui {
class AccountControl;
}

class AccountControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountControl(QWidget *parent = nullptr);
    ~AccountControl();

private slots:
    void on_LogOutButton_clicked();

    void on_AccountButton_clicked();

    void on_PreferenceButton_clicked();

    void on_BalanceButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::AccountControl *ui;
};

#endif // ACCOUNTCONTROL_H
