#ifndef PRODUCTSEARCH_H
#define PRODUCTSEARCH_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>
#include <time.h>
#include <QFile>
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
    int Sale;
};
typedef struct Good Good;
extern Good ExistGoods[100];//从文件中读取所有内容存入内存中，保存在此结构体数组中
extern Good Tmp[100];//用于筛选过程的临时结构体数组
int WriteToMemory();//从文件中读取所有内容写入结构体数组中，返回商品总数
int SearchByName(int n,QString Search);/*通过商品名称筛选，n为符合前序筛选结果的商品总数，Search为查询名称*/
int SearchForDiscount(int n);//按是否折扣查找商品，n为符合之前查找条件下的商品总数，返回符合原有与新增查找条件下的商品总数
void SortingBySellPrice(int n);//按售价从低到高排序已筛选商品，n为符合筛选规则商品的数目
void SortingByTheSaledAmount(int n);//按销量从高到低排序已筛选商品，n为符合筛选规则商品的数目
int SearchByShop(int n,QString Search);//按商店名称查找商品，n为符合之前查找条件下的商品总数，返回符合原有与新增查找条件下的商品总数
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
