/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Поменять местами первый элемент со 
вторым, третий с четвёртым и т.д. Если в массиве нечётное количество 
элементов, то последний элемент оставить на своём месте – его не с чем 
переставлять. Вывести преобразованный таким образом массив.
*/

#include <iostream>
#include <vector>
#include <limits> // Для очистки буфера ввода

int main() 
{
    int n;
    
    do 
    {
        std::cout << "Введите количество элементов массива (не больше 20): ";
        std::cin >> n;
        
        if (std::cin.fail()) 
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
            std::cin.clear(); // Сброс флага ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        }
        else if (n < 1 || n > 20) 
        {
            std::cout << "Неверный ввод. Пожалуйста, введите число от 1 до 20.\n";
        }
    } 
    while (n < 1 || n > 20);

    std::vector<int> arr(n);

    std::cout << "Введите " << n << " целых чисел:" << std::endl;
    for (int i = 0; i < n; ++i) 
    {
        while (!(std::cin >> arr[i])) 
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите " << n << " целое число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    for (int i = 0; i < n - 1; i += 2) 
    {
        std::swap(arr[i], arr[i + 1]);
    }

    std::cout << "Преобразованный массив:" << std::endl;
    for (int num : arr) 
    {
        std::cout << num << " ";
    }

    return 0;
}
