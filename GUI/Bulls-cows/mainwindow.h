#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    // Конструктор класса MainWindow
    explicit MainWindow(QWidget *parent = 0);
    // Деструктор класса MainWindow
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    // Указатель на пользовательский интерфейс
    Ui::MainWindow *ui;
    // Секретное число, загаданное компьютером
    int secretNumber;
    // Флаг, показывающий завершение игры
    bool gameOver;
    // Переменная для отслеживания количества попыток
    int attempts;

private slots:
    // Слот для проверки угаданного числа
    void checkGuess();
    // Слот для начала новой игры
    void newGame();

    // Генерация случайного числа в заданном диапазоне
    int randomIntBetween(int min, int max);
    // Подсчет количества "быков"
    int countBulls(int secret, int guess);
    // Подсчет количества "коров"
    int countCows(int secret, int guess);
};

#endif // MAINWINDOW_H
