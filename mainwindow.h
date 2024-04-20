#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include "./ui_mainwindow.h"
#include "buy.h"
#include "sell.h"
#include "swapcrypto.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void updateLabel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void updateCryptoBuy(double Buyinput, QString cryptoSelection);

    void updateCryptoSell(double Sellinput, QString cryptoSelection);

    void cryptoSwap(double Sellinput, QString swapFromSelection, QString swapToSelection);

private:
    Ui::MainWindow *ui;
    //create variables to store crypto values //
    double walletBal;
    double btc;
    double eth;
    double sol;
    double xrp;
    double usdc;

    //create variables to display how much crypto is held //
    double btcHeld;
    double ethHeld;
    double solHeld;
    double xrpHeld;
};

#endif // MAINWINDOW_H
