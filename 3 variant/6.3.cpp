/*
Задание 3. Вводятся две пары целых чисел h1 и m1 и h2 и m2. Каждая пара 
обозначает время суток: h (hour) – часы, m (minute) – минуты. Найти и вывести 
разность между более поздним и более ранним временем в том же формате: часы 
и минуты. Допустим, 9 30 и 12 0 – разность 2 30 (2 часа и 30 минут). Сделать 
функцию для проверки корректности ввода значений часов (0..23) и минут (0..59) 
– она может иметь тип bool и возвращать true или false.
*/

#include <iostream>

bool isValidTime(int h, int m) 
{
    // Проверка корректности значения часов (0..23) и минут (0..59)
    return (h >= 0 && h <= 23) && (m >= 0 && m <= 59);
}

void calculateTimeDifference(int h1, int m1, int h2, int m2) 
{
    if (!isValidTime(h1, m1) || !isValidTime(h2, m2)) 
    {
        std::cout << "Некорректные значения времени." << std::endl;
        return;
    }

    int totalMinutes1 = h1 * 60 + m1; // Преобразуем первое время в минуты
    int totalMinutes2 = h2 * 60 + m2; // Преобразуем второе время в минуты

    int diffMinutes = std::abs(totalMinutes2 - totalMinutes1); // Вычисляем разницу в минутах

    int diffHours = diffMinutes / 60; // Вычисляем часы разности
    int diffMins = diffMinutes % 60; // Вычисляем оставшиеся минуты разности

    std::cout << "Разность между временами: " << diffHours << " часов и " << diffMins << " минут." << std::endl;
}

int main() 
{
    int h1, m1, h2, m2;

    std::cout << "Введите первое время (часы минуты): ";
    std::cin >> h1 >> m1;

    std::cout << "Введите второе время (часы минуты): ";
    std::cin >> h2 >> m2;

    calculateTimeDifference(h1, m1, h2, m2);

    return 0;
}