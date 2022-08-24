#ifndef PAYPAGE_H
#define PAYPAGE_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class PayPage;
}

class PayPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit PayPage(QWidget *parent = nullptr);
    ~PayPage();

private slots:
    void on_Cancel_clicked();

    void on_Confirm_clicked();

private:
    Ui::PayPage *ui;
};

#endif // PAYPAGE_H
