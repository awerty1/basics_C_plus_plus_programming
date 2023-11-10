/*
Задание 3. Вводятся три произвольных числа x, y, z. Найти наименьшее
среди них.
*/

#include <iostream>
#include <limits>

int findMin(int x, int y, int z) 
{
    std::cout << "Введенные числа: " << x << ","<< y << "," << z << std::endl;
    int minNum = x;
    if (y < minNum) 
    {
        minNum = y;
    }
    if (z < minNum) 
    {
        minNum = z;
    }
    return minNum;
}

int inputNumber(const std::string& prompt) 
{
    int num;
    std::cout << prompt;
    while (!(std::cin >> num)) 
    {
        std::cout << "Ошибка ввода! Повторите попытку: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return num;
}

int main() 
{
    std::cout << "Программа вычисления минимального числа!" << std::endl;

    int x = inputNumber("Введите число x: ");
    int y = inputNumber("Введите число y: ");
    int z = inputNumber("Введите число z: ");

    int minNum = findMin(x, y, z);

    std::cout << "Наименьшее число: " << minNum << std::endl;

    return 0;
}