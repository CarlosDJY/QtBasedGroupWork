#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();

private slots:
    void on_BackButton_clicked();

    void on_BuyAll_clicked();

    void on_NextPage_clicked();

    void on_FindCart_clicked();

    void on_PrevPage_clicked();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
