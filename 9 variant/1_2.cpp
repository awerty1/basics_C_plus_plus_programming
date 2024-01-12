/*
Задание 2. С клавиатуры вводится трехзначное число. Найти разность 
первой и последней его цифр.
*/

#include <iostream>

int main() 
{
    int number;
    
    // Ввод трехзначного числа
    std::cout << "Введите трехзначное число: ";
    std::cin >> number;
    
    // Находим первую цифру (сотни)
    int firstDigit = number / 100;
    
    // Находим последнюю цифру (единицы)
    int lastDigit = number % 10;
    
    // Вычисляем разность
    int difference = firstDigit - lastDigit;
    
    // Вывод результата
    std::cout << "Разность между первой и последней цифрой: " << difference << std::endl;
    
    return 0;
}