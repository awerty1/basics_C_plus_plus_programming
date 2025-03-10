/*
Задание 2. Написать программу вывода всех двухзначных чисел, у которых 
первая цифра кратна 2, в вторая цифра – кратна 3 (например, числа 46 и 29
удовлетворяют этому условию).
*/

#include <iostream>

int main() 
{
    std::cout << "Двузначные числа, у которых первая цифра кратна 2, а вторая цифра кратна 3:" << std::endl;

    for (int i = 10; i <= 99; i++) 
    {
        int firstDigit = i / 10;   // Получаем первую цифру
        int secondDigit = i % 10;  // Получаем вторую цифру

        // Проверяем условие
        if (firstDigit % 2 == 0 && secondDigit != 0 && secondDigit % 3 == 0) 
        {
            std::cout << i << std::endl;    // Выводим число, удовлетворяющее условию
        }
    }

    return 0;
}
