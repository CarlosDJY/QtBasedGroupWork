#ifndef PRODUCTSEARCH_H
#define PRODUCTSEARCH_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>

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

private:
    Ui::ProductSearch *ui;
};

#endif // PRODUCTSEARCH_H
