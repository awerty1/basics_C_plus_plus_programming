#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <QKeyEvent>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Инициализация генератора случайных чисел
    srand(time(NULL));
    // Подключение сигналов от кнопок к слотам
    connect(ui->buttonCheckGuess, &QPushButton::clicked, this, &MainWindow::checkGuess);
    connect(ui->buttonNewGame, &QPushButton::clicked, this, &MainWindow::newGame);
    // Для действия "Exit" в конструкторе MainWindow
    //connect(ui->actionExit, &QAction::triggered, qApp, &QApplication::quit);
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    // Для действия "New game" в конструкторе MainWindow
    connect(ui->actionNewGame, &QAction::triggered, this, &MainWindow::newGame);
    // Для действия "Check guess" в конструкторе MainWindow
    connect(ui->actionCheckGuess, &QAction::triggered, this, &MainWindow::checkGuess);

    // Горячая клавиша для "New Game" (Ctrl+N)
//    QShortcut *shortcutNewGame = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this);
//    connect(shortcutNewGame, &QShortcut::activated, this, &MainWindow::newGame);

    // Горячая клавиша для "Check Guess" (Ctrl+Enter)
    QShortcut *shortcutCheckGuess = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Return), this);
    connect(shortcutCheckGuess, &QShortcut::activated, this, &MainWindow::checkGuess);

    // Начало новой игры при инициализации объекта окна
    newGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame()
{
    // Изменение размера окна
    resize(320, 270);
    // Генерация нового числа для угадывания
    secretNumber = randomIntBetween(10, 99);
    // Обнулить счетчик попыток
    attempts = 0;
    gameOver = false;
    ui->labelResult->setText("New game started. Try to guess the number!");
    ui->lineEdit->clear(); // Очистка текстового поля после попытки угадывания числа

    //для тестирования
    //ui->labelComputerGuess->setText("Computer's Guess: " + QString::number(secretNumber)); // Обновить метку с числом, которое компьютер загадал
}

void MainWindow::checkGuess()
{
    // Считаем неудачные попытки
    attempts++;

    if (attempts >= 10)
    {
        QString message = QString("You've reached the maximum attempts (%1).")
                            .arg(attempts);
        ui->labelComputerGuess->setText(message);
        // Перегенерировать число
        newGame();

        return;
    }

    ui->labelComputerGuess->setText("");

    // Получение числа из текстового поля
    const int guess = ui->lineEdit->text().toInt();
    if (!gameOver)
    {
        if (guess < 10 || guess > 99)
        {
            ui->labelResult->setText("Please enter a two-digit number.");
            return;
        }

        // Подсчет быков
        int numBulls = countBulls(secretNumber, guess);
        // Подсчет коров
        int numCows = countCows(secretNumber, guess);

        // Если все цифры угаданы верно
        if (numBulls == 2)
        {
            QString message = QString("Congratulations! You've guessed the number: %1!").arg(secretNumber);
            ui->labelResult->setText(message);
            // Конец игры
            gameOver = true;
        }
        else
        {
            QString result = QString("Bulls: %1, Cows: %2").arg(numBulls).arg(numCows);
            // Отображение результатов угадывания
            ui->labelResult->setText(result);
        }

         ui->lineEdit->clear(); // Очистка текстового поля после попытки угадывания числа
    }
}

int MainWindow::randomIntBetween(int min, int max)
{
    return std::rand() % (max - min + 1) + min; // Генерация случайного целого числа в заданном диапазоне
}

int MainWindow::countBulls(int secret, int guess)
{
    int bulls = 0;
    if (secret / 10 == guess / 10)
        bulls++;
    if (secret % 10 == guess % 10)
        bulls++;

    // Возвращаемое количество быков
    return bulls;
}

int MainWindow::countCows(int secret, int guess)
{
    int cows = 0;
    if ((secret / 10 == guess % 10) || (secret % 10 == guess / 10))
        cows++;

    // Возвращаемое количество коров
    return cows;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (this->isActiveWindow() && event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_Q)
    {
        QApplication::quit(); // Выход из приложения при нажатии Ctrl+Q
    }
    else
    {
        QMainWindow::keyPressEvent(event);
    }
}
