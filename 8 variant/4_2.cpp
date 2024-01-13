/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10.
Подсчитать и вывести дополнительным столбцом среднее арифметическое 
каждой строки. Найти и вывести наибольший элемент этого столбца
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

int main() 
{
    int n, m;
    int matrix[MAX_SIZE][MAX_SIZE];
    float avg[MAX_SIZE];
    float max_avg = 0;

    // ввод размера матрицы
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    // заполнение матрицы случайными числами
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    // вычисление среднего арифметического каждой строки
    for (int i = 0; i < n; i++) 
    {
        float sum = 0;
        for (int j = 0; j < m; j++) 
        {
            sum += matrix[i][j];
        }
        avg[i] = sum / m;
    }

    // вывод матрицы и среднего арифметического каждой строки
    cout << "Исходная матрица" 
        << n << "x" 
        << m <<":"<< endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << setw(3) << "AVG = "<<avg[i] << endl;
    }

    // поиск наибольшего элемента в столбце со средним арифметическим
    for (int j = 0; j < n; j++) 
    {
        if (avg[j] > max_avg) 
        {
            max_avg = avg[j];
        }
    }

    cout << "Наибольший элемент в столбце со средним арифметическим: " << max_avg << endl;

    return 0;
}