#include "swap.h"
#include "ui_swap.h"

swap::swap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::swap)
{
    ui->setupUi(this);
}

swap::~swap()
{
    delete ui;
}
