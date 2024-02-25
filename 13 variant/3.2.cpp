/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Заменить все элементы с четными 
значениями с номерами от n1 до n2 на среднее арифметическое этого массива. 
Сделать проверку на корректность ввода n, n1 и n2.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() 
{
    int n, n1, n2;
    bool inputValid = false;

    do 
    {
        std::cout << "Введите размер массива (не больше 20): ";
        if (!(std::cin >> n) || n <= 0 || n > 20) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число от 1 до 20.\n";
        } 
        else 
        {
            inputValid = true;
        }
    } 
    while (!inputValid);

    std::vector<int> arr(n);

    srand(time(NULL));
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = rand() % 101; // Generate random number in the range [0, 100]
    }

    std::cout << "Исходный массив:\n";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    do 
    {
        std::cout << "Введите n1 (начало диапазона для замены): ";
        std::cin >> n1;
        
        n1--;
        
        if (std::cin.fail() || n1 < 0 || n1 >= n) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число от 0 до " << n - 1 << ".\n";
            //n1 = -1;
        }
    } 
    while (n1 < 0);

    do 
    {
        std::cout << "Введите n2 (конец диапазона для замены): ";
        std::cin >> n2;
        
        n2--;
        
        if (std::cin.fail() || n2 < 0 || n2 >= n || n2 < n1) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число от " << n1 << " до " << n - 1 << ".\n";
            //n2 = -1;
        }
    } 
    while (n2 < 0);

    // Calculate the average of even elements in the specified range
    int countEven = 0;
    int sumEven = 0;
    for (int i = n1; i <= n2; ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            countEven++;
            sumEven += arr[i];
        }
    }

    if (countEven > 0) 
    {
        int average = sumEven / countEven;

        // Replace even elements in the range with the calculated average
        for (int i = n1; i <= n2; ++i) 
        {
            if (arr[i] % 2 == 0) 
            {
                arr[i] = average;
            }
        }

        std::cout << "Массив после замены четных элементов в диапазоне [" << n1 << ", " << n2 << "] на среднее арифметическое: \n";
        for (int i = 0; i < n; ++i) 
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } 
    else 
    {
        std::cout << "В указанном диапазоне нет четных элементов для замены.\n";
    }

    return 0;
}