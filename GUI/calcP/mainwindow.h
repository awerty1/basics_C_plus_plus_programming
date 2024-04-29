#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void subtractNumbers();
    void multiplyNumbers();
    void divideNumbers();
    void showMessage();

    // Добавленные слоты для работы с памятью
    void storeInMemory();
    void addToMemory();
    void clearMemory();
    void memoryToOperand1();
    void memoryToOperand2();


private:
    Ui::MainWindow *ui;
    // Глобальная переменная для хранения значения памяти
    double memoryValue = 0.0;
};

#endif // MAINWINDOW_H
