/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Найти число, повторяющееся 
максимальное количество раз. Если таких чисел несколько, то вывести одно из 
них. Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <unordered_map>

int main() 
{
    int n;
    std::cout << "Введите размер массива (не более 20): ";
    std::cin >> n;

    // Проверка корректности ввода n
    if (n <= 0 || n > 20) 
    {
        std::cout << "Некорректный ввод размера массива." << std::endl;
        return 1;
    }

    int* arr = new int[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }
    
    // Создание словаря для подсчета частоты встречаемости чисел
    std::unordered_map<int, int> freqMap;
    for (int i = 0; i < n; ++i) 
    {
        freqMap[arr[i]]++;
    }

    int maxCount = 0;
    int mostFrequentNumber = 0;

    // Поиск числа с максимальной частотой встречаемости
    for (const auto& entry : freqMap) 
    {
        if (entry.second > maxCount) 
        {
            maxCount = entry.second;
            mostFrequentNumber = entry.first;
        }
    }
    
    if (maxCount > 1) 
    {
        std::cout << "Число, повторяющееся максимальное количество раз(число:число повторений): " << mostFrequentNumber 
                << ":" << maxCount << std::endl;
    } 
    else 
    {
        std::cout << "В массиве нет повторяющихся чисел." << std::endl;
    }

    delete[] arr;

    return 0;
}
