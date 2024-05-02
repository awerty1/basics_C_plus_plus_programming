#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0); // Конструктор класса MainWindow
    ~MainWindow(); // Деструктор класса MainWindow

private slots:
    void on_seriesButton_clicked(); // Обработчик нажатия кнопки "seriesButton"
    void on_parallelButton_clicked(); // Обработчик нажатия кнопки "parallelButton"

private:
    Ui::MainWindow *ui; // Указатель на пользовательский интерфейс
};

#endif // MAINWINDOW_H
