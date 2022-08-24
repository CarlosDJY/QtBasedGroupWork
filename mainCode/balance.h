#ifndef BALANCE_H
#define BALANCE_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class Balance;
}

class Balance : public QMainWindow
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = nullptr);
    ~Balance();

private slots:
    void onTimeOut();

    void on_plus10_clicked();

    void on_plus50_clicked();

    void on_plus100_clicked();

    void on_plusNum_returnPressed();

    void on_BackButton_clicked();

private:
    Ui::Balance *ui;
};

#endif // BALANCE_H
