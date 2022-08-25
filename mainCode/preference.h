#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QButtonGroup>

namespace Ui {
class Preference;
}

class Preference : public QMainWindow
{
    Q_OBJECT

public:
    explicit Preference(QWidget *parent = nullptr);
    ~Preference();

private slots:
    void on_BackButton_clicked();

    void on_PriceHigh_clicked();

    void on_PriceLow_clicked();

    void on_DiscountHigh_clicked();

    void on_DiscountLow_clicked();

    void on_SalesHigh_clicked();

    void on_SalesLow_clicked();

private:
    Ui::Preference *ui;
};

#endif // PREFERENCE_H
