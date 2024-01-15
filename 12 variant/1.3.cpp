/*
Задание 3. Даны два числа A и B. Меньшее из этих двух чисел заменить их 
разностью, а большее – их удвоенной суммой. Вывести полученные значения.
Отдельно рассмотреть случай ввода одинаковых значений.
*/

#include <iostream>
#include <limits>

// Функция для проверки ввода числа
int getValidNumber(const std::string& prompt)
{
    int number;
    bool isValidInput = false;

    do 
    {
        std::cout << prompt;
        std::cin >> number;

        // Проверяем, является ли ввод числом
        if (std::cin.fail()) 
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            isValidInput = true;
        }
    } 
    while (!isValidInput);

    return number;
}

int main()
{
    int A, B;
    int difference = 0;
    int sum = 0;

    std::cout << "=== Замена чисел ===" << std::endl;

    A = getValidNumber("Введите число А: ");
    B = getValidNumber("Введите число В: ");

    if (A == B) 
    {
        difference = A - B;
        sum = (A + B) * 2;

        std::cout << "Числа одинаковы. Значения заменены: " << difference << " и " << sum << std::endl;
    } 
    else if (A < B) 
    {
        difference = B - A;
        sum = (A + B) * 2;
        
        std::cout << "Меньше число " << A << " заменено на разность: " << difference << std::endl;
        std::cout << "Больше число " << B << " заменено на удвоенную сумму: " << sum << std::endl;
    } 
    else 
    {
        difference = A - B;
        sum = (A + B) * 2;
        
        std::cout << "Меньше число " << B << " заменено на разность: " << difference << std::endl;
        std::cout << "Больше число " << A << " заменено на удвоенную сумму: " << sum << std::endl;
    }

    return 0;
}