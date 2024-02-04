/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Заменить все элементы с нечетнымизначениями с номерами от n1 до n2 на минимальный по модулю элемент этого
массива. n1, n2 вводятся с клавиатуры. Сделать проверку на корректность ввода
n, n1 и n2.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // Для использования функции abs()

int main()
{
    int n;
    
    do
    {
        std::cout << "Введите значение n (не более 20): ";
        
        if (!(std::cin >> n))
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (n <= 0 || n > 20)
        {
            std::cout << "Некорректное значение n! Пожалуйста, введите число от 1 до 20." << std::endl;
        }
    }
    while (n <= 0 || n > 20);


    bool invalidInput = false; //Сбрасываем флаг перед каждой итерацией
    std::vector<int> arr(n);
    std::cout << "Введите " << n << " элементы массива:\n";
    for (int i = 0; i < n; ++i)
    {
        do
        {
            std::cout << "M" << i+1 << ":";
            if (!(std::cin >> arr[i]))
            {
                std::cout << "Некорректный ввод. Попробуйте снова.\n";
                // Очистка ошибочных символов из ввода
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                invalidInput = true;
                i--;
                break;
            }
            invalidInput = false;
            break;
        }
        while (!invalidInput);
    }
    
    std::cout << "Массив до замены:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int n1, n2;
    
    do
    {
        std::cout << "Введите значение n1: ";
        if (!(std::cin >> n1))
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите только число." << std::endl;
            // Очистка флага ошибки ввода
            std::cin.clear();
            // Очистка буфера ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        std::cout << "Введите значение n2: ";
        if (!(std::cin >> n2))
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите только число." << std::endl;
            // Очистка флага ошибки ввода
            std::cin.clear();
            // Очистка буфера ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        // Проверка корректности ввода n1 и n2
        if (n1 <= 0 || n1 > n || n2 <= 0 || n2 > n || n1 > n2)
        {
            std::cout << "Некорректные значения n1 и n2! Пожалуйста, введите заново." << std::endl;
            continue;
        }
        
        break;
    } while (true);
    
    int min = arr[0]; // Предполагаем, что первый элемент - минимальный по модулю
    for (int i = 0; i < n; ++i)
    {
        if (abs(arr[i]) < abs(min))
        {
            min = arr[i];
        }
    }
    
    for (int i = n1 - 1; i < n2; ++i)
    {
        
        if (arr[i] % 2 != 0)
        {
            arr[i] = min;
        }
    }
    
    std::cout << "Массив после замены:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}
