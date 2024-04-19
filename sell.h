#ifndef SELL_H
#define SELL_H
#include "mainwindow.h"
#include <QDoubleValidator>
#include <QDialog>

namespace Ui {
class Sell;
}

class Sell : public QDialog
{
    Q_OBJECT

public:
    explicit Sell(QWidget *parent = nullptr);
    ~Sell();

signals:
    void inputConfirmed(double Sellinput, QString &cryptoSelection);

private:
    Ui::Sell *ui;
    double Sellinput;
    //stores input from the line edit

private slots:
    void on_pushButton_clicked();
    void input_pressed();
    void on_inputButton_10_released();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_comboBox_currentIndexChanged(int index);
};

#endif // SELL_H
