#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>

namespace Ui {
class ProductInfo;
}

class ProductInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductInfo(QWidget *parent = nullptr);
    ~ProductInfo();

private:
    Ui::ProductInfo *ui;
};

#endif // PRODUCTINFO_H
