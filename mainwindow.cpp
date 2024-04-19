#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "market.h"
#include "buy.h"
#include "sell.h"
#include "swapcrypto.h"
#include <QUrl>
#include <QDesktopServices>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>

//MainWindow mainWindowInstance;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //crypto balances are initialized //
    btc = 0.00;
    eth = 0.00;
    sol = 0.00;
    xrp = 0.00;
    usdc= 10000.00;
    walletBal = btc + eth + sol + xrp + usdc;

    //Held amounts are initialized
    btcHeld = btc / 64000.00;
    ethHeld = eth / 3200.00;
    solHeld = sol / 140.00;
    xrpHeld = xrp / 0.50;

    // Set default crypto balances for trading //
    ui->btc_balance->setText(QString::number(btc));
    ui->eth_balance->setText(QString::number(eth));
    ui->sol_balance->setText(QString::number(sol));
    ui->xrp_balance->setText(QString::number(xrp));
    ui->usdc_balance->setText(QString::number(usdc));
    ui->wallet_balance->setText(QString::number(walletBal));

    //Set default amounts held for portfolio //
    ui->btc_portfolio->setText(QString::number(btcHeld));
    ui->eth_portfolio->setText(QString::number(ethHeld));
    ui->sol_portfolio->setText(QString::number(solHeld));
    ui->xrp_portfolio->setText(QString::number(xrpHeld));
    ui->usdc_portfolio->setText(QString::number(usdc));


    //timer created to update the labels//
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateLabel()));
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabel()
{
    //label widgets update with the current values of crypto held //
    ui->btc_balance->setText(QString::number(btc));
    ui->eth_balance->setText(QString::number(eth));
    ui->sol_balance->setText(QString::number(sol));
    ui->xrp_balance->setText(QString::number(xrp));
    ui->usdc_balance->setText(QString::number(usdc));
    ui->wallet_balance->setText(QString::number(walletBal));

    ui->btc_portfolio->setText(QString::number(btcHeld));
    ui->eth_portfolio->setText(QString::number(ethHeld));
    ui->sol_portfolio->setText(QString::number(solHeld));
    ui->xrp_portfolio->setText(QString::number(xrpHeld));
    ui->usdc_portfolio->setText(QString::number(usdc));
}

