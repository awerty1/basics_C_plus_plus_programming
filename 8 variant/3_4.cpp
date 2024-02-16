/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Сделать реверс массива – последний 
элемент поменять местами с первым, предпоследний – со вторым и т.д. Вывести
преобразованный таким образом массив.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

bool readPositiveIntAndCheckInput(int& input, const char* message) 
{
    bool validInput = false;
    do 
    {
        std::cout << message;
        if (!(std::cin >> input) || input <= 0 || input > 20) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a positive integer not exceeding 20.\n";
        } 
        else 
        {
            validInput = true;
        }
    } 
    while (!validInput);
    
    return validInput;
}

int main() 
{
    int n;
    if (!readPositiveIntAndCheckInput(n, "Enter the length of the array (not more than 20):")) 
    {
        return EXIT_FAILURE;
    }

    std::vector<int> numbers(n);
    std::cout << "Enter " << n << " integers separated by spaces:\n";

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> numbers[i];
    }

    std::reverse(numbers.begin(), numbers.end());

    std::cout << "Reversed array: \n";
    for (const auto& num : numbers) 
    {
        std::cout << num << " ";
    }
    
    std::cout << "\n";

    return EXIT_SUCCESS;
}



