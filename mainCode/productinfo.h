#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>
struct Shoppingcars
{
    QString Name;//商品名称
    float SellPrice;//商品单价
    int Num;//商品数量
    QString ID;//商品ID
    int Storage;
};
typedef struct Shoppingcars Shoppingcars;//表示购物车的结构体
namespace Ui {
class ProductInfo;
}

class ProductInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductInfo(QWidget *parent = nullptr);
    ~ProductInfo();

private slots:
    void on_AddToCart_clicked();

    void on_BackButton_clicked();

private:
    Ui::ProductInfo *ui;
};

#endif // PRODUCTINFO_H
