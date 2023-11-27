/*
Задание 3. Вводятся три произвольных числа x, y, z. Найти среднее среди 
них.
*/

#include <iostream>

int main() 
{
    int x, y, z;
    float average;

    // Ввод чисел x, y и z
    std::cout << "Введите три числа: ";
    std::cin >> x >> y >> z;

    // Находим среднее значение
    average = (float)(x + y + z) / 3;

    // Выводим среднее значение на экран
    std::cout << "Среднее значение: " << average << std::endl;

    return 0;
}