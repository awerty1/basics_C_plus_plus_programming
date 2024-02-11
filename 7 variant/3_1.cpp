/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти
среднее арифметическое всех элементов с четными значениями. Сделать
проверку на корректность ввода n.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() 
{
    int n;
    bool validInput = false;

    do 
    {
        std::cout << "Введите количество элементов массива (n не больше 20): ";
        
        if (std::cin >> n) 
        {
            validInput = true;
        } 
        else 
        {
            std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (n <= 0 || n > 20) 
        {
            std::cout << "Некорректный ввод n. Пожалуйста, введите число от 1 до 20." << std::endl;
            validInput = false;
        }
        
    } 
    while (!validInput || n <= 0 || n > 20);

    int A[n];
    srand(time(nullptr)); // Инициализация генератора случайных чисел

    // Заполнение массива случайными числами от -10 до 10 и вывод элементов
    std::cout << "Элементы массива A: ";
    for (int i = 0; i < n; ++i) 
    {
        A[i] = rand() % 21 - 10;
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    int sum = 0;
    int count = 0;

    // Вычисление среднего арифметического всех элементов с четными значениями
    for (int i = 0; i < n; ++i) 
    {
        if (A[i] % 2 == 0) 
        {
            sum += A[i];
            count++;
        }
    }

    if (count == 0) 
    {
        std::cout << "В массиве нет четных чисел." << std::endl;
    } 
    else 
    {
        double average = static_cast<double>(sum) / count;
        std::cout << "Среднее арифметическое всех четных элементов: " << average << std::endl;
    }

    return 0;
}
