#ifndef MARKET_H
#define MARKET_H
#include <QDialog>

namespace Ui {
class Wallet_Balance;
}

class Wallet_Balance : public QDialog
{
    Q_OBJECT

public:
    explicit Wallet_Balance(QWidget *parent = nullptr);
    ~Wallet_Balance();

private:
    Ui::Wallet_Balance *ui;
};

#endif // MARKET_H
