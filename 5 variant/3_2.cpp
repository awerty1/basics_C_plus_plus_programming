/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Определить максимальное количество
следующих подряд положительных элементов. В массиве могут быть все
элементы отрицательные, и такой вариант должен отрабатываться корректно.
Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <sstream>

int getValidInput(const std::string &message)
{
    int input;
    bool validInput = false;
    std::string inputStr;
    
    do
    {
        std::cout << message;
        std::cin >> inputStr;
        
        bool validNumber = true;
        for (char c : inputStr)
        {
            if (!std::isdigit(c))
            {
                validNumber = false;
                break;
            }
        }
        
        if (validNumber)
        {
            std::stringstream ss(inputStr);
            ss >> input;
            if (input > 0 && input <= 20)
            {
                validInput = true;
            }
            else
            {
                std::cerr << "Ошибка: значение должно быть в диапазоне (1, 20). Попробуйте снова." << std::endl;
            }
        }
        else
        {
            std::cerr << "Ошибка: некорректный ввод. Попробуйте снова." << std::endl;
        }
        
        if (!validInput)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
    } 
    while (!validInput);
    
    return input;
}

int main()
{
    int n;
    
    do
    {
        n = getValidInput("Введите значение n (не больше 20): ");
        
        if (n <= 0 || n > 20)
        {
            std::cerr << "Ошибка: некорректный ввод n. Повторите попытку." << std::endl;
        }
    }
    while (n <= 0 || n > 20);
    
    std::vector<int> arr(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);
    
    for (int i = 0; i < n; ++i)
    {
        arr[i] = dis(gen);
    }
    
    std::cout << "Сформированный массив: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    int max_length = 0;
    int current_length = 0;
    
    for (int num : arr)
    {
        if (num > 0)
        {
            current_length++;
        }
        else
        {
            max_length = std::max(max_length, current_length);
            current_length = 0;
        }
    }
    
    max_length = std::max(max_length, current_length);
    
    std::cout << "Максимальное количество последовательных положительных элементов: " << max_length << std::endl;
    
    return 0;
}
