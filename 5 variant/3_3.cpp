/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Вставить число после всех
положительных элементов, если таковые имеются. Число для вставки вводится
с клавиатуры. Вывести измененный массив на экран. Дополнительные массивы
использовать нельзя – меняем исходный массив с помощью сдвига элементов.
Пример приведен в методичке. Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <vector>
#include <random>
#include <sstream>

int main() 
{
    int n;
    std::string input;

    do 
    {
        std::cout << "Введите значение n (не больше 20): ";
        std::getline(std::cin, input);
        std::istringstream stream(input);
        if (stream >> n && !(stream >> input) && n > 0 && n <= 20) 
        {
            break;
        }
        std::cerr << "Ошибка: некорректный ввод n. Повторите попытку." << std::endl;
    } 
    while (true);

    std::vector<int> arr(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);

    for (int i = 0; i < n; ++i) 
    {
        arr[i] = dis(gen);
    }

    std::cout << "Сформированный массив: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int numToInsert;

    do 
    {
        std::cout << "Введите число для вставки: ";
        std::getline(std::cin, input);
        std::istringstream stream(input);
        if (stream >> numToInsert && !(stream >> input)) 
        {
            break;
        }
        std::cerr << "Ошибка: некорректный ввод числа. Повторите попытку." << std::endl;
    } 
    while (true);

    int pos = 0;
    while (pos < arr.size()) 
    {
        if (arr[pos] > 0) 
        {
            arr.insert(arr.begin() + pos + 1, numToInsert);
            pos += 2;  // Двигаемся на две позиции, чтобы пропустить вставленный элемент и продолжить проверку
        } 
        else 
        {
            pos++;
        }
    }

    std::cout << "Измененный массив: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
