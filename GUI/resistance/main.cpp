/*
 * 4 вариант
 * 1. Написать программу вычисления сопротивления электрической цепи,
 * состоящей из двух сопротивлений. Сопротивления могут быть соединены
 * последовательно или параллельно.  Исходные данные – значения двух
 * сопротивлений. Также имеется две кнопки – "Последовательное соединение" и
 * "Параллельное соединение".
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setWindowTitle("Сопротивление электронной цепи"); // Установка нового заголовка
    w.setWindowTitle("Circuit Resistance");
    w.resize(360, 200);
    w.setWindowIcon(QIcon("H:\\QT test\\1st prog\\resistance\\"
                          "pngtree-resistance-vector-icon-design-illustration-png-image_6591853.png"));
    w.show();
    
    return a.exec();
}

