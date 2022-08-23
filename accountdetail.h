#ifndef ACCOUNTDETAIL_H
#define ACCOUNTDETAIL_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

extern int DetailReady;
extern int NeedEdit;

namespace Ui {
class AccountDetail;
}

class AccountDetail : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountDetail(QWidget *parent = nullptr);
    ~AccountDetail();

private slots:
    void on_ReturnButton_clicked();

    void on_SaveButton_clicked();

    void on_NameEdit_editingFinished();

    void on_MaleChoose_clicked();

    void on_FemaleChoose_clicked();

    void on_SecretChoose_clicked();

    void on_PhoneEdit_editingFinished();

    void on_MailEdit_editingFinished();

    void on_AddressEdit_editingFinished();

private:
    Ui::AccountDetail *ui;
};

#endif // ACCOUNTDETAIL_H
