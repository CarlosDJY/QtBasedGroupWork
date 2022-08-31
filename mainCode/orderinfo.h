#ifndef ORDERINFO_H
#define ORDERINFO_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class OrderInfo;
}

class OrderInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderInfo(QWidget *parent = nullptr);
    ~OrderInfo();

private slots:
    void on_BackButton_clicked();

    void on_FindOrder_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_PayButton_clicked();

private:
    Ui::OrderInfo *ui;
};

#endif // ORDERINFO_H
