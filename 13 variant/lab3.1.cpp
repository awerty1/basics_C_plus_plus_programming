/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -50 до 50 (число n вводится с клавиатуры, его значение не больше 20). Найти 
количество элементов с четными значениями и определить наибольший среди 
них. Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <vector>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function
#include <limits>
#include <climits>

int main() 
{
    int n;
    
    do 
    {
        std::cout << "Введите размер массива (не больше 20): ";
        std::cin >> n;
        
        if (std::cin.fail()) 
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            std::cout << "Ошибка! Пожалуйста, введите целое число.\n";
            n = -1; // Set n to -1 to continue the loop
        }
    } 
    while (n < 0 || n > 20);

    std::vector<int> arr(n);

    // Generate random numbers and initialize the array
    srand(time(NULL));
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = rand() % 101 - 50; // Generate random number in the range [-50, 50]
    }

    int countEven = 0;
    int maxEven = INT_MIN; // Initialize maxEven to smallest integer value

    // Find count of even elements and the largest even number
    for (int i = 0; i < n; ++i) 
    {
        if ((arr[i] % 2 == 0) && (arr[i] != 0)) 
        {
            countEven++;
            if (arr[i] > maxEven) 
            {
                maxEven = arr[i];
            }
        }
    }

    // Output the array
    std::cout << "Массив A из " << n << " случайных целых чисел:\n";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Output the count of even elements and the largest even number
    std::cout << "Количество элементов с четными значениями: " << countEven << std::endl;
    if (countEven > 0) 
    {
        std::cout << "Наибольший среди них: " << maxEven << std::endl;
    }

    return 0;
}