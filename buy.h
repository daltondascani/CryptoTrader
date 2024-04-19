#ifndef BUY_H
#define BUY_H
#include <QDialog>
#include "mainwindow.h"
#include <QDoubleValidator>

namespace Ui {
class Buy;
}

class Buy : public QDialog
{
    Q_OBJECT

public:
    explicit Buy(QWidget *parent = nullptr);
    ~Buy();

signals:
    void inputConfirmed(double Buyinput, const QString &crypto);

private slots:
    void on_pushButton_clicked();
    void input_pressed();
    void on_inputButton_10_released();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Buy *ui;
    double Buyinput;
    //stores input from the line edit
};

#endif // BUY_H
