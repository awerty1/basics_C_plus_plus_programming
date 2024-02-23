/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Поменять местами максимальный из 
положительных элементов и минимальный из отрицательных элементов (если 
таких элементов несколько, взять первые из них). Вывести преобразованный 
таким образом массив.
*/

#include <iostream>
#include <vector>
#include <limits> // Для очистки ввода в случае ввода символов

int main() 
{
    int n;
    
    do 
    {
        std::cout << "Введите размер массива (не больше 20): ";
        std::cin >> n;
        
        if (std::cin.fail()) 
        {
            std::cin.clear(); // Сбрасываем флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
            std::cout << "Ошибка! Пожалуйста, введите целое число.\n";
            n = -1; // Присваиваем -1, чтобы цикл продолжался
        }
    } 
    while (n < 0 || n > 20);

    std::vector<int> arr(n);

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
        
        if (std::cin.fail()) 
        {
            std::cin.clear(); // Сбрасываем флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
            std::cout << "Ошибка! Пожалуйста, введите целое число.\n";
        }
    }

    int maxPositive = -1; // Инициализируем индекс максимального положительного числа как -1
    int minNegative = -1; // Инициализируем индекс минимального отрицательного числа как -1

    // Находим максимальный положительный и минимальный отрицательный элементы
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] > 0 && (maxPositive == -1 || arr[i] > arr[maxPositive])) 
        {
            maxPositive = i;
        }
        if (arr[i] < 0 && (minNegative == -1 || arr[i] < arr[minNegative])) 
        {
            minNegative = i;
        }
    }

    if (maxPositive != -1 && minNegative != -1) 
    {
        // Меняем местами максимальный положительный и минимальный отрицательный элементы
        int temp = arr[maxPositive];
        arr[maxPositive] = arr[minNegative];
        arr[minNegative] = temp;
    }

    // Выводим преобразованный массив
    std::cout << "Преобразованный массив:\n";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

