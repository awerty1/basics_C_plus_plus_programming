/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Поменять местами максимальный и 
минимальный элементы (если таких элементов несколько, взять первые из них).
Вывести преобразованный таким образом массив.
*/

#include <iostream>

int main() 
{
    const int MAX_SIZE = 20;
    int n;

    do 
	{
        std::cout << "Введите количество элементов массива (не более 20): ";
        std::cin >> n;

        if (n < 1 || n > MAX_SIZE) 
		{
            std::cout << "Пожалуйста, введите корректное значение для n (от 1 до 20)." << std::endl;
        }
    } 
	while (n < 1 || n > MAX_SIZE);

    int array[MAX_SIZE];

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) 
	{
        std::cin >> array[i];
    }

    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < n; ++i) 
	{
        if (array[i] < array[min_index]) 
		{
            min_index = i;
        }
        if (array[i] > array[max_index]) 
		{
            max_index = i;
        }
    }

    // Обмен местами максимального и минимального элементов
    int temp = array[min_index];
    array[min_index] = array[max_index];
    array[max_index] = temp;

    std::cout << "Преобразованный массив после обмена максимального и минимального элементов: ";
    for (int i = 0; i < n; ++i) 
	{
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}