#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Установка интерфейса для MainWindow
    ui->setupUi(this);
    // Подключение кнопки для рассчета последовательной цепи
    connect(ui->seriesButton, &QPushButton::clicked, this, &MainWindow::on_seriesButton_clicked);
    // Подключение кнопки для рассчета параллельной цепи
    connect(ui->parallelButton, &QPushButton::clicked, this, &MainWindow::on_parallelButton_clicked);
}

MainWindow::~MainWindow()
{
    // Освобождение ресурсов от ui
    delete ui;
}

void MainWindow::on_seriesButton_clicked()
{
    bool ok1, ok2;
    double r1 = ui->lineEdit_R1->text().toDouble(&ok1);
    double r2 = ui->lineEdit_R2->text().toDouble(&ok2);

    //Некорректный ввод
    if (!ok1 || !ok2)
    {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, введите корректные числовые значения для r1 и r2.");
        return;
    }

    // Вычисление сопротивления в последовательной цепи
    double totalResistance = r1 + r2;
    ui->label_Result->setText(QString("Общее сопротивление при последовательном соединении: %1 Ом").arg(totalResistance));
}

void MainWindow::on_parallelButton_clicked()
{
    bool ok1, ok2;
    double r1 = ui->lineEdit_R1->text().toDouble(&ok1);
    double r2 = ui->lineEdit_R2->text().toDouble(&ok2);

    //Некорректный ввод
    if (!ok1 || !ok2)
    {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, введите корректные числовые значения для r1 и r2.");
        return;
    }

    // Проверка деления на ноль
    if (r1 == 0 || r2 == 0)
    {
        QMessageBox::critical(this, "Ошибка", "Значение сопротивления не может быть равно нулю.");
        return;
    }

    // Вычисление сопротивления в параллельной цепи
    double totalResistance = 1 / (1 / r1 + 1 / r2);
    // Отображение результата
    ui->label_Result->setText(QString("Общее сопротивление при параллельном соединении: %1 Ом").arg(totalResistance));
}
