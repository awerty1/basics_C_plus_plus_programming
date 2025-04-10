/*
Задание 3. Написать программу вывода всех двухзначных чисел, у которых 
первая цифра кратна 3, в вторая цифра – кратна 4 (например, числа 38 и 94
удовлетворяют этому условию).
*/

#include <iostream>

int main() 
{
    std::cout << "Двузначные числа, у которых первая цифра кратна 3, а вторая цифра – кратна 4:" << std::endl;

    for (int i = 10; i <= 99; i++) 
    {
        int firstDigit = i / 10;   // Получаем первую цифру
        int secondDigit = i % 10;  // Получаем вторую цифру

        if (firstDigit % 3 == 0 && secondDigit != 0 && secondDigit % 4 == 0) 
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}