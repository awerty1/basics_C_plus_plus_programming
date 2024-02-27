/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Поменять местами максимальный из 
положительных элементов и минимальный из отрицательных элементов (если 
таких элементов несколько, взять первые из них). Вывести преобразованный 
таким образом массив.
*/

#include <iostream>
#include <limits>

int main() 
{
    const int maxSize = 20;
    int n;
    int arr[maxSize];

    std::cout << "Введите количество элементов массива (не более 20): ";
    std::cin >> n;

    if (n <= 0 || n > maxSize) 
	{
        std::cout << "Ошибка: введите корректное число элементов до 20." << std::endl;
        return 1;
    }

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) 
	{
        std::cin >> arr[i];
    }

    int minNegativeIndex = -1;
    int maxPositiveIndex = -1;

    for (int i = 0; i < n; ++i) 
	{
        if (arr[i] < 0 && (minNegativeIndex == -1 || arr[i] < arr[minNegativeIndex])) 
		{
            minNegativeIndex = i;
        }

        if (arr[i] > 0 && (maxPositiveIndex == -1 || arr[i] > arr[maxPositiveIndex])) 
		{
            maxPositiveIndex = i;
        }
    }

    if (minNegativeIndex != -1 && maxPositiveIndex != -1) 
	{
        int temp = arr[minNegativeIndex];
        arr[minNegativeIndex] = arr[maxPositiveIndex];
        arr[maxPositiveIndex] = temp;
    }

    std::cout << "Преобразованный массив:" << std::endl;
    for (int i = 0; i < n; ++i) 
	{
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}