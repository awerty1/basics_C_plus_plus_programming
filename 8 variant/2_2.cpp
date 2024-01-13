/*
Задание 2. C клавиатуры вводится число n. Найти число из диапазона от 1
до n с максимальной суммой делителей (в делители не включаются 1 и само
число). Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <limits>

int getSumOfDivisors(int number)
{
    int sum = 0;
    for (int i = 2; i <= number / 2; ++i)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int n;
    
    do
    {
        std::cout << "Введите число n: ";
        
        //Проверка корректности ввода n
        if (!(std::cin >> n))
        {
            std::cout << "Ошибка ввода!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Проверка на корректность ввода
        else if (n <= 0)
        {
            std::cout << "Число должно быть положительным.\n";
        }
    }
    while (n <= 0);
    
    
    int maxNumber = 1;
    int maxSum = 0;
    
    for (int i = 2; i <= n; ++i)
    {
        int sum = getSumOfDivisors(i);
        if (sum > maxSum)
        {
            maxSum = sum;
            maxNumber = i;
        }
    }
    
    std::cout << "Число из диапазона от 1 до " << n << " с максимальной суммой делителей: " << maxNumber << "\n";
    
    return 0;
}
