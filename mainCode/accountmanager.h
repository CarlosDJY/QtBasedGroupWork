#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QMainWindow>

namespace Ui {
class AccountManager;
}

class AccountManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountManager(QWidget *parent = nullptr);
    ~AccountManager();

private:
    Ui::AccountManager *ui;
};

#endif // ACCOUNTMANAGER_H