void MainWindow::updateCryptoBuy(double Buyinput, QString cryptoSelection)
{
    if (cryptoSelection == "Bitcoin" && Buyinput <= usdc){
        btc +=Buyinput;
        btcHeld = btc /64000.00;
        walletBal +=Buyinput;
        usdc-=Buyinput;
        walletBal -=Buyinput;
        ui->btc_balance->setText(QString::number(btc));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->btc_portfolio->setText(QString::number(btcHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Buy Complete");
        mb.setInformativeText("Purchase of $BTC Successful!");
        QPixmap exportSuccess(":/res/Bitcoin.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
        }

    else if (cryptoSelection == "Ethereum" && Buyinput <= usdc){
        eth +=Buyinput;
        ethHeld = eth / 3200.00;
        walletBal +=Buyinput;
        usdc-=Buyinput;
        walletBal -=Buyinput;
        ui->eth_balance->setText(QString::number(eth));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->eth_portfolio->setText(QString::number(ethHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Buy Complete");
        mb.setInformativeText("Purchase of $ETH Successful!");
        QPixmap exportSuccess(":/res/ethereum.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "Solana" && Buyinput <= usdc){
        sol +=Buyinput;
        solHeld = sol / 140.00;
        walletBal +=Buyinput;
        usdc-=Buyinput;
        walletBal -=Buyinput;
        ui->sol_balance->setText(QString::number(sol));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->sol_portfolio->setText(QString::number(solHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Buy Complete");
        mb.setInformativeText("Purchase of $SOL Successful!");
        QPixmap exportSuccess(":/res/solana.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "XRP" && Buyinput <= usdc){
        xrp +=Buyinput;
        xrpHeld = xrp / 0.50;
        walletBal +=Buyinput;
        usdc-=Buyinput;
        walletBal -=Buyinput;
        ui->xrp_balance->setText(QString::number(xrp));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->xrp_portfolio->setText(QString::number(xrpHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Buy Complete");
        mb.setInformativeText("Purchase of $XRP Successful!");
        QPixmap exportSuccess(":/res/xrp.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "USDC" && Buyinput <= usdc){
        usdc +=Buyinput;
        walletBal +=Buyinput;
        usdc-=Buyinput;
        walletBal -=Buyinput;
        ui->usdc_balance->setText(QString::number(usdc));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->usdc_portfolio->setText(QString::number(usdc));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Buy Issue");
        mb.setInformativeText("You cannot buy $USDC with $USDC. Please select a vaild option.");
        QPixmap exportSuccess(":/res/usdc.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }
    else
    {
        QMessageBox mb;
        mb.setText("Buy Failed");
        mb.setInformativeText("You do not have enough $USDC to complete this purchase.");
        QPixmap exportSuccess(":/res/error.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

}

void MainWindow::updateCryptoSell(double Sellinput, QString cryptoSelection)
{
    if (cryptoSelection == "Bitcoin" && Sellinput <= btc)
    {
        btc -=Sellinput;
        btcHeld = btc /64000.00;
        walletBal -=Sellinput;
        usdc+=Sellinput;
        walletBal +=Sellinput;
        ui->btc_balance->setText(QString::number(btc));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->btc_portfolio->setText(QString::number(btcHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Sell Complete");
        mb.setInformativeText("$BTC Sold Successfully!");
        QPixmap exportSuccess(":/res/Bitcoin.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "Ethereum" && Sellinput <= eth)
    {
        eth -=Sellinput;
        ethHeld = eth / 3200.00;
        walletBal -=Sellinput;
        usdc+=Sellinput;
        walletBal +=Sellinput;
        ui->eth_balance->setText(QString::number(eth));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->eth_portfolio->setText(QString::number(ethHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Sell Complete");
        mb.setInformativeText("$ETH Sold Successfully!");
        QPixmap exportSuccess(":/res/ethereum.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "Solana" && Sellinput <= sol)
    {
        sol -=Sellinput;
        solHeld = sol / 140.00;
        walletBal -=Sellinput;
        usdc+=Sellinput;
        walletBal +=Sellinput;
        ui->sol_balance->setText(QString::number(sol));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->sol_portfolio->setText(QString::number(solHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Sell Complete");
        mb.setInformativeText("$SOL Sold Successfully!");
        QPixmap exportSuccess(":/res/solana.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "XRP" && Sellinput <= xrp)
    {
        xrp -=Sellinput;
        xrpHeld = xrp / 0.50;
        walletBal -=Sellinput;
        usdc+=Sellinput;
        walletBal +=Sellinput;
        ui->xrp_balance->setText(QString::number(xrp));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->xrp_portfolio->setText(QString::number(xrpHeld));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Sell Complete");
        mb.setInformativeText("$XRP Sold Successfully!");
        QPixmap exportSuccess(":/res/xrp.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

    else if (cryptoSelection == "USDC" && Sellinput <= usdc)
    {
        usdc -=Sellinput;
        walletBal -=Sellinput;
        ui->usdc_balance->setText(QString::number(usdc));
        ui->wallet_balance->setText(QString::number(walletBal));
        ui->usdc_portfolio->setText(QString::number(usdc));

        //Message box displaying a successful buy!//
        QMessageBox mb;
        mb.setText("Sell Issue");
        mb.setInformativeText("You cannot sell $USDC with $USDC. Please select a vaild option.");
        QPixmap exportSuccess(":/res/usdc.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }
    else
    {
        QMessageBox mb;
        mb.setText("Sell Failed");
        mb.setInformativeText("You do not have enough crypto to complete this sale.");
        QPixmap exportSuccess(":/res/error.png");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mb.setIconPixmap(exportSuccess);
        mb.exec();
    }

}

void MainWindow::cryptoSwap(double SwapInput, QString swapFromSelection, QString swapToSelection)
{
        if (swapFromSelection == "Bitcoin")
        {
            if (swapToSelection == "Ethereum" && SwapInput <= btc){
                btc -=SwapInput;
                btcHeld = btc /64000.00;
                walletBal -=SwapInput;
                eth +=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal +=SwapInput;
                ui->eth_balance->setText(QString::number(eth));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->btc_portfolio->setText(QString::number(btcHeld));
                ui->eth_portfolio->setText(QString::number(ethHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$BTC Successfully Swapped to $ETH");
                QPixmap exportSuccess(":/res/Bitcoin.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Solana" && SwapInput <= btc){
                btc -=SwapInput;
                btcHeld = btc /64000.00;
                walletBal -=SwapInput;
                sol +=SwapInput;
                solHeld = sol / 140.00;
                walletBal +=SwapInput;
                ui->sol_balance->setText(QString::number(sol));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->btc_portfolio->setText(QString::number(btcHeld));
                ui->sol_portfolio->setText(QString::number(solHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$BTC Successfully Swapped to $SOL");
                QPixmap exportSuccess(":/res/Bitcoin.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "XRP" && SwapInput <= btc){
                btc -=SwapInput;
                btcHeld = btc /64000.00;
                walletBal -=SwapInput;
                xrp +=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal +=SwapInput;
                ui->xrp_balance->setText(QString::number(xrp));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->btc_portfolio->setText(QString::number(btcHeld));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$BTC Successfully Swapped to $XRP");
                QPixmap exportSuccess(":/res/Bitcoin.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapFromSelection == "USDC" && SwapInput <= btc){
                btc -=SwapInput;
                btcHeld = btc /64000.00;
                walletBal -=SwapInput;
                usdc +=SwapInput;
                walletBal +=SwapInput;
                ui->usdc_balance->setText(QString::number(usdc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->btc_portfolio->setText(QString::number(btcHeld));
                ui->usdc_portfolio->setText(QString::number(usdc));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$BTC Successfully Swapped to $USDC");
                QPixmap exportSuccess(":/res/Bitcoin.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
            else
            {
                QMessageBox mb;
                mb.setText("Swap Failed");
                mb.setInformativeText("You do not have enough crypto to complete this transaction.");
                QPixmap exportSuccess(":/res/error.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
        }

        else if (swapFromSelection == "Ethereum"){
            if (swapToSelection == "Bitcoin" && SwapInput <= eth){
                eth -=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal -=SwapInput;
                btc +=SwapInput;
                btcHeld = btc /64000.00;
                walletBal +=SwapInput;
                ui->btc_balance->setText(QString::number(btc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->eth_portfolio->setText(QString::number(ethHeld));
                ui->btc_portfolio->setText(QString::number(btcHeld));

                //Message box displaying a successful swap!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$ETH Successfully Swapped to $BTC");
                QPixmap exportSuccess(":/res/ethereum.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Solana" && SwapInput <= eth){
                eth -=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal -=SwapInput;
                sol +=SwapInput;
                solHeld = sol / 140.00;
                walletBal +=SwapInput;
                ui->sol_balance->setText(QString::number(sol));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->eth_portfolio->setText(QString::number(ethHeld));
                ui->sol_portfolio->setText(QString::number(solHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$ETH Successfully Swapped to $SOL");
                QPixmap exportSuccess(":/res/ethereum.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "XRP" && SwapInput <= eth){
                eth -=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal -=SwapInput;
                xrp +=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal +=SwapInput;
                ui->xrp_balance->setText(QString::number(xrp));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->eth_portfolio->setText(QString::number(ethHeld));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$ETH Successfully Swapped to $XRP");
                QPixmap exportSuccess(":/res/ethereum.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapFromSelection == "USDC" && SwapInput <= eth){
                eth -=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal -=SwapInput;
                usdc +=SwapInput;
                walletBal +=SwapInput;
                ui->usdc_balance->setText(QString::number(usdc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->eth_portfolio->setText(QString::number(ethHeld));
                ui->usdc_portfolio->setText(QString::number(usdc));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$ETH Successfully Swapped to $USDC");
                QPixmap exportSuccess(":/res/ethereum.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
            else
            {
                QMessageBox mb;
                mb.setText("Swap Failed");
                mb.setInformativeText("You do not have enough crypto to complete this transaction.");
                QPixmap exportSuccess(":/res/error.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
        }

        else if (swapFromSelection == "Solana"){
            if (swapToSelection == "Bitcoin" && SwapInput <= sol){
                sol -=SwapInput;
                solHeld = sol / 140.00;
                walletBal -=SwapInput;
                btc +=SwapInput;
                btcHeld = btc /64000.00;
                walletBal +=SwapInput;
                ui->btc_balance->setText(QString::number(btc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->sol_portfolio->setText(QString::number(solHeld));
                ui->btc_portfolio->setText(QString::number(btcHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$SOL Successfully Swapped to $BTC");
                QPixmap exportSuccess(":/res/solana.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Ethereum" && SwapInput <= sol){
                sol -=SwapInput;
                solHeld = sol / 140.00;
                walletBal -=SwapInput;
                eth +=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal +=SwapInput;
                ui->eth_balance->setText(QString::number(eth));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->sol_portfolio->setText(QString::number(solHeld));
                ui->eth_portfolio->setText(QString::number(ethHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$SOL Successfully Swapped to $ETH");
                QPixmap exportSuccess(":/res/solana.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "XRP" && SwapInput <= sol){
                sol -=SwapInput;
                solHeld = sol / 140.00;
                walletBal -=SwapInput;
                xrp +=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal +=SwapInput;
                ui->xrp_balance->setText(QString::number(xrp));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->sol_portfolio->setText(QString::number(solHeld));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$SOL Successfully Swapped to $XRP");
                QPixmap exportSuccess(":/res/solana.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapFromSelection == "USDC" && SwapInput <= sol){
                sol -=SwapInput;
                solHeld = sol / 140.00;
                walletBal -=SwapInput;
                usdc +=SwapInput;
                walletBal +=SwapInput;
                ui->usdc_balance->setText(QString::number(usdc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->sol_portfolio->setText(QString::number(solHeld));
                ui->usdc_portfolio->setText(QString::number(usdc));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$SOL Successfully Swapped to $USDC");
                QPixmap exportSuccess(":/res/solana.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
            else
            {
                QMessageBox mb;
                mb.setText("Swap Failed");
                mb.setInformativeText("You do not have enough crypto to complete this transaction.");
                QPixmap exportSuccess(":/res/error.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
        }

        else if (swapFromSelection == "XRP"){
            if (swapToSelection == "Bitcoin" && SwapInput <= xrp){
                xrp -=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal -=SwapInput;
                btc +=SwapInput;
                btcHeld = btc /64000.00;
                walletBal +=SwapInput;
                ui->btc_balance->setText(QString::number(btc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));
                ui->btc_portfolio->setText(QString::number(btcHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$XRP Successfully Swapped to $BTC");
                QPixmap exportSuccess(":/res/xrp.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Ethereum" && SwapInput <= xrp){
                xrp -=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal -=SwapInput;
                eth +=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal +=SwapInput;
                ui->eth_balance->setText(QString::number(eth));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));
                ui->eth_portfolio->setText(QString::number(ethHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$XRP Successfully Swapped to $ETH");
                QPixmap exportSuccess(":/res/xrp.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Solana" && SwapInput <= xrp){
                xrp -=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal -=SwapInput;
                sol +=SwapInput;
                solHeld = sol / 140.00;
                walletBal +=SwapInput;
                ui->sol_balance->setText(QString::number(sol));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));
                ui->sol_portfolio->setText(QString::number(solHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$XRP Successfully Swapped to $SOL");
                QPixmap exportSuccess(":/res/xrp.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapFromSelection == "USDC" && SwapInput <= xrp){
                xrp -=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal -=SwapInput;
                usdc +=SwapInput;
                walletBal +=SwapInput;
                ui->usdc_balance->setText(QString::number(usdc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));
                ui->usdc_portfolio->setText(QString::number(usdc));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$XRP Successfully Swapped to $USDC");
                QPixmap exportSuccess(":/res/xrp.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
            else
            {
                QMessageBox mb;
                mb.setText("Swap Failed");
                mb.setInformativeText("You do not have enough crypto to complete this transaction.");
                QPixmap exportSuccess(":/res/error.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
        }

        else if (swapFromSelection == "USDC"){
            if (swapToSelection == "Bitcoin" && SwapInput <= usdc){
                usdc -=SwapInput;
                walletBal -=SwapInput;
                btc +=SwapInput;
                btcHeld = btc /64000.00;
                walletBal +=SwapInput;
                ui->btc_balance->setText(QString::number(btc));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->usdc_portfolio->setText(QString::number(usdc));
                ui->btc_portfolio->setText(QString::number(btcHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$USDC Successfully Swapped to $BTC");
                QPixmap exportSuccess(":/res/usdc.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Ethereum" && SwapInput <= usdc){
                usdc -=SwapInput;
                walletBal -=SwapInput;
                eth +=SwapInput;
                ethHeld = eth / 3200.00;
                walletBal +=SwapInput;
                ui->eth_balance->setText(QString::number(eth));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->usdc_portfolio->setText(QString::number(usdc));
                ui->eth_portfolio->setText(QString::number(ethHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$USDC Successfully Swapped to $ETH");
                QPixmap exportSuccess(":/res/usdc.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "Solana" && SwapInput <= usdc){
                usdc -=SwapInput;
                walletBal -=SwapInput;
                sol +=SwapInput;
                solHeld = sol / 140.00;
                walletBal +=SwapInput;
                ui->sol_balance->setText(QString::number(sol));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->usdc_portfolio->setText(QString::number(usdc));
                ui->sol_portfolio->setText(QString::number(solHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$USDC Successfully Swapped to $SOL");
                QPixmap exportSuccess(":/res/usdc.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }

            else if (swapToSelection == "XRP" && SwapInput <= usdc){
                usdc -=SwapInput;
                walletBal -=SwapInput;
                xrp +=SwapInput;
                xrpHeld = xrp / 0.50;
                walletBal +=SwapInput;
                ui->xrp_balance->setText(QString::number(xrp));
                ui->wallet_balance->setText(QString::number(walletBal));
                ui->usdc_portfolio->setText(QString::number(usdc));
                ui->xrp_portfolio->setText(QString::number(xrpHeld));

                //Message box displaying a successful buy!//
                QMessageBox mb;
                mb.setText("Swap Complete");
                mb.setInformativeText("$USDC Successfully Swapped to $XRP");
                QPixmap exportSuccess(":/res/usdc.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
            else
            {
                QMessageBox mb;
                mb.setText("Swap Failed");
                mb.setInformativeText("You do not have enough crypto to complete this transaction.");
                QPixmap exportSuccess(":/res/error.png");
                mb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                mb.setIconPixmap(exportSuccess);
                mb.exec();
            }
        }
    }


void MainWindow::on_pushButton_clicked()
{

    QDesktopServices::openUrl(QUrl("https://coinmarketcap.com/", QUrl::TolerantMode));
}


void MainWindow::on_pushButton_2_clicked()
{
    Buy buy_window;
    buy_window.setModal(true);
    connect(&buy_window,&Buy::inputConfirmed,this,&MainWindow::updateCryptoBuy);
    buy_window.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    Sell sell_window;
    sell_window.setModal(true);
    connect(&sell_window,&Sell::inputConfirmed,this,&MainWindow::updateCryptoSell);
    sell_window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    SwapCrypto swap_window;
    swap_window.setModal(true);
    connect(&swap_window,&SwapCrypto::inputConfirmed,this,&MainWindow::cryptoSwap);
    swap_window.exec();
}
