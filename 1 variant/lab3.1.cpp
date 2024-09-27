/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
среднее арифметическое всех положительных элементов. Сделать проверку на 
корректность ввода n.
*/

#include <iostream>
#include <vector>
#include <random>

int main() 
{
    int n;
    
    do 
    {
        std::cout << "Введите количество элементов массива (n <= 20): ";
        std::cin >> n;
        
        if (n <= 0 || n > 20) 
        {
            std::cout << "Некорректный ввод n. Пожалуйста, введите число от 1 до 20." << std::endl;
        }
    } 
    while (n <= 0 || n > 20);
    
    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-10, 10);
    
    std::vector<int> arrayA(n);
    int positiveSum = 0;
    int positiveCount = 0;
    
    // Заполнение массива случайными числами и подсчет суммы положительных элементов
    std::cout << "Исходный массив:" << std::endl;
    for (int i = 0; i < n; ++i) 
    {
        arrayA[i] = dist(gen);
    
        std::cout << arrayA[i] << " ";
        
        if (arrayA[i] > 0) 
        {
            positiveSum += arrayA[i];
            positiveCount++;
        }
    }
    
    // Проверка, есть ли положительные элементы
    if (positiveCount > 0) 
    {
        double average = static_cast<double>(positiveSum) / positiveCount;
        std::cout << "\nСреднее арифметическое положительных элементов: " << average << std::endl;
    } 
    else 
    {
        std::cout << "\nВ массиве нет положительных элементов." << std::endl;
		
		// Предложение пользователю возможности повторного ввода числа n или завершения программы
        char choice;
        std::cout << "Хотите попробовать еще раз? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') 
        {
            main(); // Рекурсивный вызов main для повторного запуска программы
        } 
        else 
        {
            return 0; // Завершение программы
        }
    }
    
    return 0;
}

