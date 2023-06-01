/*
Задание 2. Написать программу вывода всех четырехзначных чисел, у 
которых вторая цифра кратна 2, а четвертая цифра – кратна 4 (например, числа 
1238 и 2604 удовлетворяют этому условию).
*/

#include <iostream>

int main() 
{
    int SIZE = 10000;
    int last_elem = 9898;
    
    std::cout << "Вывод всех четырехзначных чисел:" << std::endl;
    for (int i = 1000; i < SIZE; ++i) 
	{
        int secondDigit = (i / 100) % 10;
        int fourthDigit = i % 10;
        
        if (secondDigit != 0 && fourthDigit != 0 && 
             secondDigit % 2 == 0 && fourthDigit % 4 == 0 && i < last_elem) 
		{
            std::cout << i << ",";
        }
        else if (secondDigit != 0 && fourthDigit != 0 && 
             secondDigit % 2 == 0 && fourthDigit % 4 == 0 && (i == last_elem))
        {
            std::cout << i << ".";
        }
    }

    return 0;
}