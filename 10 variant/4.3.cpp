/*
Задание 3. Сформировать и вывести квадратную матрицу из n строк и 
столбцов. Элементы матрицы должны быть случайными числами в диапазоне от 
-50 до 50. Удалить строку, в которой находится наименьший элемент побочной 
диагонали. Вывести преобразованную таким образом матрицу.
Из-за того, что мы вводим размер 1 значением еще удаляется столбец
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

// Функция для вывода матрицы на экран
void printMatrix(int** matrix, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(time(0));

    int size;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> size;

    // Создаем двумерный динамический массив для хранения матрицы
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) 
    {
        matrix[i] = new int[size];
    }

    // Заполняем матрицу случайными числами
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            matrix[i][j] = generateRandomNumber(-50, 50);
        }
    }

    std::cout << "Исходная матрица:\n";
    printMatrix(matrix, size);

    // Находим строку с наименьшим элементом побочной диагонали
    int minRowIndex = 0;
    int minElement = matrix[0][size - 1];
    for (int i = 1; i < size; i++) 
    {
        if (matrix[i][size - 1 - i] < minElement) 
        {
            minElement = matrix[i][size - 1 - i];
            minRowIndex = i;
        }
    }

    // Удаляем строку с наименьшим элементом побочной диагонали
    delete[] matrix[minRowIndex];

    // Сдвигаем оставшиеся строки влево
    for (int i = minRowIndex; i < size - 1; i++) 
    {
        matrix[i] = matrix[i + 1];
    }

    // Уменьшаем размер матрицы на 1
    size--;

    std::cout << "Преобразованная матрица:\n";
    printMatrix(matrix, size);

    // Освобождаем память, выделенную для динамического массива
    for (int i = 0; i < size; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}