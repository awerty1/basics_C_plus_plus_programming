/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50.  
Отсортировать все строки с нечетными номерами по возрастанию 
(нумерация  строк ведется со стороны пользователя, т.е. с единицы). 
Вывести  преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функция для генерации случайного числа в заданном диапазоне
int getrandomnumber(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

int main() 
{
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
      
    int n, m;
    do 
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;

        if (n <= 0 || m <= 0) 
        {
            std::cout << "Ошибка: количество строк и столбцов должно быть положительным числом." << std::endl;
        }
    } 
    while (n <= 0 || m <= 0);
    
    int** matrix = new int*[n]; // Создание указателя на указатель
    
    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m]; // Выделение памяти для каждой строки
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = getrandomnumber(-50, 50);
        }
    }
    
    //Вывод матрицы
    std::cout << "Преобразованная матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    
    // Сортировка строк с нечетными номерами
    for (int i = 0; i < n; i += 2) 
    {
        for (int j = 0; j < m - 1; j++) 
        {
            for (int k = 0; k < m - j - 1; k++) 
            {
                if (matrix[i][k] > matrix[i][k + 1]) 
                {
                    // Обмен значений элементов
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
    
    // Вывод преобразованной матрицы
    std::cout << "\nПреобразованная матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
        
        delete[] matrix[i]; // Освобождение памяти для каждой строки
    }
    
    delete[] matrix; // Освобождение памяти для указателя на указатель
    
    return 0;
}