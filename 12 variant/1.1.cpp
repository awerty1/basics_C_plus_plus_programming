/*
Задание 1. Написать программу вычисления стоимости покупки нескольких 
тетрадей. Цена и количество тетрадей вводится с клавиатуры.
*/

#include <iostream>

int main()
{
    double notebookPrice;
    int notebookQuantity;

    do
    {
        std::cout << "Введите цену одной тетради (больше 0): ";
        std::cin >> notebookPrice;

        std::cout << "Введите количество тетрадей (больше 0): ";
        std::cin >> notebookQuantity;

        if (notebookPrice <= 0 || notebookQuantity <= 0)
        {
            std::cout << "Ошибка! Введите положительные значения цены и количества тетрадей." << std::endl;
        }
    } 
	while (notebookPrice <= 0 || notebookQuantity <= 0);

    double totalCost = notebookPrice * notebookQuantity;

    std::cout << "Общая стоимость покупки: " << totalCost << " руб." << std::endl;

    return 0;
}