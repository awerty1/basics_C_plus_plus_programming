/*
Задание 3. Написать программу вывода всех четырехзначных чисел, у 
которых первая цифра кратна 3, а четвертая цифра – кратна 5 (например, числа 
3260 и 9605 удовлетворяют этому условию).
*/

#include <iostream>

int main() 
{
    for (int number = 1000; number < 10000; ++number) 
    {
        int firstDigit = number / 1000;         // Получаем первую цифру
        int fourthDigit = number % 10;          // Получаем четвертую цифру

        if (firstDigit % 3 == 0 && fourthDigit != 0 && fourthDigit % 5 == 0) 
        {
            std::cout << number << "\n";
        }
    }

    return 0;
}