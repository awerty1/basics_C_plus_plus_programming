/* 2. Разработать приложение-тренажер игры «Быки-коровы» для двухзначного
 * числа. Компьютер «загадывает» случайное двухзначное число. Игрок должен
 * его угадать, т.е. вводит число, и если одна цифра угадана, но стоит не на своем
 * месте, то компьютер выдает б – 1 (если две, то б – 2, если не одной б – 0). Если
 * цифра угадана и стоит на своем месте, то компьютер выдает к – 1. Если число
 * угадано, то игра завершается.
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Bulls-cows");
    w.resize(320, 270);

    // Если это Windows, то устанавливаем иконку
    #ifdef Q_OS_WIN
       w.setWindowIcon(QIcon("H:\\QT test\\2nd prog\\Bulls-cows\\unnamed.ico"));
    #endif


    w.show();
    
    return a.exec();
}
