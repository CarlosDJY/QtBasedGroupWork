#ifndef PRODUCTSEARCHADMIN_H
#define PRODUCTSEARCHADMIN_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>
namespace Ui {
class ProductSearchAdmin;
}

class ProductSearchAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductSearchAdmin(QWidget *parent = nullptr);
    ~ProductSearchAdmin();

private slots:
    void on_BackButton_clicked();

    void on_pushButton_3_clicked();

    void on_ComfirmingButtom_clicked();

private:
    Ui::ProductSearchAdmin *ui;
};

#endif // PRODUCTSEARCHADMIN_H
