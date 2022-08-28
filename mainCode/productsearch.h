#ifndef PRODUCTSEARCH_H
#define PRODUCTSEARCH_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>
#include <time.h>
struct Good//在内存中用于保存商品的结构体
{
    QString Name;
    float SellPrice;
    float BuyPrice;
    float Discount;//此变量表示折扣，如为八折，该变量设置为0.8，其他折扣同理
    QString Shop;
    QString ID;
    int Storage;
    struct tm EndTime;
    struct tm StartTime;
};
typedef struct Good Good;
namespace Ui {
class ProductSearch;
}

class ProductSearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductSearch(QWidget *parent = nullptr);
    ~ProductSearch();

private slots:
    void on_BackButton_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void DoubleClick_on_TableView(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_ComfirmingButtom_clicked();

    void on_pushButton_clicked();

private:
    Ui::ProductSearch *ui;
};

#endif // PRODUCTSEARCH_H
