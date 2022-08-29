#ifndef MAINWINDOW2ADMIN_H
#define MAINWINDOW2ADMIN_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class MainWindow2Admin;
}

class MainWindow2Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2Admin(QWidget *parent = nullptr);
    ~MainWindow2Admin();

private slots:
    void on_AccountButton_clicked();

    void on_OrderButton_clicked();

    void on_ProductButton_clicked();

private:
    Ui::MainWindow2Admin *ui;
};

#endif // MAINWINDOW2ADMIN_H
