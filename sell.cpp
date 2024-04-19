#include "sell.h"
#include "ui_sell.h"
#include <QMessageBox>
#include <QString>
#include <QMainWindow>
#include <QPushButton>
#include "mainwindow.h"
#include <QDoubleValidator>

Sell::Sell(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Sell)
{
    ui->setupUi(this);

    //LineEdit setup to receive changes//
    connect(ui->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(on_lineEdit_textChanged(const QString &)));

    //Allow only input for doubles in the combo box //
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_currentIndexChanged(int)));
    QDoubleValidator *validator = new QDoubleValidator(this);
    ui->lineEdit->setValidator(validator);

    //setup the input buttons //
    connect(ui->inputButton_0,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_1,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_2,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_3,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_4,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_5,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_6,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_7,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_8,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_9,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_10,SIGNAL(released()),this,SLOT(input_pressed()));
    connect(ui->inputButton_11,SIGNAL(released()),this,SLOT(input_pressed()));

    //setup the combo box with icons //
    ui->comboBox->setStyleSheet("QComboBox{color: white;}, QListView { color: white; }");
    ui->comboBox->addItem(QIcon(":/res/Bitcoin.png"),"Bitcoin");
    ui->comboBox->addItem(QIcon(":/res/ethereum.png"),"Ethereum");
    ui->comboBox->addItem(QIcon(":/res/solana.png"),"Solana");
    ui->comboBox->addItem(QIcon(":/res/xrp.png"),"XRP");
    ui->comboBox->addItem(QIcon(":/res/usdc.png"),"USDC");
}

Sell::~Sell()
{
    delete ui;
}

//Allows number boxes to input values into the lineEdit//
void Sell::input_pressed()
{
    QPushButton * button = (QPushButton*) sender();

    double labelNumber;
    QString newLabel;

    labelNumber = (ui->lineEdit->text() + button->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);


    ui->lineEdit->setText(newLabel);
}

//Allows the dot operator to be pressed//
void Sell::on_inputButton_10_released()
{
    ui->lineEdit->setText(ui->inputButton_10->text() + ".");
}

//Saves input from the lineEdit//
void Sell::on_lineEdit_textChanged(const QString &arg1)
{
    Sellinput = arg1.toDouble();
}

void Sell::on_pushButton_clicked()
{
    QString selectedCrypto = ui->comboBox->currentText();
    emit inputConfirmed(Sellinput,selectedCrypto);
}

void Sell::on_comboBox_currentIndexChanged(int index)
{

}
