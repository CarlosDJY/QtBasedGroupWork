#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QMainWindow>

namespace Ui {
class AddProduct;
}

class AddProduct : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:
    void on_AddToCart_clicked();

    void on_BackButton_clicked();

private:
    Ui::AddProduct *ui;
};

#endif // ADDPRODUCT_H
