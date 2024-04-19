#ifndef SWAPCRYPTO_H
#define SWAPCRYPTO_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class SwapCrypto;
}

class SwapCrypto : public QDialog
{
    Q_OBJECT

public:
    explicit SwapCrypto(QWidget *parent = nullptr);
    ~SwapCrypto();

signals:
    void inputConfirmed(double Swapinput, QString &swapFromSelection, QString &swapToSelection);

private:
    Ui::SwapCrypto *ui;
    double Swapinput;

private slots:
    void on_pushButton_clicked();
    void input_pressed();
    void on_buttonBox_clicked();
    void on_inputButton_10_released();
    void on_comboBox_3_currentIndexChanged(int index);
    void on_comboBox_4_currentIndexChanged(int index);
    void on_lineEdit_textChanged(const QString &arg1);
};

#endif // SWAPCRYPTO_H
