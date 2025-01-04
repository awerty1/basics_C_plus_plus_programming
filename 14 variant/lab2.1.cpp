/*
Задание 1. Вывести все нечётные числа начиная с числа M и до числа N. 
Числа M и N задает пользователь. Сделать проверку на корректность ввода M, 
N.
*/

#include <iostream>
#include <limits>

int main()
{
    int M, N;

    std::cout << "Введите число M: ";
    std::cin >> M;

    // Проверка корректности ввода числа M
    while (std::cin.fail())
    {
        std::cout << "Некорректный ввод. Введите число M: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> M;
    }

    std::cout << "Введите число N: ";
    std::cin >> N;

    // Проверка корректности ввода числа N
    while (std::cin.fail())
    {
        std::cout << "Некорректный ввод. Введите число N: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> N;
    }

    // Вывод нечётных чисел от M до N
    for (int i = M; i <= N; i++)
    {
        if (i % 2 != 0)
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}