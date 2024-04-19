#include "swapcrypto.h"
#include "ui_swapcrypto.h"
#include <QMessageBox>
#include <QString>

SwapCrypto::SwapCrypto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SwapCrypto)
{

    ui->setupUi(this);

    //LineEdit setup to receive changes//
    connect(ui->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(on_lineEdit_textChanged(const QString &)));

    //Allow only input for doubles in the combo box //
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_3_currentIndexChanged(int)));
    connect(ui->comboBox_4,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_4_currentIndexChanged(int)));
    QDoubleValidator *validator = new QDoubleValidator(this);
    ui->lineEdit->setValidator(validator);

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

    ui->comboBox_3->setStyleSheet("QComboBox{color: white;}, QListView { color: white; }");
    ui->comboBox_3->addItem(QIcon(":/res/Bitcoin.png"),"Bitcoin");
    ui->comboBox_3->addItem(QIcon(":/res/ethereum.png"),"Ethereum");
    ui->comboBox_3->addItem(QIcon(":/res/solana.png"),"Solana");
    ui->comboBox_3->addItem(QIcon(":/res/xrp.png"),"XRP");
    ui->comboBox_3->addItem(QIcon(":/res/usdc.png"),"USDC");

    ui->comboBox_4->setStyleSheet("QComboBox{color: white;}, QListView { color: white; }");
    ui->comboBox_4->addItem(QIcon(":/res/Bitcoin.png"),"Bitcoin");
    ui->comboBox_4->addItem(QIcon(":/res/ethereum.png"),"Ethereum");
    ui->comboBox_4->addItem(QIcon(":/res/solana.png"),"Solana");
    ui->comboBox_4->addItem(QIcon(":/res/xrp.png"),"XRP");
    ui->comboBox_4->addItem(QIcon(":/res/usdc.png"),"USDC");
}

SwapCrypto::~SwapCrypto()
{
    delete ui;
}

void SwapCrypto::input_pressed()
{
    QPushButton * button = (QPushButton*) sender();

    double labelNumber;
    QString newLabel;

    labelNumber = (ui->lineEdit->text() + button->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);


    ui->lineEdit->setText(newLabel);
}

//Allows the dot operator to be pressed//
void SwapCrypto::on_inputButton_10_released()
{
    ui->lineEdit->setText(ui->inputButton_10->text() + ".");
}

void SwapCrypto::on_lineEdit_textChanged(const QString &arg1)
{
    Swapinput = arg1.toDouble();
}

void SwapCrypto::on_pushButton_clicked()
{
    QString swapFromSelection = ui->comboBox_3->currentText();
    QString swapToSelection = ui->comboBox_4->currentText();
    emit inputConfirmed(Swapinput,swapFromSelection,swapToSelection);
}


void SwapCrypto::on_comboBox_3_currentIndexChanged(int index)
{

}


void SwapCrypto::on_comboBox_4_currentIndexChanged(int index)
{

}
void SwapCrypto::on_buttonBox_clicked()
{
    close();
}

