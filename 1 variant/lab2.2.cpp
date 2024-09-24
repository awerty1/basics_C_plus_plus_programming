/*
Задание 2. Подсчитать общее количество «счастливых» автобусных 
билетов. Автобусный билет имеет шестизначный номер и является счастливым, 
если сумма первых трех цифр равна сумме последних цифр.
*/

#include <iostream>

int countLuckyTickets() 
{
    int count = 0;

    for (int digit1 = 0; digit1 <= 9; digit1++) 
    {
        for (int digit2 = 0; digit2 <= 9; digit2++) 
        {
            for (int digit3 = 0; digit3 <= 9; digit3++) 
            {
                int sumFirstHalf = digit1 + digit2 + digit3;
                int sumSecondHalf = sumFirstHalf; // Сумма цифр первой половины будет равна сумме цифр второй половины

                if (sumFirstHalf > 9) 
                {
                    // Если сумма цифр первой половины больше 9,
                    // то уменьшаем сумму второй половины на разницу
                    sumSecondHalf -= (sumFirstHalf - 9);
                    sumFirstHalf = 9; // Максимальное значение суммы для первой половины
                }

                count += (sumSecondHalf >= 0 && sumSecondHalf <= 9) ? 1 : 0;
            }
        }
    }

    return count * count; // Умножаем на два, так как сумма первой половины может быть равна сумме второй половины или наоборот
}

int main() 
{
    int count = countLuckyTickets();

    std::cout << "Total number of lucky tickets: " << count << std::endl;

    return 0;
}
