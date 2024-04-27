#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonSubtract, &QPushButton::clicked, this, &MainWindow::subtractNumbers);
    connect(ui->pushButtonMultiply, &QPushButton::clicked, this, &MainWindow::multiplyNumbers);
    connect(ui->pushButtonDivide, &QPushButton::clicked, this, &MainWindow::divideNumbers);
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::showMessage);


    connect(ui->pushButtonStoreInMemory, &QPushButton::clicked, this, &MainWindow::storeInMemory);
    connect(ui->pushButtonAddToMemory, &QPushButton::clicked, this, &MainWindow::addToMemory);
    connect(ui->pushButtonClearMemory, &QPushButton::clicked, this, &MainWindow::clearMemory);
    connect(ui->pushButtonMemoryToOperand1, &QPushButton::clicked, this, &MainWindow::memoryToOperand1);
    connect(ui->pushButtonMemoryToOperand2, &QPushButton::clicked, this, &MainWindow::memoryToOperand2);

    // Установка нового заголовка для окна калькулятора
    this->setWindowTitle("calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::subtractNumbers() {
    ui->labelPlus->setText("-");
    double num1 = ui->lineEditFirstNumber->text().toDouble();
    double num2 = ui->lineEditSecondNumber->text().toDouble();
    double result = num1 - num2;
    ui->labelResult->setText(QString::number(result));
}

void MainWindow::multiplyNumbers() {
    ui->labelPlus->setText("*");
    double num1 = ui->lineEditFirstNumber->text().toDouble();
    double num2 = ui->lineEditSecondNumber->text().toDouble();
    double result = num1 * num2;
    ui->labelResult->setText(QString::number(result));
}

void MainWindow::divideNumbers() {
    ui->labelPlus->setText("/");
    double num1 = ui->lineEditFirstNumber->text().toDouble();
    double num2 = ui->lineEditSecondNumber->text().toDouble();
    if (num2 != 0) {
        double result = num1 / num2;
        ui->labelResult->setText(QString::number(result));
    } else {
        ui->labelResult->setText("Ошибка");
    }
}

void MainWindow::showMessage() {
    ui->labelPlus->setText("+");
    double num1 = ui->lineEditFirstNumber->text().toDouble();
    double num2 = ui->lineEditSecondNumber->text().toDouble();
    double result = num1 + num2;
    ui->labelResult->setText(QString::number(result));
    //QMessageBox::information(this, "Message", "Функция не реализована!");
}


void MainWindow::storeInMemory() {
    memoryValue = ui->labelResult->text().toDouble();
    ui->lineEditMemory->setText(QString::number(memoryValue));
}

void MainWindow::addToMemory() {
    memoryValue += ui->labelResult->text().toDouble();
    ui->lineEditMemory->setText(QString::number(memoryValue));
}

void MainWindow::clearMemory() {
    memoryValue = 0.0;
    ui->lineEditMemory->setText(QString::number(memoryValue));
}

void MainWindow::memoryToOperand1() {
    ui->lineEditFirstNumber->setText(QString::number(memoryValue));
    ui->lineEditMemory->setText(QString::number(memoryValue));
}

void MainWindow::memoryToOperand2() {
    ui->lineEditSecondNumber->setText(QString::number(memoryValue));
    ui->lineEditMemory->setText(QString::number(memoryValue));
}

