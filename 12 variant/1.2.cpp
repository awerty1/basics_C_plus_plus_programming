/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти разность
второй и третьей его цифр.
*/

#include <iostream>

int main()
{
    int number;
    bool is_valid_number = false;

    do 
	{
        std::cout << "Введите четырехзначное число: ";
        std::cin >> number;

        if (number >= 1000 && number <= 9999) 
		{
            is_valid_number = true;
        } 
		else 
		{
            std::cout << "Ошибка! Введите четырехзначное число." << std::endl;
        }
    } 
	while (!is_valid_number);

    int thousands = number / 1000;    // Получаем значение тысяч
    int hundreds = (number / 100) % 10;     // Получаем значение сотен
    int tens = (number / 10) % 10;   // Получаем значение десятков
    int units = number % 10;           // Получаем значение единиц

    int difference = tens - hundreds;

    std::cout << "Разность второй и третьей цифры числа: " << difference << std::endl;

    return 0;
}