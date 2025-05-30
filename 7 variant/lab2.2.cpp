/*
Задание 2. Написать программу вывода всех трехзначных чисел, у которых 
вторая цифра кратна 3, а третья цифра – кратна 4 (например, числа 268 и 194 
удовлетворяют этому условию)
*/

#include <iostream>

int main()
{
    std::cout << "Трехзначные числа, у которых вторая цифра кратна 3, а третья цифра кратна 4:" << std::endl;
    
    for (int i = 100; i <= 999; ++i)
    {
        int secondDigit = (i / 10) % 10;
        int thirdDigit = i % 10;
        
        if (secondDigit % 3 == 0 && secondDigit != 0 && thirdDigit != 0 && thirdDigit % 4 == 0)
        {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
