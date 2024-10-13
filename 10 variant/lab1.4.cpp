/*
Задание 4. Написать программу вычисления стоимости покупки с учетом 
скидки. Скидка в 3% предоставляется в том случае, если сумма покупки больше 
500 руб., в 5% – если сумма больше 1000 руб. 
*/

#include <iostream>

double calculateDiscountedPrice(double price)
{
    double discount = 0.0;

    if (price > 1000)
    {
        discount = 0.05;
    }
    else if (price > 500)
    {
        discount = 0.03;
    }

    return price - (price * discount);
}

int main()
{
    double purchasePrice;

    std::cout << "Введите стоимость покупки: ";
    std::cin >> purchasePrice;

    // Проверяем, действительно ли введено положительное значение
    if (purchasePrice < 0)
    {
        std::cout << "Ошибка! Введите положительное значение стоимости покупки." << std::endl;
        return 0;
    }

    double discountedPrice = calculateDiscountedPrice(purchasePrice);

    std::cout << "Стоимость покупки с учетом скидки: " << discountedPrice << " руб." << std::endl;

    return 0;
}