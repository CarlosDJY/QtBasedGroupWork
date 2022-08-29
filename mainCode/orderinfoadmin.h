#ifndef ORDERINFOADMIN_H
#define ORDERINFOADMIN_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class OrderInfoAdmin;
}

class OrderInfoAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderInfoAdmin(QWidget *parent = nullptr);
    ~OrderInfoAdmin();

private slots:
    void on_BackButton_clicked();

private:
    Ui::OrderInfoAdmin *ui;
};

#endif // ORDERINFOADMIN_H
