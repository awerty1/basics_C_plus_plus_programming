/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Поменять местами максимальный из
отрицательных элементов и минимальный из положительных элементов (если
таких элементов несколько, взять первые из них). Вывести преобразованный
таким образом массив.
*/

#include <iostream>
#include <vector>
#include <limits>

int main()
{
    int n;
    
    // Ввод размера массива с защитой от некорректного ввода
    do
    {
        std::cout << "Введите размер массива (n не больше 20): ";
        std::cin >> n;
        
        if (std::cin.fail() || n <= 0 || n > 20)
        {
            std::cout << "Пожалуйста, введите целое число в диапазоне от 1 до 20.\n";
            std::cin.clear(); // Сброс флага ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
        }
    } 
    while (n <= 0 || n > 20);

    std::vector<int> arr(n);

    // Ввод элементов массива
    std::cout << "Введите " << n << " целых чисел для массива: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите ARR[" << i+1 << "]: ";
        std::cin >> arr[i];

        if (std::cin.fail()) 
        {
            std::cout << "Пожалуйста, введите целое число.\n";
            std::cin.clear(); // Сброс флага ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
            i--; // Повторяем ввод для текущего элемента
        }
    }

    // Поиск максимального отрицательного элемента и минимального положительного элемента
    // int maxNegative = -1000; // Максимальное отрицательное число
    // int minPositive = 1000; // Минимальное положительное число
    // int maxNegIndex = -1;
    // int minPosIndex = -1;
    
    
    int maxNegative = -1; // Максимальное отрицательное число
    int minPositive = 1000; // Минимальное положительное число
    int maxNegIndex = 0;
    int minPosIndex = 0;
    
    
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < 0 && arr[i] < maxNegative)
        {
            maxNegative = arr[i];
            maxNegIndex = i;
        }
        else if (arr[i] > 0 && arr[i] < minPositive)
        {
            minPositive = arr[i];
            minPosIndex = i;
        }
    }

    // Поменять местами найденные элементы
    if (maxNegIndex != -1 && minPosIndex != -1)
    {
        int temp = arr[maxNegIndex];
        arr[maxNegIndex] = arr[minPosIndex];
        arr[minPosIndex] = temp;
    }

    // Вывод преобразованного массива
    std::cout << "Преобразованный массив:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
