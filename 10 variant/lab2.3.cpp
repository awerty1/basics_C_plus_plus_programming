/*
Задание 3. Вывести на экран все трехзначные натуральные числа, в записи 
которых нет двух одинаковых цифр.
*/

#include <iostream>
#include <set>

bool hasDuplicateDigits(int number)
{
    std::set<int> digits;
    while (number > 0)
    {
        int digit = number % 10;
        if (digits.count(digit) > 0)
        {
            return true;
        }
        digits.insert(digit);
        number /= 10;
    }
    return false;
}

int main()
{
    for (int number = 100; number < 1000; ++number)
    {
        if (!hasDuplicateDigits(number))
        {
            std::cout << number << std::endl;
        }
    }
    return 0;
}