/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Отсортировать все строки с четными номерами по убыванию (нумерация строк 
ведется со стороны пользователя, т.е. с единицы). Вывести преобразованную 
таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <limits>

int main()
{
    srand(time(NULL)); // инициализация генератора случайных чисел
    
    int n, m;
    bool input_success = false;
    
    do 
    {
        std::cout << "Введите количество строк матрицы: ";
        if (!(std::cin >> n) || n <= 0 || std::cin.fail()) 
        {
            std::cin.clear(); // сброс флагов ошибок потока ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
            std::cout << "Ошибка ввода. Попробуйте еще раз." << std::endl;
        } 
        else 
        {
            input_success = true;
        }
    } 
    while (!input_success);
    
    input_success = false;
    
    do 
    {
        std::cout << "Введите количество столбцов матрицы: ";
        if (!(std::cin >> m) || m <= 0 || std::cin.fail()) 
        {
            std::cin.clear(); // сброс флагов ошибок потока ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
            std::cout << "Ошибка ввода. Попробуйте еще раз." << std::endl;
        } 
        else 
        {
            input_success = true;
        }
    } 
    while (!input_success);
    
    int** matrix = new int*[n]; // создание двумерного динамического массива
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 101 - 50; // заполнение матрицы случайными числами от -50 до 50
        }
    }
    
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(4) << matrix[i][j] ;
        }
        std::cout << std::endl;
    }
    
    for (int i = 1; i < n; i += 2) // сортировка строк с четными номерами
    {
        sort(matrix[i], matrix[i] + m, std::greater<int>()); // сортировка по убыванию
    }
    
    std::cout << "Преобразованная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    
    // освобождение памяти
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
