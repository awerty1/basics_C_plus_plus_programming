/*
Задание 3. C клавиатуры вводится число n. Найти число из диапазона от 1 
до n с максимальной суммой делителей (в делители не включаются 1 и само 
число). Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <vector>
#include <limits>

int main()
{
    int n;
    bool validInput = false;

    do
    {
        std::cout << "Введите число n: ";
        std::cin >> n;

        if (std::cin.fail() || n <= 1)
        {
            std::cout << "Ошибка! Введите корректное число (больше 1)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            validInput = true;
        }
    }
    while (!validInput);

    int maxSum = 0;
    int numberWithMaxSum = 0;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            numberWithMaxSum = i;
        }
    }

    std::cout << "Число из диапазона от 1 до " << n << " с максимальной суммой делителей: " << numberWithMaxSum << std::endl;

    return 0;
}