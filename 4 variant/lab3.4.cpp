/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Поменять местами первый элемент со
вторым, третий с четвёртым и т.д. Если в массиве нечётное количество
элементов, то последний элемент оставить на своём месте – его не с чем
переставлять. Вывести преобразованный таким образом массив.
*/

#include <iostream>
#include <array>
#include <limits>

int main()
{
    int n;
    
    do
    {
        std::cout << "Введите количество элементов массива (n): ";
        
        // Проверка корректности ввода n
        if (!(std::cin >> n))
        {
            std::cout << "Ошибка ввода!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (n <= 0 || n > 20)
        {
            std::cout << "Некорректный ввод n!" << std::endl;
        }
    }
    while (n <= 0 || n > 20);
    
    int array[20]; // Массив размером 20
    
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "M" << i+1 << ":";
        if (!(std::cin >> array[i]))
        {
            std::cout << "Ошибка ввода символов!" << std::endl;
            
            // Очищаем входной буфер
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // Уменьшаем счетчик, чтобы можно было повторно ввести значение
            i--;
        }
    }
    
    // Вывод массива
    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    // Перестановка элементов в массиве
    for (int i = 0; i < n - 1; i += 2)
    {
        std::swap(array[i], array[i + 1]);
    }
    
    // Вывод массива
    std::cout << "Преобразованный массив: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
