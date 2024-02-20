/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Заменить все положительные элементы 
с номерами от n1 до n2 на минимальный по модулю элемент этого массива. n1, n2 
вводятся с клавиатуры. Сделать проверку на корректность ввода n, n1 и n2.
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

int main() 
{
    int n;
    int n1, n2;
    int A[20];
    
    std::cout << "Введите длину массива (не больше 20): ";
    std::cin >> n;
    
    if (n < 1 || n > 20) 
    {
        std::cout << "Недопустимая длина массива!\n";
        return 1;
    }
    
    // Заполнение массива случайными числами от -100 до 100
    srand(time(NULL));
    for (int i = 0; i < n; ++i) 
    {
        A[i] = rand() % 201 - 100;
    }
    
    std::cout << "Исходный массив A: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Введите n1 и n2 (n1 <= n2): ";
    std::cin >> n1 >> n2;
    n1--;
    n2--;
    
    if (n1 < 0 || n1 >= n || n2 < 0 || n2 >= n || n1 > n2) 
    {
        std::cout << "Некорректные значения n1 и n2!\n";
        return 1;
    }
    
    // Находим минимальный по модулю элемент массива
    int minAbs = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) 
    {
        if (abs(A[i]) < abs(minAbs)) 
        {
            minAbs = A[i];
        }
    }
    
    // Заменяем положительные элементы в заданном диапазоне на минимальный по модулю элемент
    for (int i = n1; i <= n2; ++i) 
    {
        if (A[i] > 0) 
        {
            A[i] = minAbs;
        }
    }
    
    std::cout << "Измененный массив A: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}