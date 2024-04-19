#include "market.h"
#include "ui_market.h"

Wallet_Balance::Wallet_Balance(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Wallet_Balance)
{
    ui->setupUi(this);
}

Wallet_Balance::~Wallet_Balance()
{
    delete ui;
}
