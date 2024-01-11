/*
Задание 3. Вводятся три произвольных числа x, y, z. Найти среднее среди 
них.
*/

#include <iostream>
#include <limits>

int main() 
{
    int x, y, z;
    float average;
    
    do
    {
        // Ввод чисел x, y и z
        std::cout << "Введите три числа: ";
    
        // Проверка на корректный ввод
        if (!(std::cin >> x >> y >> z)) 
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите только числа." << std::endl;
            // Очистка флага ошибки ввода
            std::cin.clear();
            // Очистка буфера ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        }
        else
        {
            // Находим среднее значение
            average = static_cast<float>(x + y + z) / 3;
        
            // Выводим среднее значение на экран
            std::cout << "Среднее значение: " << average << std::endl;
            break; // Выход из цикла после корректного ввода
        }
    }
    while(true);
    
    return 0;
}
