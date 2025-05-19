/*
Задание 3. Вводятся три целых числа d, m, y, которые вместе обозначают 
дату: d (day) – день, m (month) – месяц, y (year) – год. Если дата введена 
корректно, найти и вывести дату предыдущего дня в том же формате: день месяц 
год. С високосным годом можно так решить проблему – это год, который нацело 
делится на 4.
*/

#include <iostream>
#include <iomanip> // Для использования манипулятора std::setw

// Функция для проверки, является ли год високосным
bool isLeapYear(int year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true; // Високосный год
    }
    else
    {
        return false; // Не високосный год
    }
}

// Функция для определения количества дней в указанном месяце
int getDaysInMonth(int month, int year) 
{
    int daysInMonth;

    switch (month) 
    {
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }

    return daysInMonth;
}

// Функция для нахождения предыдущего дня
void findPreviousDay(int day, int month, int year, int& prevDay, int& prevMonth, int& prevYear) 
{
    prevDay = day - 1;
    prevMonth = month;
    prevYear = year;

    if (prevDay == 0) 
    {
        prevMonth--;

        if (prevMonth == 0) 
        {
            prevMonth = 12;
            prevYear--;
        }

        prevDay = getDaysInMonth(prevMonth, prevYear);
    }
}

// Проверка на корректность даты
bool isValidDate(int day, int month, int year) 
{
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > getDaysInMonth(month, year)) 
    {
        return false; // Некорректная дата
    }
    else 
    {
        return true; // Корректная дата
    }
}

int main() 
{
    int day, month, year;
    std::cout << "Введите день, месяц и год: ";
    std::cin >> day >> month >> year;
    
    if (!isValidDate(day, month, year)) 
    {
        std::cout << "Некорректная дата!" << std::endl;
        return 1; // Возврат из программы с ошибкой
    }

    int prevDay, prevMonth, prevYear;
    findPreviousDay(day, month, year, prevDay, prevMonth, prevYear);

    // Используем манипулятор setw для добавления ведущего нуля перед однозначными значениями
    std::cout << "Предыдущий день: " << std::setw(2) << std::setfill('0') << prevDay << "." 
              << std::setw(2) << std::setfill('0') << prevMonth << "." << prevYear << std::endl;

    return 0;
}