#include "buy.h"
#include "ui_buy.h"
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"
#include <QDoubleValidator>

Buy::Buy(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Buy)
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

Buy::~Buy()
{
    delete ui;
}

//Allows number boxes to input values into the lineEdit//
void Buy::input_pressed()
{

    QPushButton * button = (QPushButton*) sender();

    double labelNumber;
    QString newLabel;

    labelNumber = (ui->lineEdit->text() + button->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);


    ui->lineEdit->setText(newLabel);

}

//Allows the dot operator to be pressed//
void Buy::on_inputButton_10_released()
{
    ui->lineEdit->setText(ui->inputButton_10->text() + ".");
}

//Saves input from the lineEdit//
void Buy::on_lineEdit_textChanged(const QString &arg1)
{
    Buyinput = arg1.toDouble();
}

// Takes current selection of the combo box //
void Buy::on_comboBox_currentIndexChanged(int index)
{
    //QString selection = ui->comboBox->currentText();
}

//confirms transaction and emitts signal to confirm the buy//
void Buy::on_pushButton_clicked()
{
    QString selectedCrypto = ui->comboBox->currentText();
    emit inputConfirmed(Buyinput, selectedCrypto);
}

