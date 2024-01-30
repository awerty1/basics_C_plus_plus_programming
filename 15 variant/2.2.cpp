/*
Задание 2. Вывести на экран все четырехзначные натуральные числа, в 
записи которых нет двух одинаковых цифр.
*/

#include <iostream>
#include <set>

int main()
{
    for (int num = 1000; num < 10000; num++)
    {
        std::set<int> digits;

        int temp = num;
        while (temp > 0)
        {
            int digit = temp % 10;
            digits.insert(digit);
            temp /= 10;
        }

        if (digits.size() == 4)
        {
            std::cout << num << std::endl;
        }
    }

    return 0;
}